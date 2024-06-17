#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 15:27:52
 
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
#ifndef LINUX
#include <wtypes.h>

#ifndef FASTDFS_CLIENT_WIN_H_
#define FASTDFS_CLIENT_WIN_H_

#define IP_ADDRESS_SIZE				16
#define FDFS_GROUP_NAME_MAX_LEN		16
#define FDFS_FILE_PREFIX_MAX_LEN	16
#define FDFS_GROUP_NAME_MAX_LEN		16
#define FDFS_STORAGE_ID_MAX_SIZE	16
#define FDFS_REMOTE_FILE_NAME_MAX_LEN		128
#define FDFS_FILE_EXT_NAME_MAX_LEN	6
#define FDFS_MAX_SERVERS_EACH_GROUP	32
#define FDFS_MAX_GROUPS				512
#define FDFS_PROTO_PKG_LEN_SIZE		8
#define FDFS_VERSION_SIZE			6
#define FDFS_DOMAIN_NAME_MAX_SIZE	128


typedef enum enumTemplateResult_FDFS
{
	enumSuccess_FDFS = 0,				//�ɹ�
	enumFailure_FDFS = 1,				//ʧ��
	enumNotInit_FDFS = 2,				//δ��ʼ��
	enumInvalidParameters_FDFS = 3,		//��������
	enumNetworkError_FDFS = 4,			//�������
	enumFileNotExists_FDFS = 5,			//�ļ�������
	enumNoEnoughSpace_FDFS = 6			//���̿ռ䲻��
} Result_FDFS;

typedef struct __ServerAddress__
{
	TCHAR szIP[16];
	UINT32 nPort;
} ServerAddress;

typedef struct
{
	TCHAR	szGroupName[FDFS_GROUP_NAME_MAX_LEN + 8];	//for 8 bytes alignment
	UINT64	nTotalMB;									//total disk storage in MB
	UINT64	nFreeMB;  //free disk storage in MB
	UINT64	nTrunkFreeMB;  //trunk free disk storage in MB
	UINT32	nCount;        //server count
	UINT32	nStoragePort; //storage server port
	UINT32	nStorageHttpPort; //storage server http port
	UINT32	nActiveCount; //active server count
	UINT32	nCurrentWriteServer; //current server index to upload file
	UINT32	nStorePathCount;  //store base path count of each storage server
	UINT32	nSubdirCountPerPath;
	UINT32	nCurrentTrunkFileID;  //current trunk file id
} FDFSGroupStat;

//FDFS Storage״̬���ݽṹ
typedef struct
{
	UINT64 nTotalUploadCount;
	UINT64 nSuccessUploadCount;
	UINT64 nTotalAppendCount;
	UINT64 nSuccessAppendCount;
	UINT64 nTotalModifyCount;
	UINT64 nSuccessModifyCount;
	UINT64 nTotalTruncateCount;
	UINT64 nSuccessTruncateCount;
	UINT64 nTotalSetMetaCount;
	UINT64 nSuccessSetMetaCount;
	UINT64 nTotalDeleteCount;
	UINT64 nSuccessDeleteCount;
	UINT64 nTotalDownloadCount;
	UINT64 nSuccessDownloadCount;
	UINT64 nTotalGetMetaCount;
	UINT64 nSuccessGetMetaCount;
	UINT64 nTotalCreateLinkCount;
	UINT64 nSuccessCreateLinkCount;
	UINT64 nTotalDeleteLinkCount;
	UINT64 nSuccessDeleteLinkCount;
	UINT64 nTotalUploadBytes;
	UINT64 nSuccessUploadBytes;
	UINT64 nTotalAppendBytes;
	UINT64 nSuccessAppendBytes;
	UINT64 nTotalModifyBytes;
	UINT64 nSuccessModifyBytes;
	UINT64 nTotalDownloadBytes;
	UINT64 nSuccessDownloadBytes;
	UINT64 nTotalSyncInBytes;
	UINT64 nSuccessSyncInBytes;
	UINT64 nTotalSyncOutBytes;
	UINT64 nSuccessSyncOutBytes;
	UINT64 nTotalFileOpenCount;
	UINT64 nSuccessFileOpenCount;
	UINT64 nTotalFileReadCount;
	UINT64 nSuccessFileReadCount;
	UINT64 nTotalFileWriteCount;
	UINT64 nSuccessFileWriteCount;

	/* last update timestamp as source server,
		   current server' timestamp
	*/
	time_t lastSourceUpdate;

	/* last update timestamp as dest server,
		   current server' timestamp
	*/
	time_t lastSyncUpdate;

	/* last syned timestamp,
	   source server's timestamp
	*/
	time_t lastSyncedTimestamp;

	/* last heart beat time */
	time_t lastHeartBeatTime;

	struct {
		UINT32 nAllocCount;
		volatile UINT32 nCurrentCount;
		UINT32 nMaxCount;
	} connection;
} FDFSStorageInfo;

