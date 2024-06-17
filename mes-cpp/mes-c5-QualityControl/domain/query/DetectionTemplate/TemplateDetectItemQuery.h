#pragma once
#ifndef _TEMPLATEDETECTITEM_QUERY_
#define _TEMPLATEDETECTITEM_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 分页查询对象
 */
class TemplateDetectItemQuery : public PageQuery
{
	DTO_INIT(TemplateDetectItemQuery, PageQuery);
	// 记录ID
	DTO_FIELD(UInt64, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.record_id");
	}

	// 检测模板ID
	DTO_FIELD(UInt64, template_id);
	DTO_FIELD_INFO(template_id) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.template_id");
	}

	// 检测项ID
	DTO_FIELD(UInt64, index_id);
	DTO_FIELD_INFO(index_id) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.index_id");
	}

	// 检测项编码
	DTO_FIELD(String, index_code);
	DTO_FIELD_INFO(index_code) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.index_code");
	}

	// 检测项名称
	DTO_FIELD(String, index_name);
	DTO_FIELD_INFO(index_name) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.index_name");
	}

	// 检测项类型
	DTO_FIELD(String, index_type);
	DTO_FIELD_INFO(index_type) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.index_type");
	}

	// 检测工具
	DTO_FIELD(String, qc_tool);
	DTO_FIELD_INFO(qc_tool) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.qc_tool");
	}

	// 检测方法
	DTO_FIELD(String, check_method);
	DTO_FIELD_INFO(check_method) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.check_method");
	}

	// 标准值
	DTO_FIELD(Float64, stander_val);
	DTO_FIELD_INFO(stander_val) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.stander_val");
	}

	// 单位
	DTO_FIELD(String, unit_of_measure);
	DTO_FIELD_INFO(unit_of_measure) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.unit_of_measure");
	}

	// 误差上限
	DTO_FIELD(Float64, threshold_max);
	DTO_FIELD_INFO(threshold_max) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.threshold_max");
	}

	// 误差下限
	DTO_FIELD(Float64, threshold_min);
	DTO_FIELD_INFO(threshold_min) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.threshold_min");
	}

	// 说明图
	DTO_FIELD(String, doc_url);
	DTO_FIELD_INFO(doc_url) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.doc_url");
	}

	// 备注
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.remark");
	}

	// 预留字段1
	DTO_FIELD(String, attr1);
	DTO_FIELD_INFO(attr1) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.attr1");
	}

	// 预留字段2
	DTO_FIELD(String, attr2);
	DTO_FIELD_INFO(attr2) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.attr2");
	}

	// 预留字段3
	DTO_FIELD(Int32, attr3);
	DTO_FIELD_INFO(attr3) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.attr3");
	}

	// 预留字段4
	DTO_FIELD(Int32, attr4);
	DTO_FIELD_INFO(attr4) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.attr4");
	}

	// 创建者
	DTO_FIELD(String, create_by);
	DTO_FIELD_INFO(create_by) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.create_by");
	}

	// 创建时间
	DTO_FIELD(String, create_time);
	DTO_FIELD_INFO(create_time) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.createtime");
	}

	// 更新者
	DTO_FIELD(String, update_by);
	DTO_FIELD_INFO(update_by) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.update_by");
	}

	// 更新时间
	DTO_FIELD(String, update_time);
	DTO_FIELD_INFO(update_time) {
		info->description = ZH_WORDS_GETTER("templatedetectitem.field.update_time");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TEMPLATEDETECTITEM_QUERY_
