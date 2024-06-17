#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 15:40:11
 
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
#ifndef _FASTDFSDEFINE_H_
#define _FASTDFSDEFINE_H_
#include <string>
#include <fstream>

#ifdef LINUX

#include "fastdfs/fdfs_client.h"
#include "fastdfs/fdfs_global.h"
#include "fastdfs/fastcommon/base64.h"
#include "fastdfs/fastcommon/sockopt.h"
#include "fastdfs/fastcommon/logger.h"

#else

#include "fastdfs/fastdfs_client_win.h"

typedef UINT32(__stdcall* func_Initialize)(ServerAddress* pAddr, UINT32 nAddrCount, UINT32 nLogLevel);
typedef UINT32(__stdcall* func_UploadFile)(const BYTE* pbyFileBuff, UINT32 nFileSize, const BYTE* pbyFileExtName, BYTE* pbyGroupName, BYTE* pbyRemoteFileName);
typedef UINT32(__stdcall* func_DownloadFile)(const BYTE* pbyGroupName, const BYTE* pbyRemoteFileName, BYTE* pbyFileBuff, UINT32* nFileSize);
typedef UINT32(__stdcall* func_DeleteFile)(const BYTE* pbyGroupName, const BYTE* pbyRemoteFileName);
typedef UINT32(__stdcall* func_UploadFileByID)(const BYTE* pbyFileBuff, UINT32 nFileSize, const BYTE* pbyFileExtName, BYTE* pbyFileID);
typedef UINT32(__stdcall* func_DownloadFileByID)(const BYTE* pbyFileID, BYTE* pbyFileBuff, UINT32* nFileSize);
typedef UINT32(__stdcall* func_DeleteFileByID)(const BYTE* pbyFileID);
typedef UINT32(__stdcall* func_UploadSlaveFileByID)(const BYTE* pbyFileBuff, UINT32 nFileSize, const BYTE* pbyMasterGroupName, const BYTE* pbyMasterFileName, const BYTE* pbyPrefixName, const BYTE* pbyFileExtName, BYTE* pbyFileID);
typedef void(__stdcall* func_UnInitialize)();
typedef UINT32(__stdcall* func_TrackerListGroups)(ServerAddress* pTrackerAddr, FDFSGroupStat* pStat, UINT32 nLen, UINT32* pnStatCount);
typedef UINT32(__stdcall* func_TrackerListStorages)(ServerAddress* pTrackerAddr, TCHAR* pszGroupName, FDFSStorageStat* pStat, UINT32 nLen, UINT32* pnStatCount);
typedef UINT32(__stdcall* func_DeleteFileByIDEx)(const TCHAR* pszTrackerIPList, const TCHAR* pszFileID);
typedef UINT32(__stdcall* func_DownloadFileByIDEx)(const TCHAR* pszTrackerIPList, const TCHAR* pszFileID, BYTE* pbyFileBuff, UINT32* nFileSize);
typedef UINT32(__stdcall* func_CheckConfiguration)(const TCHAR* pszTrackerIPList);

#endif

/**
 * FastDFS�ļ��ϴ����ؿͻ���
 */
class FastDfsClient
{
private:
	//�Ƿ��ʼ���ɹ�
	bool isInit;
	//�ļ�����Ա����
	std::ifstream fsRead;
	std::ofstream fsWrite;

#ifdef LINUX

	//�����ļ�·��
	std::string m_configPath;
	//�����ļ�����
	std::string m_configContent;
	//��־�ȼ�
	int	m_nLevelLog;

#else

