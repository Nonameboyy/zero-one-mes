#pragma once
#ifndef _storage_SERVICE_
#define _storage_SERVICE_
#include <list>
#include "domain/dto/storage/storageDTO.h"
#include "domain/query/storage/storageQuery.h"
#include "domain/do/storage/storageDO.h"
#include "ExcelComponent.h"

/**
 * ��Ʒ�����Ϣ�ķ���ӿ�
 */
class storageService
{
public:

	// �������
	uint64_t update(const storageDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
	// ��ҳ��ѯ��������
	storagePageDTO::Wrapper listAll(const storageQuery::Wrapper& query);

};

#endif // !_storage_SERVICE_
