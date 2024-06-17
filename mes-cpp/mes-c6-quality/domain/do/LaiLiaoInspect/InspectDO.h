#pragma once
#ifndef _INSPECT_DO_
#define _INSPECT_DO_
#include "../DoInclude.h"



/**
 * 来料检验列表数据库实体类
 */
class InspectDO
{
	// 来料检验单id
	CC_SYNTHESIZE(int64_t, iqc_id, Iqc_id);
	// 来料检验单编号
	CC_SYNTHESIZE(string, iqc_code, Iqc_code);
	// 来料检验单名称
	CC_SYNTHESIZE(string, iqc_name, Iqc_name);
	//检验模板ID
	CC_SYNTHESIZE(int64_t, template_id, Template_id);
	//来源单据ID
	CC_SYNTHESIZE(int64_t, source_doc_id, Source_doc_id);
	// 来源单据类型 
	CC_SYNTHESIZE(string, source_doc_type, Source_doc_type);
	// 来源单据编号
	CC_SYNTHESIZE(string, source_doc_code, Source_doc_code);
	// 来源单据行ID
	CC_SYNTHESIZE(int64_t, source_line_id, Source_line_id);
	//供应商ID
	CC_SYNTHESIZE(int64_t, vendor_id, Vendor_id);
	//供应商编码
	CC_SYNTHESIZE(string, vendor_code, Vendor_code);
	//供应商名称
	CC_SYNTHESIZE(string, vendor_name, Vendor_name);
	// 供应商简称
	CC_SYNTHESIZE(string, vendor_nick, Vendor_nick);
	//供应商批次号
	CC_SYNTHESIZE(string, vendor_batch, Vendor_batch);
	//产品物料ID
	CC_SYNTHESIZE(int64_t, item_id, Item_id);
	//产品物料编码
	CC_SYNTHESIZE(string, item_code, Item_code);
	//产品物料名称
	CC_SYNTHESIZE(string, item_name, Item_name);
	//规格型号
	CC_SYNTHESIZE(string, specification, Specification);
	//单位
	CC_SYNTHESIZE(string, unit_of_measure, Unit_of_measure);
	// 最低检测数
	CC_SYNTHESIZE(int, quantity_min_check, Quantity_min_check);
	// 最大不合格数
	CC_SYNTHESIZE(int, quantity_max_unqualified, Quantity_max_unqualified);
	//接收数量
	CC_SYNTHESIZE(double, quantity_recived, Quantity_recived);
	//检测数量
	CC_SYNTHESIZE(int, quantity_check, Quantity_check);
	//不合格数
	CC_SYNTHESIZE(int, quantity_unqualified, Quantity_unqualified);
	//致命缺陷率
	CC_SYNTHESIZE(double, maj_rate, Maj_rate);
	//严重缺陷率
	CC_SYNTHESIZE(double, cr_rate, Cr_rate);
	//轻微缺陷率
	CC_SYNTHESIZE(double, min_rate, Min_rate);
	//致命缺陷数量
	CC_SYNTHESIZE(int64_t, cr_quantity, Cr_quantity);
	//严重缺陷数量
	CC_SYNTHESIZE(int64_t, maj_quantity, Maj_quantity);
	//轻微缺陷数量
	CC_SYNTHESIZE(int64_t, min_quantity, Min_quantity);
	//检测结果
	CC_SYNTHESIZE(string, check_result, Check_result);
	//来料日期
	CC_SYNTHESIZE(string, recive_date, Recive_date);
	//检测日期
	CC_SYNTHESIZE(string, inspect_date, Inspect_date);
	//检测人员
	CC_SYNTHESIZE(string, inspector, Inspector);
	//单据状态
	CC_SYNTHESIZE(string, list_status, List_status);
	
//protected: string list_status; public: string getList_status(void) const {
//	return list_status;
//}public: void setList_status(string var) {
//	list_status = var;
//};
	//备注
	CC_SYNTHESIZE(string, remark, Remark);
	//预留字段1
	CC_SYNTHESIZE(string, attr1, Attr1);
	//预留字段2
	CC_SYNTHESIZE(string, attr2, Attr2);
	//预留字段3
	CC_SYNTHESIZE(int, attr3, Attr3);
	//预留字段4
	CC_SYNTHESIZE(int, attr4, Attr4);
	//创建者
	CC_SYNTHESIZE(string, create_by, Create_by);
	//创建时间
	CC_SYNTHESIZE(string, create_time, Create_time);
	//更新者
	CC_SYNTHESIZE(string, update_by, Update_by);
	//更新时间
	CC_SYNTHESIZE(string, update_time, Update_time);
public:
	InspectDO() {
		iqc_id = 0;
		iqc_code = "";
		iqc_name = "";
		template_id = 0;
		source_doc_id = 0;
		source_doc_type = "";
		source_doc_code = "";
		source_line_id = 0;
		vendor_id = 0;
		vendor_code = "";
		vendor_name = "";
		vendor_nick = "";
		vendor_batch = "";
		item_id = 0;
		item_code = "";
		item_name = "";
		specification = "";
		unit_of_measure = "";
		quantity_min_check = 0;
		quantity_max_unqualified = 0;
		quantity_recived = 0.0;
		quantity_check = 0;
		quantity_unqualified = 0;
		maj_rate = 0.0;
		cr_rate = 0.0;
		min_rate = 0.0;
		cr_quantity = 0;
		maj_quantity = 0;
		min_quantity = 0;
		check_result = "";
		recive_date = "";
		inspect_date = "";
		inspector = "";
		list_status = "";
		remark = "";
		attr1 = "";
		attr2 = "";
		attr3 = 0;
		attr4 = 0;
		create_by = "";
		create_time = "";
		update_by = "";
		update_time = "";
	}
};


/**
 * 来料检验详情数据库实体类
 */
class Inspect_detailDO :public InspectDO
{

};

class Inspect_tableDO :public InspectDO
{

};

#endif // !_INSPECT_DO_
