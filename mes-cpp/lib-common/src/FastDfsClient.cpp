/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 15:49:14
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
      https://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifdef USE_DFS

#include "pch.h"
#include "../include/FastDfsClient.h"
#include "../include/StringUtil.h"
#include "../include/CommonMacros.h"
#include <iostream>
#include <sstream>

#ifdef LINUX

#define DFS_GET_CONN(__VAR_RES_CODE__, __VAR_SERVER__, __VAL_RETURN__) \
int __VAR_RES_CODE__ = 0; \
ConnectionInfo* __VAR_SERVER__ = tracker_get_connection(); \
if (__VAR_SERVER__ == NULL) { \
	__VAR_RES_CODE__ = (errno != 0 ? errno : ECONNREFUSED); \
	logErrorEx(&g_log_context, "tracker_get_connection is failed, result:%d", __VAR_RES_CODE__); \
	return __VAL_RETURN__; \
}

#else

#include <atlstr.h>

//����5M���ļ���������
BYTE byFileBuff[5 * 1024 * 1024];

#endif

void FastDfsClient::init()
{
#ifdef LINUX
	// ��ʼ����־
	log_init();
	g_log_context.log_level = m_nLevelLog;
	// ��ʼ��fastfds�ͻ���
	int result = -1;
	if (m_configPath != "")
		result = fdfs_client_init(m_configPath.c_str());
	else
		result = fdfs_client_init_from_buffer(m_configContent.c_str());
	if (result != 0)
	{
		isInit = false;
		logErrorEx(&g_log_context, "Initialize Failed, Code Is %d", result);
	}
	else
	{
		isInit = true;
		logInfoEx(&g_log_context, "Initialize Succeed");
	}
#else
	m_hDll = LoadLibrary("dfs_client_win.dll");
	if (!m_hDll)
	{
		std::cout << "Load Dll Failed" << std::endl;
		isInit = false;
		return;
	}
	m_func_Initialize = (func_Initialize)GetProcAddress(m_hDll, "FDFSC_Initialize");
	m_func_UnInitialize = (func_UnInitialize)GetProcAddress(m_hDll, "FDFSC_UnInitialize");
	m_func_UploadFile = (func_UploadFile)GetProcAddress(m_hDll, "FDFSC_UploadFile");
	m_func_DownloadFile = (func_DownloadFile)GetProcAddress(m_hDll, "FDFSC_DownloadFile");
	m_func_DeleteFile = (func_DeleteFile)GetProcAddress(m_hDll, "FDFSC_DeleteFile");
	m_func_UploadFileByID = (func_UploadFileByID)GetProcAddress(m_hDll, "FDFSC_UploadFileByID");
	m_func_DownloadFileByID = (func_DownloadFileByID)GetProcAddress(m_hDll, "FDFSC_DownloadFileByID");
	m_func_DeleteFileByID = (func_DeleteFileByID)GetProcAddress(m_hDll, "FDFSC_DeleteFileByID");
	m_func_UploadSlaveFileByID = (func_UploadSlaveFileByID)GetProcAddress(m_hDll, "FDFSC_UploadSlaveFileByID");
	m_func_TrackerListGroups = (func_TrackerListGroups)GetProcAddress(m_hDll, "FDFSC_TrackerListGroups");
	m_func_TrackerListStorages = (func_TrackerListStorages)GetProcAddress(m_hDll, "FDFSC_TrackerListStorages");
	m_func_DeleteFileByIDEx = (func_DeleteFileByIDEx)GetProcAddress(m_hDll, "FDFSC_DeleteFileByIDEx");
	m_func_DownloadFileByIDEx = (func_DownloadFileByIDEx)GetProcAddress(m_hDll, "FDFSC_DownloadFileByIDEx");
	m_func_CheckConfiguration = (func_CheckConfiguration)GetProcAddress(m_hDll, "FDFSC_CheckConfiguration");

	TCHAR szProxyAddr[IP_ADDRESS_SIZE];
	_tcscpy_s(szProxyAddr, CA2T(this->serverAddr.c_str()));
	ServerAddress addr[2];
	addr[0].nPort = this->port;
	memcpy(addr[0].szIP, szProxyAddr, strlen(szProxyAddr) + 1);
	UINT32 nRet = m_func_Initialize(&addr[0], 1, 0);
	if (nRet != enumSuccess_FDFS)
	{
		std::cerr << "Initialize Failed" << std::endl;
		isInit = false;
	}
	else
	{
		std::cout << "Initialize Succeed" << std::endl;
		isInit = true;
	}
#endif
}

