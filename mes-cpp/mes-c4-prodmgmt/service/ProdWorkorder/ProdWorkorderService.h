#pragma once
#ifndef _PRODWORKORDER_SERVICE_
#define _PRODWORKORDER_SERVICE_
#include <list>
#include "../mes-c4-prodmgmt/domain/vo/ProdWorkorder/ProdWorkorderInfoVO.h"
#include "../mes-c4-prodmgmt/domain/vo/ProdWorkorder/ProdWorkorderBomListVO.h"
#include "../mes-c4-prodmgmt/domain/vo/ProdWorkorder/GetProdWorkorderListVO.h"
#include "../mes-c4-prodmgmt/domain/vo/ProdWorkorder/AddProdWorkorderVO.h"

#include "../mes-c4-prodmgmt/domain/query/ProdWorkorder/GetProdWorkorderListQuery.h"
#include "../mes-c4-prodmgmt/domain/query/ProdWorkorder/ProdWorkorderBomListQuery.h"

#include "../mes-c4-prodmgmt/domain/dto/ProdWorkorder/AddProdWorkorderDTO.h"
#include "../mes-c4-prodmgmt/domain/dto/ProdWorkorder/ProdWorkorderInfoDTO.h"
#include "../mes-c4-prodmgmt/domain/dto/ProdWorkorder/ProdWorkorderBomListDTO.h"
#include "../mes-c4-prodmgmt/domain/dto/ProdWorkorder/GetProdWorkorderListDTO.h"

class ProdWorkorderService {
public:
	// ��ȡ������������
	ProdWorkorderInfoDTO::Wrapper listDetail(const uint64_t& workorder_id);
	//��ȡ��������BOM����б�
	ProdWorkorderBomListPageDTO::Wrapper listBom(const ProdWorkorderBomListQuery::Wrapper& query);
	//��ȡ���������б�(����+��ҳ)
	GetProdWorkorderListPageDTO::Wrapper listAll(const GetProdWorkorderListQuery::Wrapper& query);
	//�����������
	uint64_t saveData(const AddProdWorkorderDTO::Wrapper& dto);
};



#endif // !_PRODWORKORDER_SERVICE_