#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ronaldo
 @Date: 2024/5/27 11:52:32

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
#ifndef _MATDO_H_
#define _MATDO_H_
#include "../DoInclude.h"

/**
 * ��Ӧ���˻������ݿ�ʵ����
 */
class MatlistDO
{
	// �˻���ID
	CC_SYNTHESIZE(uint64_t, rtid, Rtid);
	// �˻������
	CC_SYNTHESIZE(string, rtcode, Rtcode);
	// �˻�������
	CC_SYNTHESIZE(string, rtname, Rtname);
	// �ɹ��������
	CC_SYNTHESIZE(string, pocode, Pocode);
	// ��Ӧ��ID
	CC_SYNTHESIZE(uint64_t, vendorid, Vendorid);
	// ��Ӧ�̱���
	CC_SYNTHESIZE(string, vendorcode, Vendorcode);
	// ��Ӧ������
	CC_SYNTHESIZE(string, vendorname, Vendorname);
	// ��Ӧ�̼��
	CC_SYNTHESIZE(string, vendornick, Vendornick);
	// ���κ�
	CC_SYNTHESIZE(string, batchcode, Batchcode);
	// �˻�����
	CC_SYNTHESIZE(string, rtdate, Rtdate);
	// ����״̬
	CC_SYNTHESIZE(string, statuss, Statuss);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// Ԥ���ֶ�1
	CC_SYNTHESIZE(string, attr1, Attr1);
	// Ԥ���ֶ�2
	CC_SYNTHESIZE(string, attr2, Attr2);
	// Ԥ���ֶ�3
	CC_SYNTHESIZE(int, attr3, Attr3);
	// Ԥ���ֶ�4
	CC_SYNTHESIZE(int, attr4, Attr4);
	// ������
	CC_SYNTHESIZE(string, createby, Createby);
	// ����ʱ��
	CC_SYNTHESIZE(string, createtime, Createtime);
	// ������
	CC_SYNTHESIZE(string, updateby, Updateby);
	// ����ʱ��
	CC_SYNTHESIZE(string, updatetime, Updatetime);
public:
	MatlistDO() {
		rtid = 0;
		rtcode = "";
		rtname = "";
		pocode = "";
	}
};
/**
 * ��Ӧ���˻������ݿ�ʵ����
 */
class MatlineDO
{
	// ��ID
	CC_SYNTHESIZE(uint64_t, lineid, Lineid);
	// �˻���ID
	CC_SYNTHESIZE(uint64_t, rtid, Rtid);
	// ����¼ID
	CC_SYNTHESIZE(uint64_t, materialstockid, Materialstockid);
	// ��Ʒ����ID
	CC_SYNTHESIZE(uint64_t, itemid, Itemid);
	// ��Ʒ���ϱ���
	CC_SYNTHESIZE(string, itemcode, Itemcode);
	// ��Ʒ��������
	CC_SYNTHESIZE(string, itemname, Itemname);
	// ����ͺ�
	CC_SYNTHESIZE(string, specification, Specification);
	// ��λ
	CC_SYNTHESIZE(string, unitofmeasure, Unitofmeasure);
	// �˻�����
	CC_SYNTHESIZE(double, quantityrted, Quantityrted);
	// ���κ�
	CC_SYNTHESIZE(string, batchcode, Batchcode);
	// �ֿ�ID
	CC_SYNTHESIZE(uint64_t, warehouseid, Warehouseid);
	// �ֿ����
	CC_SYNTHESIZE(string, warehousecode, Warehousecode);
	// �ֿ�����
	CC_SYNTHESIZE(string, warehousename, Warehousename);
	// ����ID
	CC_SYNTHESIZE(uint64_t, locationid, Locationid);
	// ��������
	CC_SYNTHESIZE(string, locationcode, Locationcode);
	// ��������
	CC_SYNTHESIZE(string, locationname, Locationname);
	// ��λID
	CC_SYNTHESIZE(uint64_t, areaid, Areaid);
	// ��λ����
	CC_SYNTHESIZE(string, areacode, Areacode);
	// ��λ����
	CC_SYNTHESIZE(string, areaname, Areaname);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// Ԥ���ֶ�1
	CC_SYNTHESIZE(string, attr1, Attr1);
	// Ԥ���ֶ�2
	CC_SYNTHESIZE(string, attr2, Attr2);
	// Ԥ���ֶ�3
	CC_SYNTHESIZE(int, attr3, Attr3);
	// Ԥ���ֶ�4
	CC_SYNTHESIZE(int, attr4, Attr4);
	// ������
	CC_SYNTHESIZE(string, createby, Createby);
	// ����ʱ��
	CC_SYNTHESIZE(string, createtime, Createtime);
	// ������
	CC_SYNTHESIZE(string, updateby, Updateby);
	// ����ʱ��
	CC_SYNTHESIZE(string, updatetime, Updatetime);
public:
	MatlineDO() {
		lineid = 0;
		rtid = 0;
		materialstockid = 0;
		itemid = 0;
		itemcode = "";
		itemname = "";
		specification = "";
	}
};

#endif // !_MATDO_H_