bool FastDfsClient::checkOrCreateDir(const std::string& fileName)
{
	//�ж�Ŀ¼�Ƿ���ڣ������ڴ���Ŀ¼
	auto dir = fileName.substr(0, fileName.find_last_of("/") + 1);
	const size_t dirLen = dir.length();
	if (dirLen > MAX_DIR_LEN)
	{
		std::cout << "file path is too long" << std::endl;
		return false;
	}
	
	//ѭ������Ŀ¼
	char tmpDirPath[MAX_DIR_LEN] = { 0 };
	for (size_t i = 0; i < dirLen; i++)
	{
		tmpDirPath[i] = dir[i];
		if (tmpDirPath[i] == '/')
		{
			if (ACCESS(tmpDirPath, 0) != 0)
			{
				if (MKDIR(tmpDirPath) != 0)
				{
					std::cout << "create dir fail:" << tmpDirPath << std::endl;
					return false;
				}
			}
		}
	}
	return true;
}

#ifdef LINUX

FastDfsClient::FastDfsClient(const std::string& fdsConfig, bool isPath /*= true*/, int logLevel /*= 3*/)
{
	//��ʼ����Ա����
	if(isPath) 
		m_configPath = fdsConfig;
	else
		m_configContent = fdsConfig;
	m_nLevelLog = logLevel;
	//���г�ʼ��
	this->init();
}

FastDfsClient::~FastDfsClient()
{
	fdfs_client_destroy();
	log_destroy();
}

#else

FastDfsClient::FastDfsClient(std::string serverAddr, unsigned int port /*= 22122*/)
{
	//��ʼ����Ա����
	this->serverAddr = serverAddr;
	this->port = port;
	this->isInit = false;
	//���г�ʼ��
	this->init();
}

#endif

std::string FastDfsClient::uploadFile(const std::string& fileName)
{
	// �����Ƿ��ʼ���ɹ�
	if (!this->isInit)
	{
		std::cerr << "Not initialize succeed" << std::endl;
		return "";
	}

	// ��ȡ�ļ���չ��
	std::string extName = fileName.substr(fileName.find_last_of(".") + 1);

#ifdef LINUX

	// ��ȡ����
	DFS_GET_CONN(result, pTrackerServer, "");
	
	// �����ϴ�����
	char group_name[FDFS_GROUP_NAME_MAX_LEN + 1];
	char remote_filename[256];
	int store_path_index;

	// ��ѯ�洢������
	ConnectionInfo storageServer;
	ConnectionInfo* pStorageServer;
	if ((result = tracker_query_storage_store(pTrackerServer, \
		&storageServer, group_name, &store_path_index)) != 0)
	{
		tracker_close_connection_ex(pTrackerServer, true);
		logErrorEx(&g_log_context, "tracker_query_storage fail, " \
			"error no: %d, error info: %s\n", \
			result, STRERROR(result));
		return "";
	}

	// ִ���ϴ�
	result = storage_upload_by_filename1(pTrackerServer, \
		&storageServer, store_path_index, \
		fileName.c_str(), NULL, \
		NULL, 0, group_name, remote_filename);
	
	// �ر�����
	tracker_close_connection_ex(pTrackerServer, true);
	
	// �жϽ��
	if (result == 0)
	{
		string fieldName = remote_filename;
		return fieldName;
	}
	else
	{
		logErrorEx(&g_log_context, "upload file fail, " \
			"error no: %d, error info: %s\n", \
			result, STRERROR(result));
		return "";
	}

#else
	//�ж��Ƿ��ܹ����ļ�
	fsRead.open(fileName.c_str(), std::ios::in | std::ios::binary);
	if (!fsRead)
	{
		std::cout << "Can not open file: " << fileName << std::endl;
		return "";
	}

	//��ȡ�ļ�
	fsRead.seekg(0, std::ios::end);
	size_t size = static_cast<size_t>(fsRead.tellg());
	fsRead.seekg(0, std::ios::beg);
	char* buff = new char[size];
	fsRead.read(buff, size);
	fsRead.close();

	//�����ϴ�����
	BYTE byGroupName[FDFS_GROUP_NAME_MAX_LEN + 1];
	BYTE byRemoteFileName[FDFS_REMOTE_FILE_NAME_MAX_LEN + 1];
	BYTE byFileExtName[10];
	memcpy(byFileExtName, extName.c_str(), extName.length() + 1);

	//��װ�ϴ��ļ�����
	BYTE* byFile = new BYTE[size];
	for (size_t i = 0; i < size; i ++)
	{
		byFile[i] = buff[i];
	}
	delete[] buff;

	//ִ���ļ��ϴ�
	std::string remoteFileld = "";
	UINT32 nRet = m_func_UploadFile(byFile, size, byFileExtName, byGroupName, byRemoteFileName);
	delete[] byFile;
	if (nRet != enumSuccess_FDFS)
	{
		std::cout << "File upload fail: " << fileName << ",error code " << nRet << std::endl;
	}
	else
	{
		std::stringstream ss;
		ss << byGroupName << "/" << byRemoteFileName;
		remoteFileld = ss.str();
	}
	return remoteFileld;
#endif
}

