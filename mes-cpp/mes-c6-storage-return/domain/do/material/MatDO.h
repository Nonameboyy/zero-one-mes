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
 * 供应商退货表数据库实体类
 */
class MatlistDO
{
	// 退货单ID
	CC_SYNTHESIZE(uint64_t, rtid, Rtid);
	// 退货单编号
	CC_SYNTHESIZE(string, rtcode, Rtcode);
	// 退货单名称
	CC_SYNTHESIZE(string, rtname, Rtname);
	// 采购订单编号
	CC_SYNTHESIZE(string, pocode, Pocode);
	// 供应商ID
	CC_SYNTHESIZE(uint64_t, vendorid, Vendorid);
	// 供应商编码
	CC_SYNTHESIZE(string, vendorcode, Vendorcode);
	// 供应商名称
	CC_SYNTHESIZE(string, vendorname, Vendorname);
	// 供应商简称
	CC_SYNTHESIZE(string, vendornick, Vendornick);
	// 批次号
	CC_SYNTHESIZE(string, batchcode, Batchcode);
	// 退货日期
	CC_SYNTHESIZE(string, rtdate, Rtdate);
	// 单据状态
	CC_SYNTHESIZE(string, statuss, Statuss);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 预留字段1
	CC_SYNTHESIZE(string, attr1, Attr1);
	// 预留字段2
	CC_SYNTHESIZE(string, attr2, Attr2);
	// 预留字段3
	CC_SYNTHESIZE(int, attr3, Attr3);
	// 预留字段4
	CC_SYNTHESIZE(int, attr4, Attr4);
	// 创建者
	CC_SYNTHESIZE(string, createby, Createby);
	// 创建时间
	CC_SYNTHESIZE(string, createtime, Createtime);
	// 更新者
	CC_SYNTHESIZE(string, updateby, Updateby);
	// 更新时间
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
 * 供应商退货行数据库实体类
 */
class MatlineDO
{
	// 行ID
	CC_SYNTHESIZE(uint64_t, lineid, Lineid);
	// 退货单ID
	CC_SYNTHESIZE(uint64_t, rtid, Rtid);
	// 库存记录ID
	CC_SYNTHESIZE(uint64_t, materialstockid, Materialstockid);
	// 产品物料ID
	CC_SYNTHESIZE(uint64_t, itemid, Itemid);
	// 产品物料编码
	CC_SYNTHESIZE(string, itemcode, Itemcode);
	// 产品物料名称
	CC_SYNTHESIZE(string, itemname, Itemname);
	// 规格型号
	CC_SYNTHESIZE(string, specification, Specification);
	// 单位
	CC_SYNTHESIZE(string, unitofmeasure, Unitofmeasure);
	// 退货数量
	CC_SYNTHESIZE(double, quantityrted, Quantityrted);
	// 批次号
	CC_SYNTHESIZE(string, batchcode, Batchcode);
	// 仓库ID
	CC_SYNTHESIZE(uint64_t, warehouseid, Warehouseid);
	// 仓库编码
	CC_SYNTHESIZE(string, warehousecode, Warehousecode);
	// 仓库名称
	CC_SYNTHESIZE(string, warehousename, Warehousename);
	// 库区ID
	CC_SYNTHESIZE(uint64_t, locationid, Locationid);
	// 库区编码
	CC_SYNTHESIZE(string, locationcode, Locationcode);
	// 库区名称
	CC_SYNTHESIZE(string, locationname, Locationname);
	// 库位ID
	CC_SYNTHESIZE(uint64_t, areaid, Areaid);
	// 库位编码
	CC_SYNTHESIZE(string, areacode, Areacode);
	// 库位名称
	CC_SYNTHESIZE(string, areaname, Areaname);
	// 备注
	CC_SYNTHESIZE(string, remark, Remark);
	// 预留字段1
	CC_SYNTHESIZE(string, attr1, Attr1);
	// 预留字段2
	CC_SYNTHESIZE(string, attr2, Attr2);
	// 预留字段3
	CC_SYNTHESIZE(int, attr3, Attr3);
	// 预留字段4
	CC_SYNTHESIZE(int, attr4, Attr4);
	// 创建者
	CC_SYNTHESIZE(string, createby, Createby);
	// 创建时间
	CC_SYNTHESIZE(string, createtime, Createtime);
	// 更新者
	CC_SYNTHESIZE(string, updateby, Updateby);
	// 更新时间
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
