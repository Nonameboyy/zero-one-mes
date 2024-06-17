#pragma once
#ifndef __AREASERVICE_H__
#define __AREASERVICE_H__

#include "domain/dto/storagearea/AreaDTO.h"
#include "domain/query/storagearea/AreaQuery.h"


class AreaService 
{
public:
	// ��ҳ��ѯ��������
	AreaPageDTO::Wrapper listAllAreabyPage(const AreaQuery::Wrapper& query);
	// ���һ���λ
	uint64_t insertArea(const AreaDTO::Wrapper& dto, const PayloadDTO& payload);
	// �޸�һ���λ
	bool updateArea(const AreaDTO::Wrapper& dto, const PayloadDTO& payload);
	// ɾ��һ�������λ
	bool removeArea( std::list<int64_t>& ids);
};

#endif //__AREASERVICE_H__
