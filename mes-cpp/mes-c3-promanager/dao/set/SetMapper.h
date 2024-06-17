#pragma once
#ifndef _SET_MAPPER_
#define _SET_MAPPER_

#include "Mapper.h"
#include "../../domain/do/pro/ProProcessDO.h"
#include "../../domain/do/pro/ProProcessContentDO.h"

/**
 * Ê¾Àı±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class SetMapper : public Mapper<ProProcessDO>
{
public:
	ProProcessDO mapper(ResultSet* resultSet) const override
	{
		ProProcessDO data;
		data.setProcessCode(resultSet->getString(2));
		data.setProcessName(resultSet->getString(3));
		data.setEnableFlag(resultSet->getString(4));
		data.setAttention(resultSet->getString(5));
		data.setRemark(resultSet->getString(6));
		data.setProcessId(resultSet->getUInt64(1));
		return data;
	}
};

class SetStepMapper : public Mapper<ProProcessContentDO>
{
public:
	ProProcessContentDO mapper(ResultSet* resultSet) const override
	{
		ProProcessContentDO data; 
		data.setProcessId(resultSet->getUInt64(1));
		data.setOrderNum(resultSet->getInt(2));
		data.setContentText(resultSet->getString(3));
		data.setDevice(resultSet->getString(4));
		data.setMaterial(resultSet->getString(5));
		data.setDocUrl(resultSet->getString(6));
		data.setRemark(resultSet->getString(7));
		return data;
	}
};
//µ¼³ö¹¤Ğò²½Öè
class SetStepExportMapper : public Mapper<ProProcessContentDO>
{
public:
	ProProcessContentDO mapper(ResultSet* resultSet) const override
	{
		ProProcessContentDO data;
		data.setProcessId(resultSet->getUInt64(1));
		data.setOrderNum(resultSet->getInt(2));
		data.setContentText(resultSet->getString(3));
		data.setDevice(resultSet->getString(4));
		data.setMaterial(resultSet->getString(5));
		data.setDocUrl(resultSet->getString(6));
		return data;
	}
};
/**
 * pro_process±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class ProDetailMapper : public Mapper<ProProcessDO>
{
public:
	ProProcessDO mapper(ResultSet* resultSet) const override
	{
		ProProcessDO data;
		data.setProcessId(resultSet->getUInt64(1));
		data.setProcessCode(resultSet->getString(2));
		data.setProcessName(resultSet->getString(3));
		data.setAttention(resultSet->getString(4));
		data.setEnableFlag(resultSet->getString(5));
		data.setRemark(resultSet->getString(6));
		return data;
	}
};
/**
 * pro_process±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class ProListMapper : public Mapper<ProProcessDO>
{
public:
	ProProcessDO mapper(ResultSet* resultSet) const override
	{
		ProProcessDO data;
		data.setProcessId(resultSet->getUInt64(1));
		data.setProcessCode(resultSet->getString(2));
		data.setProcessName(resultSet->getString(3));
		data.setEnableFlag(resultSet->getString(4));
		data.setRemark(resultSet->getString(5));
		return data;
	}
};
/**
 * pro_process±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class ProNameListMapper : public Mapper<ProProcessDO>
{
public:
	ProProcessDO mapper(ResultSet* resultSet) const override
	{
		ProProcessDO data;
		data.setProcessId(resultSet->getUInt64(1));
		data.setProcessCode(resultSet->getString(2));
		data.setProcessName(resultSet->getString(3));
		return data;
	}
};
#endif // !_SET_MAPPER_