	//��������ַ
	std::string serverAddr;
	//�������˿�
	unsigned int port;
	
#pragma region Define dynamic library function 
	HMODULE m_hDll;
	func_Initialize m_func_Initialize;
	func_UnInitialize m_func_UnInitialize;
	func_UploadFile m_func_UploadFile;
	func_DownloadFile m_func_DownloadFile;
	func_DeleteFile m_func_DeleteFile;
	func_UploadFileByID m_func_UploadFileByID;
	func_DownloadFileByID m_func_DownloadFileByID;
	func_DeleteFileByID m_func_DeleteFileByID;
	func_UploadSlaveFileByID m_func_UploadSlaveFileByID;
	func_TrackerListGroups m_func_TrackerListGroups;
	func_TrackerListStorages m_func_TrackerListStorages;
	func_DeleteFileByIDEx m_func_DeleteFileByIDEx;
	func_DownloadFileByIDEx m_func_DownloadFileByIDEx;
	func_CheckConfiguration m_func_CheckConfiguration;
#pragma endregion

#endif
	//��ʼ��
	void init();
	//�жϻ򴴽��ļ���
	bool checkOrCreateDir(const std::string& fileName);
public:
#ifdef LINUX
	//************************************
	// Method:    FastDfsClient
	// FullName:  FastDfsClient::FastDfsClient
	// Access:    public 
	// Returns:   
	// Description: �����ʼ��
	// Parameter: const std::string& fdsConfig ������Ϣ
	// �����������ļ�·������:/etc/fdfs/client.conf����Ҳ������ͨ����ȡ�����ļ���ȡ������������Ϣ
	// Parameter: bool isPath ���fdsConfig�Ƿ�Ϊ�����ļ�·����Ĭ��ֵΪtrue����ʾ�������ļ���
	// Parameter: int logLevel ��־���𣬲��õ���unix��־�ȼ���Ĭ��3
	//  0: LOG_EMERG
	//	1: LOG_ALERT
	//	2: LOG_CRIT
	//	3: LOG_ERR
	//	4: LOG_WARNING
	//	5: LOG_NOTICE
	//	6: LOG_INFO
	//	7: LOG_DEBUG
	//************************************
	FastDfsClient(const std::string& fdsConfig, bool isPath = true, int logLevel = 3);
	// �����ͷ���Դ
	~FastDfsClient();
#else
	//************************************
	// Method:    FastDfsClient
	// FullName:  FastDfsClient::FastDfsClient
	// Access:    public 
	// Returns:   
	// Description: �����ʼ��
	// Parameter: std::string serverAddr fastdfs��������ַ
	// Parameter: unsigned int port �������˿ڣ�Ĭ��22122
	//************************************
	explicit FastDfsClient(std::string serverAddr, unsigned int port = 22122);
#endif

	//************************************
	// Method:    uploadFile
	// FullName:  FastDfsClient::uploadFile
	// Access:    public 
	// Returns:   std::string �ϴ��ɹ�����fastdfs�洢���ļ���������������+�ļ������ϴ�ʧ�ܷ��ؿ��ַ���
	// Description: �ϴ��ļ�
	// Parameter: const std::string & fileName ����·�����ϴ��ļ���
	//************************************
	std::string uploadFile(const std::string& fileName);

	//************************************
	// Method:    uploadFile
	// FullName:  FastDfsClient::uploadFile
	// Access:    public 
	// Returns:   std::string �ϴ��ɹ�����fastdfs�洢���ļ���������������+�ļ������ϴ�ʧ�ܷ��ؿ��ַ���
	// Description: �ϴ��ļ�
	// Parameter: const char * buff �ļ��������ֽ�����
	// Parameter: size_t size �ļ���С
	// Parameter: const std::string& extName �ļ���׺��
	//************************************
	std::string uploadFile(const char* buff, size_t size, const std::string& extName = "");
	
	//************************************
	// Method:    downloadFile
	// FullName:  FastDfsClient::downloadFile
	// Access:    public 
	// Returns:   std::string ���ذ���·�����ļ���
	// Description: �����ļ�
	// Parameter: const std::string & fieldName fastdfs��Ӧ���ļ���������������+�ļ���
	// Parameter: std::string * savePath �����ļ���Ŀ¼��Ҫ���ַ�����β����//��\
	//************************************
	std::string downloadFile(const std::string& fieldName, std::string* savePath);

	//************************************
	// Method:    deleteFile
	// FullName:  FastDfsClient::deleteFile
	// Access:    public 
	// Returns:   bool ɾ���ɹ�����true
	// Description: ɾ���ļ�
	// Parameter: const std::string & fieldName fastdfs��Ӧ���ļ���������������+�ļ���
	//************************************
	bool deleteFile(const std::string& fieldName);
};

#endif // _FASTDFSDEFINE_H_
