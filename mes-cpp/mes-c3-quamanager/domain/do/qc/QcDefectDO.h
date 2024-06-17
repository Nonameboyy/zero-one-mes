#pragma once
#ifndef _QC_DEFECT_DO_
#define _QC_DEFECT_DO_
#include "../DoInclude.h"

/**
* ����ȱ�ݱ�
*/
class  QcDefectDO
{
    // ȱ��ID
    CC_SYNTHESIZE(int64_t, defect_id, DefectId);
    // ȱ�ݱ���
    CC_SYNTHESIZE(string, defect_code, DefectCode);
    // ȱ������
    CC_SYNTHESIZE(string, defect_name, DefectName);
    // ���������
    CC_SYNTHESIZE(string, index_type, IndexType);
    // ȱ�ݵȼ�
    CC_SYNTHESIZE(string, defect_level, DefectLevel);
    // ��ע
    CC_SYNTHESIZE(string, remark, Remark);
    // Ԥ���ֶ�1
    CC_SYNTHESIZE(string, attr1, Attr1);
    // Ԥ���ֶ�2
    CC_SYNTHESIZE(string, attr2, Attr2);
    // Ԥ���ֶ�3
    CC_SYNTHESIZE(int32_t, attr3, Attr3);
    // Ԥ���ֶ�4
    CC_SYNTHESIZE(int32_t, attr4, Attr4);
    // ������
    CC_SYNTHESIZE(string, create_by, CreateBy);
    // ����ʱ��
    CC_SYNTHESIZE(string, create_time, CreateTime);
    // ������
    CC_SYNTHESIZE(string, update_by, UpdateBy);
    // ����ʱ��
    CC_SYNTHESIZE(string, update_time, UpdateTime);

public:
    QcDefectDO() : defect_id(0), attr3(0), attr4(0) {}
};

#endif 