typedef struct
{
	BOOL bIfTrunkServer;
	BYTE byStatus;
	TCHAR szID[FDFS_STORAGE_ID_MAX_SIZE];
	TCHAR szIpAddr[IP_ADDRESS_SIZE];
	TCHAR szSrcId[FDFS_STORAGE_ID_MAX_SIZE];
	TCHAR szDomainName[FDFS_DOMAIN_NAME_MAX_SIZE];
	TCHAR szVersion[FDFS_VERSION_SIZE];
	UINT32 nTotalMb;
	UINT32 nFreeMb;
	UINT32 nUploadPriority;
	time_t joinTime;
	time_t upTime;
	UINT32 nStorePathCount;
	UINT32 nSubdirCountPerPath;
	UINT32 nStoragePort;
	UINT32 nStorageHttpPort;
	UINT32 nCurrentWritePath;
	FDFSStorageInfo stat;
} FDFSStorageStat;

#ifdef __cplusplus
extern "C" {
#endif

	/**
	 * ��ʼ��FastDFS �ͻ���
	 *
	 * ������
	 * pAddr		[in]	tracker��������ַ����
	 * nAddrCount	[in]	tracker��������ַ����ĳ��ȣ���tracker��������ͬ
	 *
	 * ����ֵ��
	 * enumSuccess_FDFS����ʼ���ɹ�
	 * enumInvalidParameters_FDFS����Ч�Ĳ���
	 * enumFailure_FDFS����ʼ��ʧ��
	 */
	UINT32 __stdcall FDFSC_Initialize(ServerAddress* pAddr,
		UINT32 nAddrCount,
		UINT32 nLogLevel);

	/**
	 * ����ʼ��FastDFS �ͻ���
	 *
	 * ��������
	 *
	 * ����ֵ����
	 */
	void __stdcall FDFSC_UnInitialize();

	/**
	 * �ϴ��ļ�
	 *
	 * ������
	 * pbyFileBuff			[in]	Ҫ�ϴ����ļ����ڴ�����
	 * nFileSize			[in]	Ҫ�ϴ����ļ��Ĵ�С
	 * pszFileExtName		[in]	Ҫ�ϴ����ļ�����չ��
	 * pszGroupName			[out]   �ϴ����ļ������������
	 * pszRemoteFileName	[out]	�ϴ����ļ��ļ���
	 *
	 * ����ֵ��
	 * enumSuccess_FDFS���ϴ��ɹ�
	 * enumInvalidParameters_FDFS����Ч�Ĳ���
	 * enumFailure_FDFS���ϴ�ʧ��
	 */
	UINT32 __stdcall FDFSC_UploadFile(const BYTE* pbyFileBuff, UINT32 nFileSize, const TCHAR* pszFileExtName,
		TCHAR* pszGroupName, TCHAR* pszRemoteFileName);

	/**
	 * �ϴ��ļ�
	 *
	 * ������
	 * pbyFileBuff			[in]	Ҫ�ϴ����ļ����ڴ�����
	 * nFileSize			[in]	Ҫ�ϴ����ļ��Ĵ�С
	 * pszFileExtName		[in]	Ҫ�ϴ����ļ�����չ��
	 * pszFileID			[out]	�ϴ����ļ�ID
	 *
	 * ����ֵ��
	 * enumSuccess_FDFS���ϴ��ɹ�
	 * enumInvalidParameters_FDFS����Ч�Ĳ���
	 * enumFailure_FDFS���ϴ�ʧ��
	 */
	UINT32 __stdcall FDFSC_UploadFileByID(const BYTE* pbyFileBuff, UINT32 nFileSize, const TCHAR* pszFileExtName,
		TCHAR* pszFileID);

	/**
	 * �ϴ����ļ�
	 *
	 * ������
	 * pbyFileBuff			[in]	Ҫ�ϴ��Ĵ��ļ����ڴ�����
	 * nFileSize			[in]	Ҫ�ϴ��Ĵ��ļ��Ĵ�С
	 * pszMasterGroupName	[in]	���ļ������������
	 * pszMasterFileName	[in]	���ļ����ļ���
	 * pszPrefixName		[in]	���ļ���Prefix
	 * pszFileExtName		[in]	Ҫ�ϴ��Ĵ��ļ�����չ��
	 * pszGroupName			[out]   �ϴ��Ĵ��ļ������������
	 * pszRemoteFileName	[out]	�ϴ��Ĵ��ļ��ļ���
	 *
	 * ����ֵ��
	 * enumSuccess_FDFS���ϴ��ɹ�
	 * enumInvalidParameters_FDFS����Ч�Ĳ���
	 * enumFailure_FDFS���ϴ�ʧ��
	 */
	UINT32 __stdcall FDFSC_UploadSlaveFile(const BYTE* pbyFileBuff, UINT32 nFileSize,
		const TCHAR* pszMasterGroupName, const TCHAR* pszMasterFileName,
		const TCHAR* pszPrefixName, const TCHAR* pszFileExtName,
		TCHAR* pszGroupName, TCHAR* pszRemoteFileName);

	/**
	 * �ϴ����ļ�
	 *
	 * ������
	 * pbyFileBuff			[in]	Ҫ�ϴ��Ĵ��ļ����ڴ�����
	 * nFileSize			[in]	Ҫ�ϴ��Ĵ��ļ��Ĵ�С
	 * pszMasterGroupName	[in]	���ļ������������
	 * pszMasterFileName	[in]	���ļ����ļ���
	 * pszPrefixName		[in]	���ļ���Prefix
	 * pszFileExtName		[in]	Ҫ�ϴ��Ĵ��ļ�����չ��
	 * pszFileID			[out]	�ϴ��Ĵ��ļ�ID
	 *
	 * ����ֵ��
	 * enumSuccess_FDFS���ϴ��ɹ�
	 * enumInvalidParameters_FDFS����Ч�Ĳ���
	 * enumFailure_FDFS���ϴ�ʧ��
	 */
	UINT32 __stdcall FDFSC_UploadSlaveFileByID(const BYTE* pbyFileBuff, UINT32 nFileSize,
		const TCHAR* pszMasterGroupName, const TCHAR* pszMasterFileName,
		const TCHAR* pszPrefixName, const TCHAR* pszFileExtName,
		TCHAR* pszFileID);

	/**
	 * �����ļ�
	 *
	 * ������
	 * pszGroupName			[in]	Ҫ���ص��ļ������������
	 * pszRemoteFileName	[in]	Ҫ���ص��ļ����ļ���
	 * pbyFileBuff			[out]	���ص��ļ���ַ
	 * nFileSize			[out]	���ص��ļ���С
	 *
	 * ����ֵ��
	 * enumSuccess_FDFS�����سɹ�
	 * enumInvalidParameters_FDFS����Ч�Ĳ���
	 * enumFailure_FDFS������ʧ��
	 */
	UINT32 __stdcall FDFSC_DownloadFile(const TCHAR* pszGroupName, const TCHAR* pszRemoteFileName,
		BYTE* pbyFileBuff, UINT32* nFileSize);

	/**
	 * �����ļ�
	 *
	 * ������
	 * pszFileID			[in]	Ҫ���ص��ļ���ID
	 * pbyFileBuff			[out]	���ص��ļ���ַ
	 * nFileSize			[out]	���ص��ļ���С
	 *
	 * ����ֵ��
	 * enumSuccess_FDFS�����سɹ�
	 * enumInvalidParameters_FDFS����Ч�Ĳ���
	 * enumFailure_FDFS������ʧ��
	 */
	UINT32 __stdcall FDFSC_DownloadFileByID(const TCHAR* pszFileID,
		BYTE* pbyFileBuff, UINT32* nFileSize);

	/**
	 * �����ļ�
	 *
	 * ������
	 * pszTrackerIPList		[in]	Tracker��IP�б�
	 * pszFileID			[in]	Ҫ���ص��ļ���ID
	 * pbyFileBuff			[out]	���ص��ļ���ַ
	 * nFileSize			[out]	���ص��ļ���С
	 *
	 * ����ֵ��
	 * enumSuccess_FDFS�����سɹ�
	 * enumInvalidParameters_FDFS����Ч�Ĳ���
	 * enumFailure_FDFS������ʧ��
	 *
	 * ��ע
	 * δ��ʼ���Ϳ��Ե���
	 */
	UINT32 __stdcall FDFSC_DownloadFileByIDEx(const TCHAR* pszTrackerIPList, const TCHAR* pszFileID,
		BYTE* pbyFileBuff, UINT32* nFileSize);

	/**
	 * ɾ���ļ�
	 *
	 * ������
	 * pszGroupName			[in]	Ҫɾ�����ļ������������
	 * pszRemoteFileName	[in]	Ҫɾ�����ļ����ļ���
	 *
	 * ����ֵ��
	 * enumSuccess_FDFS��ɾ���ɹ�
	 * enumInvalidParameters_FDFS����Ч�Ĳ���
	 * enumFailure_FDFS��ɾ��ʧ��
	 */
	UINT32 __stdcall FDFSC_DeleteFile(const TCHAR* pszGroupName, const TCHAR* pszRemoteFileName);

	/**
	 * ɾ���ļ�
	 *
	 * ������
	 * pszFileID			[in]	Ҫɾ�����ļ�ID
	 *
	 * ����ֵ��
	 * enumSuccess_FDFS��ɾ���ɹ�
	 * enumInvalidParameters_FDFS����Ч�Ĳ���
	 * enumFailure_FDFS��ɾ��ʧ��
	 */
	UINT32 __stdcall FDFSC_DeleteFileByID(const TCHAR* pszFileID);

	/**
	 * ɾ���ļ�
	 *
	 * ������
	 * pszTrackerIPList		[in]	�ƶ�Tracker��IP��ַ�б�
	 * pszFileID			[in]	Ҫɾ�����ļ�ID
	 *
	 * ����ֵ��
	 * enumSuccess_FDFS��ɾ���ɹ�
	 * enumInvalidParameters_FDFS����Ч�Ĳ���
	 * enumFailure_FDFS��ɾ��ʧ��
	 *
	 * ��ע
	 * δ��ʼ���Ϳ��Ե���
	 */
	UINT32 __stdcall FDFSC_DeleteFileByIDEx(const TCHAR* pszTrackerIPList, const TCHAR* pszFileID);

	/**
	 * ��ѯGroup��Ϣ
	 *
	 * ������
	 * pTrackerAddr			[in]	��ѯ��Tracker��������ַ
	 * pStat				[in,out]	FDFSGroupStat�ṹ���������ڷ��ز�ѯ���
	 * nLen					[in]	���鳤��,ȡFDFS_MAX_GROUPS����
	 * pnStatCount			[out]	���ڷ��ز�ѯ�����FDFSGroupStat����
	 *
	 * ����ֵ��
	 * enumSuccess_FDFS����ѯ�ɹ�
	 * enumInvalidParameters_FDFS����Ч�Ĳ���
	 * enumFailure_FDFS����ѯʧ��
	 * enumNetworkError_FDFS���������
	 * enumNotInit_FDFS��δ��ʼ���ɹ�
	 */
	UINT32 __stdcall FDFSC_TrackerListGroups(ServerAddress* pTrackerAddr, FDFSGroupStat* pStat, UINT32 nLen, UINT32* pnStatCount);

	/**
	 * ��ѯGroup��Storage��������Ϣ
	 *
	 * ������
	 * pTrackerAddr			[in]	��ѯ��Tracker��������ַ
	 * pszGroupName			[in]	��ѯ������
	 * pStat				[in,out]	FDFSGroupStat�ṹ���������ڷ��ز�ѯ���
	 * nLen					[in]	���鳤��ΪFDFS_MAX_GROUPS
	 * pnStatCount			[out]	���ڷ��ز�ѯ�����FDFSGroupStat����
	 *
	 * ����ֵ��
	 * enumSuccess_FDFS����ѯ�ɹ�
	 * enumInvalidParameters_FDFS����Ч�Ĳ���
	 * enumFailure_FDFS����ѯʧ��
	 * enumNetworkError_FDFS���������
	 * enumNotInit_FDFS��δ��ʼ���ɹ�
	 */
	UINT32 __stdcall FDFSC_TrackerListStorages(ServerAddress* pTrackerAddr, TCHAR* pszGroupName, FDFSStorageStat* pStat, UINT32 nLen, UINT32* pnStatCount);

	/**
	 * ���ͬ���Tracker��ȡ����Storage�Ƿ���ͬ
	 *
	 * ������
	 * pszTrackerIPList		[in]	�ƶ�Tracker��IP��ַ�б�
	 *
	 * ����ֵ��
	 * enumSuccess_FDFS��������ͬ
	 * enumInvalidParameters_FDFS����Ч�Ĳ���
	 * enumFailure_FDFS�����ʧ��
	 *
	 * ��ע
	 * δ��ʼ���Ϳ��Ե���
	 */
	UINT32 __stdcall FDFSC_CheckConfiguration(const TCHAR* pszTrackerIPList);

#ifdef __cplusplus
}
#endif

#endif
#endif