std::string FastDfsClient::uploadFile(const char* buff, size_t size, const std::string& extName /*= ""*/)
{
	// �����Ƿ��ʼ���ɹ�
	if (!this->isInit)
	{
		std::cerr << "Not initialize succeed" << std::endl;
		return "";
	}
#ifdef LINUX
	// ��ȡ����
	DFS_GET_CONN(result, pTrackerServer, "");

	// �����ϴ�����
	char group_name[FDFS_GROUP_NAME_MAX_LEN + 1];
	char remote_filename[256];
	int store_path_index;

	// ��ѯ�洢������
	ConnectionInfo storageServer;
	ConnectionInfo* pStorageServer;
	if ((result = tracker_query_storage_store(pTrackerServer, \
		& storageServer, group_name, &store_path_index)) != 0)
	{
		tracker_close_connection_ex(pTrackerServer, true);
		logErrorEx(&g_log_context, "tracker_query_storage fail, " \
			"error no: %d, error info: %s\n", \
			result, STRERROR(result));
		return "";
	}

	// ִ���ϴ�
	result = storage_upload_by_filebuff1(pTrackerServer, \
		& storageServer, store_path_index, \
		buff, size, extName.c_str(), \
		NULL, 0, group_name, remote_filename);

	// �ر�����
	tracker_close_connection_ex(pTrackerServer, true);

	// �жϽ��
	if (result == 0)
	{
		string fieldName = remote_filename;
		return fieldName;
	}
	else
	{
		logErrorEx(&g_log_context, "upload file fail, " \
			"error no: %d, error info: %s\n", \
			result, STRERROR(result));
		return "";
	}
#else
	//�����ϴ�����
	BYTE byGroupName[FDFS_GROUP_NAME_MAX_LEN + 1];
	BYTE byRemoteFileName[FDFS_REMOTE_FILE_NAME_MAX_LEN + 1];
	BYTE byFileExtName[10];
	memcpy(byFileExtName, extName.c_str(), extName.length() + 1);

	//��װ�ϴ��ļ�����
	BYTE* byFile = new BYTE[size];
	for (size_t i = 0; i < size; i++)
	{
		byFile[i] = buff[i];
	}

	//ִ���ļ��ϴ�
	std::string remoteFileld = "";
	UINT32 nRet = m_func_UploadFile(byFile, size, byFileExtName, byGroupName, byRemoteFileName);
	delete[] byFile;
	if (nRet != enumSuccess_FDFS)
	{
		std::cout << "File upload fail with byte buff, error code " << nRet << std::endl;
	}
	else
	{
		std::stringstream ss;
		ss << byGroupName << "/" << byRemoteFileName;
		remoteFileld = ss.str();
	}
	return remoteFileld;
#endif
}

