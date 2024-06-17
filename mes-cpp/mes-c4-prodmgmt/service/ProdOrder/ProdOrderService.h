#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/02/17 16:29:07

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
#ifndef _TREEMENUMAPPER_H_
#define _TREEMENUMAPPER_H_

#include "tree/TreeNodeMapper.h"
#include "domain/do/ProdOrder/ProdOrderDO.h"
#include "domain/dto/ProdOrder/ProdOrderDTO.h"

/**
 * ��ʾ�˵������ֶ�ƥ��ʵ��
 */
class ProdOrderTreeMapper : public TreeNodeMapper<ProdOrderQueryTreeDO>
{
public:
	shared_ptr<TreeNode> objectMapper(ProdOrderQueryTreeDO* source) const override
	{
		// ����������ݶ���
		auto res = make_shared<ProdOrderQueryTreeDTO>();
		// ����㼶�ṹ����ӳ��
		res->_id(source->getId());
		res->_pid(source->getParentId());
		// ��չ����ӳ��
		res->task_name = source->getTask_name();
		res->workstation_name = source->getWorkstation_name();
		res->process_name = source->getProcess_name();
		res->start_time = source->getStart_time();
		res->end_time = source->getEnd_time();
		return res;
	}
};

#endif // !_TREEMENUMAPPER_H_