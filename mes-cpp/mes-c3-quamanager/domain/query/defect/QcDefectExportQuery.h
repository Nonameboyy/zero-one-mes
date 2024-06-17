#ifndef _QC_DEFECT_EXPORT_QUERY_H_
#define _QC_DEFECT_EXPORT_QUERY_H_

#include "domain/GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class QcDefectExportQuery : public PageQuery
{
    DTO_INIT(QcDefectExportQuery, PageQuery);

    DTO_FIELD(String, defect_code);
    DTO_FIELD_INFO(defect_code)
    {
        info->description = u8"缺陷名称";
    };

    DTO_FIELD(String, defect_name);
    DTO_FIELD_INFO(defect_name)
    {
        info->description = u8"缺陷名称";
    };
    DTO_FIELD(String, index_type);
    DTO_FIELD_INFO(index_type)
    {
        info->description = u8"缺陷类型";
    };
    DTO_FIELD(String, defect_level);
    DTO_FIELD_INFO(defect_level)
    {
        info->description = u8"缺陷等级";
    };
};

#include OATPP_CODEGEN_END(DTO)
#endif