std::string FastDfsClient::downloadFile(const std::string& fieldName, std::string* savePath)
{
	//�����Ƿ��ʼ���ɹ�
	if (!this->isInit)
	{
		std::cerr << "Not initialize succeed" << std::endl;
		return "";
	}

	//��������·��
	StringUtil::replace(savePath, "\\", "/");
	stringstream ss;
	ss << savePath->c_str() << "/" << fieldName;
	std::string fileName = ss.str();

	//�ж��ļ����봴��
	if (!checkOrCreateDir(fileName)) {
		return "";
	}

#ifdef LINUX

	// ��ȡ����
	DFS_GET_CONN(result, pTrackerServer, "");

	// ��ʼ����
	int64_t file_size = 0;
	int64_t file_offset = 0;
	int64_t download_bytes = 0;
	char* local_filename = &fileName[0];
	result = storage_do_download_file1_ex(pTrackerServer, \
		NULL, FDFS_DOWNLOAD_TO_FILE, fieldName.c_str(), \
		file_offset, download_bytes, \
		&local_filename, NULL, &file_size);

	// �ر�����
	tracker_close_connection_ex(pTrackerServer, true);

	// �жϽ��
	if (result != 0)
	{
		logErrorEx(&g_log_context, "download file fail, " \
			"error no: %d, error info: %s\n", \
			result, STRERROR(result));
		return "";
	}

	// �����ļ���
	return fileName;
#else

	//���巽�����ò���
	TCHAR szFileID[260] = { 0 };
	UINT32 nFileSize = 0;
	_tcscpy_s(szFileID, CA2T(fieldName.c_str()));

	//�����ļ�
	UINT32 nRet = m_func_DownloadFileByID(reinterpret_cast<BYTE*>(szFileID), byFileBuff, &nFileSize);
	if (nRet != enumSuccess_FDFS)
	{
		std::cout << "File download fail: " << fieldName << ",error code " << nRet << std::endl;
		return "";
	}

	//�����ļ�
	fsWrite.open(fileName, std::ios::out | std::ios::binary);
	char* buff = new char[nFileSize];
	for (size_t i = 0; i < nFileSize; i++)
	{
		buff[i] = byFileBuff[i];
	}
	fsWrite.write(buff, nFileSize);
	fsWrite.close();
	delete[] buff;

	//�����ļ���
	return fileName;
#endif
}

bool FastDfsClient::deleteFile(const std::string& fieldName)
{
	//�����Ƿ��ʼ���ɹ�
	if (!this->isInit)
	{
		std::cerr << "Not initialize succeed" << std::endl;
		return false;
	}

#ifdef LINUX

	// ��ȡ����
	DFS_GET_CONN(result, pTrackerServer, false);

	// ɾ���ļ�
	result = storage_delete_file1(pTrackerServer, NULL, fieldName.c_str());

	// �ر�����
	tracker_close_connection_ex(pTrackerServer, true);
	
	// �жϽ��
	if (result != 0)
	{
		logErrorEx(&g_log_context, "delete file fail, " \
			"error no: %d, error info: %s\n", \
			result, STRERROR(result));
		return false;
	}

	// ����ɾ���ɹ�
	return true;
#else

	//���巽�����ò���
	TCHAR szFileID[260] = { 0 };
	_tcscpy_s(szFileID, CA2T(fieldName.c_str()));

	//ɾ���ļ�
	UINT32 nRet = m_func_DeleteFileByID(reinterpret_cast<BYTE*>(szFileID));
	if (nRet != enumSuccess_FDFS)
	{
		std::cerr << "File delete fail: " << fieldName << ",error code " << nRet << std::endl;
		return false;
	}

	return true;
#endif
}

#endif // USE_DFS