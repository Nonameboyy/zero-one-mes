#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/02/13 14:43:25

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
#ifndef _TREENODEMAPPER_H_
#define _TREENODEMAPPER_H_
#include "TreeNode.h"

/**
 * ����ת���ڵ�����ƥ��ӿ�,���ڴ���ͬ������TreeNode�����ֶ�����������
 */
template <typename T>
class TreeNodeMapper
{
public:
	//************************************
	// Method:    objectMapper
	// FullName:  shared_ptr<TreeNode>::objectMapper
	// Access:    virtual public 
	// Returns:   shared_ptr<TreeNode> ת�����
	// Description: ��һ�����ݶ���ת��Ϊ�ڵ�����ݶ���
	// Parameter: T * source ��ת��������Դ����
	//************************************
	virtual shared_ptr<TreeNode> objectMapper(T* source) const = 0;
};

#endif // !_TREENODEMAPPER_H_