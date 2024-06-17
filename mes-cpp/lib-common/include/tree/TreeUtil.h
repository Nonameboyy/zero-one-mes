#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/02/13 15:09:41

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
#ifndef _TREEUTIL_H_
#define _TREEUTIL_H_
#include "TreeNode.h"
#include "TreeNodeMapper.h"

/**
 * �������ݹ����࣬���ڽ����ӹ�ϵ���б�����ת������������
 */
class TreeUtil
{
private:
	static void findChildNodes(TreeNode* parentNode, list<shared_ptr<TreeNode>>* nodes)
	{
		for (shared_ptr<TreeNode> child : *nodes) {
			// �ҵ����ڵ���ӽڵ�
			if (parentNode->_id() == child->_pid()) {
				// �����ӽڵ����ز������
				child->_depth(parentNode->_depth() + 1);
				// ���ӽڵ���ӵ����ڵ���ӽڵ㼯����
				parentNode->addChild(child);
				// �����ӽڵ�������ӽڵ�
				findChildNodes(child.get(), nodes);
			}
		}
	}
public:
	//************************************
	// Method:    listToTree
	// FullName:  TreeUtil::listToTree
	// Access:    public static 
	// Returns:   ����ת���������
	// Description: ��������ת������������
	// Parameter: const list<T> & dataList ��ת����������
	// Parameter: const M & mapper ��������ڵ������ֶ�ƥ����
	//************************************
	template<typename T, typename M = TreeNodeMapper<T>>
	static list<shared_ptr<TreeNode>> listToTree(const list<T>& dataList, const M& mapper)
	{
		// �Ѽ����е�����ת��Ϊ�ڵ�����
		list<shared_ptr<TreeNode>> nodes;
		for (T row : dataList) {
			shared_ptr<TreeNode> node = mapper.objectMapper(&row);
			nodes.push_back(node);
		}
		// ����һ�����в�νṹ����
		list<shared_ptr<TreeNode>> tree;
		// ѭ����ȡ���ڵ�
		for (shared_ptr<TreeNode> node : nodes) {
			if ("" == node->_pid()) {
				node->_depth(0);
				tree.push_back(node);
				// �����ӽڵ�
				findChildNodes(node.get(), &nodes);
			}
		}
		return tree;
	}
};

#endif // !_TREEUTIL_H_