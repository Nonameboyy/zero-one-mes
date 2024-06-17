#include "stdafx.h"
#include "EquipmentController.h"
#include "../../domain/vo/equipment/EquipmentTypeTreeVO.h"
#include "domain/do/equipment/EquipmentTypeDO.h"
#include "tree/TreeUtil.h"
#include "service/equipment/TreeEquipmentTypeMapper.h"
#include "service/equipment/EquipmentService.h"

EquipmentTypeTreeVO::Wrapper EquipmentController::executeGetEquipmentTypeTree(const PayloadDTO& payload)
{
	// ����һ��JsonVO����
	auto vo = EquipmentTypeTreeVO::createShared();
	// ��ѯ�豸����
	EquipmentService service;
	list<EquipmentTypeDO> listData = service.listTypeAll();
	// ת��Ϊ���νṹ
	list<shared_ptr<TreeNode>> res = TreeUtil::listToTree<EquipmentTypeDO>(listData, TreeEquipmentMapper());
	// �����ڵ�洢���б���
	for (auto one : res)
	{
		vo->data->push_back(EquipmentTypeDTO::Wrapper(dynamic_pointer_cast<EquipmentTypeDTO>(one), EquipmentTypeDTO::Wrapper::Class::getType()));
	}
	return vo;
}

EquipmentPageVO::Wrapper EquipmentController::execGetEquipmentList(const EquipmentQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	EquipmentService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = EquipmentPageVO::createShared();
	jvo->success(result);
	return jvo;
}


