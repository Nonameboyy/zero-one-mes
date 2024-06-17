#pragma once
#ifndef _QC_DEFECT_DO_
#define _QC_DEFECT_DO_
#include "../DoInclude.h"

/**
* 常见缺陷表
*/
class  QcDefectDO
{
    // 缺陷ID
    CC_SYNTHESIZE(int64_t, defect_id, DefectId);
    // 缺陷编码
    CC_SYNTHESIZE(string, defect_code, DefectCode);
    // 缺陷描述
    CC_SYNTHESIZE(string, defect_name, DefectName);
    // 检测项类型
    CC_SYNTHESIZE(string, index_type, IndexType);
    // 缺陷等级
    CC_SYNTHESIZE(string, defect_level, DefectLevel);
    // 备注
    CC_SYNTHESIZE(string, remark, Remark);
    // 预留字段1
    CC_SYNTHESIZE(string, attr1, Attr1);
    // 预留字段2
    CC_SYNTHESIZE(string, attr2, Attr2);
    // 预留字段3
    CC_SYNTHESIZE(int32_t, attr3, Attr3);
    // 预留字段4
    CC_SYNTHESIZE(int32_t, attr4, Attr4);
    // 创建者
    CC_SYNTHESIZE(string, create_by, CreateBy);
    // 创建时间
    CC_SYNTHESIZE(string, create_time, CreateTime);
    // 更新者
    CC_SYNTHESIZE(string, update_by, UpdateBy);
    // 更新时间
    CC_SYNTHESIZE(string, update_time, UpdateTime);

public:
    QcDefectDO() : defect_id(0), attr3(0), attr4(0) {}
};

#endif 