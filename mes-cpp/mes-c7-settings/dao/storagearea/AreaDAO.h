#pragma once
#ifndef __AREADAO_H__
#define __AREADAO_H__

#include "BaseDAO.h"
#include "../../domain/do/storagearea/AreaDO.h"
#include "../../domain/query/storagearea/AreaQuery.h"

class AreaDAO : public BaseDAO
{
public:
	// ͳ����������
	std::uint64_t count(const AreaQuery::Wrapper& query);	
	// ͨ��������ѯ����
	std::list<AreaDO> selectByName(const std::string& name);
	// ��ҳ��ѯ����
	std::list<AreaDO> selectWithPage(const AreaQuery::Wrapper& query);
	// ��������
	std::uint64_t insert(const AreaDO& iObj);
	// �޸�����
	std::uint64_t update(const AreaDO& uObj);
	// ͨ���û�ָ��IDɾ������
	std::uint64_t deleteById(std::list<int64_t>& ids);
	
	
};

#endif //__AREADAO_H__
