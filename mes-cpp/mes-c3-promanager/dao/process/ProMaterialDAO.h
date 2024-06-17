#pragma once
#ifndef _PROMATERIAL_DAO_
#define _PROMATERIAL_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pro/ProRouteProductBomDO.h"
#include "../../domain/query/process/ProMaterialQuery.h"


/**
 * ��Ʒ�Ƴ����ϱ����ݿ����ʵ��
 */
class ProMaterialDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ProMaterialQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<ProRouteProductBomDO> selectWithPage(const ProMaterialQuery::Wrapper& query);
	// ͨ����Ʒ���ϱ����ѯ����
	list<ProRouteProductBomDO> selectByItemCode(const string& item_code);
	// ͨ����Ʒ�������Ʋ�ѯ����
	list<ProRouteProductBomDO> selectByItem_Name(const string& item_name);
	
};
#endif // !_PROMATERIAL_DAO_
