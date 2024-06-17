/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "MergeMenuService.h"
#include "../../dao/warehouse-setting/MergeMenuDAO.h"

list<shared_ptr<TreeNode>> MergeMenuService::listadress() {
	MergeMenuDAO dao;
	WarehouseMenuMapper mapper1;
	LocationMenuMapper mapper2;
	AreaMenuMapper mapper3;


	//查询所有的仓库
    list<shared_ptr<TreeNode>> rootNodes;
	list<WarehouseMenuDO> warehouselist = dao.selectallwarehouse();
	//将do转化为dto
	for (WarehouseMenuDO sub1:warehouselist) {
		shared_ptr<TreeNode> node1 =mapper1.objectMapper(&sub1);
		rootNodes.push_back(node1);
		list<LocationMenuDO> locationlist=dao.selectlocation(sub1.getWarehouse_id());
		for (LocationMenuDO sub2:locationlist) {
			shared_ptr<TreeNode> node2 = mapper2.objectMapper(&sub2);
			node1->addChild(node2);
			list<AreaMenuDO> arealist = dao.selectarea(sub2.getLocation_id());
			for (AreaMenuDO sub3 : arealist) {
				shared_ptr<TreeNode> node3 = mapper3.objectMapper(&sub3);
				node2->addChild(node3);
			}
		}
	}
	return rootNodes;
}


