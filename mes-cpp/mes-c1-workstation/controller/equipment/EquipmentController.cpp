#include "stdafx.h"
#include "EquipmentController.h"
#include "../../domain/vo/equipment/EquipmentTypeTreeVO.h"
#include "domain/do/equipment/EquipmentTypeDO.h"
#include "tree/TreeUtil.h"
#include "service/equipment/TreeEquipmentTypeMapper.h"
#include "service/equipment/EquipmentService.h"

EquipmentTypeTreeVO::Wrapper EquipmentController::executeGetEquipmentTypeTree(const PayloadDTO& payload)
{
	// 定义一个JsonVO对象
	auto vo = EquipmentTypeTreeVO::createShared();
	// 查询设备密码
	EquipmentService service;
	list<EquipmentTypeDO> listData = service.listTypeAll();
	// 转换为树形结构
	list<shared_ptr<TreeNode>> res = TreeUtil::listToTree<EquipmentTypeDO>(listData, TreeEquipmentMapper());
	// 将根节点存储到列表中
	for (auto one : res)
	{
		vo->data->push_back(EquipmentTypeDTO::Wrapper(dynamic_pointer_cast<EquipmentTypeDTO>(one), EquipmentTypeDTO::Wrapper::Class::getType()));
	}
	return vo;
}

EquipmentPageVO::Wrapper EquipmentController::execGetEquipmentList(const EquipmentQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	EquipmentService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = EquipmentPageVO::createShared();
	jvo->success(result);
	return jvo;
}


