#pragma once

#ifndef _MDPRODUCTBOM_DAO_
#define _MDPRODUCTBOM_DAO_
#include "BaseDAO.h"
#include "../../domain/do/MdProductBom/MdProductBomDO.h"

/**
 * �������������ݿ����ʵ��
 */
class MdProductBomDAO : public BaseDAO
{
public:
	int countById(uint64_t itemId);
	
	list<MdProductBomDO> selectByItemId(uint64_t itemId);
	
	int deleteById(uint64_t itemId);
};
#endif // !_MDPRODUCTBOM_DAO_
