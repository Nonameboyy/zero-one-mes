#ifndef _QC_DEFECR_EXPORT_MAPPER_
#define _QC_DEFECR_EXPORT_MAPPER_

#include "Mapper.h"
#include "domain/do/qc/QcDefectDO.h"

class QcDefectExportMapper : public Mapper<QcDefectDO>
{
public:
    QcDefectDO mapper(ResultSet *resultSet) const override
    {
        QcDefectDO data;
        data.setDefectCode(resultSet->getString(1));
        data.setDefectName(resultSet->getString(2));
        data.setIndexType(resultSet->getString(3));
        data.setDefectLevel(resultSet->getString(4));
        return data;
    }
};

#endif