#pragma once
#ifndef _RELATEPRO_DAO_
#define  _RELATEPRO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pro/ProRouteProductDO.h"
#include "../../../lib-oatpp/include/domain/dto/PayloadDTO.h"

/**
 * ������Ʒ���ݿ����ʵ��
 */
class RelateProDAO : public BaseDAO
{
public:
	// ���������Ʒ
	uint64_t insert(const ProRouteProductDO& iObj, const PayloadDTO& payload);
	// �޸Ĺ�����Ʒ
	int update(const ProRouteProductDO& uObj, const PayloadDTO& payload);
	// ɾ��������Ʒ
	int deleteById(uint64_t id);
	// ����������Ʒ
	list<ProRouteProductDO> selectById(uint64_t id);
};
#endif // ! _RELATEPRO_DAO_
