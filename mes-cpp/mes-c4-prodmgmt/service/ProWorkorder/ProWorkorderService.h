#pragma once

#ifndef _PROWORKORDER_SERVICE_
#define _PROWORKORDER_SERVICE_
#include <list>
#include "../../domain/vo/ProdWorkorder/ConfirmProWorkorderVO.h"
#include "../../domain/dto/ProdWorkorder/ConfirmProWorkorderDTO.h"
#include "../../domain/dto/ProdWorkorder/ModifyProWorkorderDTO.h"
#include "../../domain/do/pro_workorder_bom/ProWorkOrderBomDO.h"
#include "../../domain/do/MdProductBom/MdProductBomDO.h"
#include "../../domain/do/pro_workorder_bom/ProWorkOrderBomDO.h"
#include "../../domain/do/ProdWorkorder/ProdWorkorderDO.h"

#include "TransactionManager.h"


/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class ProWorkorderService
{
public:
	// �޸�����
	bool updateData(const ModifyProWorkorderDTO::Wrapper& dto);
	// ͨ��ID�����������
	bool completeData(uint64_t id);
	// ͨ��IDɾ����������
	bool removeData(uint64_t id);

	// ͨ��IDȷ����������
	bool confirmData(uint64_t id);
};

#endif // !_PROWORKORDER_SERVICE_

