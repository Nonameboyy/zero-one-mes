#include "stdafx.h"
#include "EquipmentDAO.h"
#include"../../dao/equipment/EquipmentMapper.h"
//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->eCode) { \
	sql << " AND `machinery_code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->eCode.getValue("")); \
} \
if (query->eName) { \
	sql << " AND machinery_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->eName.getValue("")); \
} 

#define SAMPLE_TERAM_PARSEX(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->eId) { \
	sql << " AND `machinery_id`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->eId.getValue(0)); \
}




uint64_t EquipmentDAO::count(const EquipmentQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM dv_machinery";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<dvMachineryDO> EquipmentDAO::selectWithPage(const EquipmentQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT machinery_id,machinery_code,machinery_name,machinery_brand,machinery_spec,workshop_id,workshop_code,workshop_name,status,create_time FROM dv_machinery";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	EquipmentMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<dvMachineryDO, EquipmentMapper>(sqlStr, mapper, params);
}

list<dvMachineryDO> EquipmentDAO::selectWithId(const EquipmentDetailQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT machinery_id,machinery_code,machinery_name,machinery_brand,machinery_type_id,machinery_type_code,machinery_type_name,machinery_spec,workshop_id,workshop_code,workshop_name,remark FROM dv_machinery ";
	SAMPLE_TERAM_PARSEX(query, sql);
	EquipmentDetailMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<dvMachineryDO, EquipmentDetailMapper>(sqlStr, mapper, params);
}


list<dvMachineryTypeDO> EquipmentDAO::getMachinerytypeidByname(std::string name)
{
	string sql = "SELECT machinery_type_id FROM dv_machinery_type WHERE machinery_type_name= ? ";
	EquipmentTypeMapper mapper;
	return sqlSession->executeQuery<dvMachineryTypeDO, EquipmentTypeMapper>(sql, mapper,"%s" ,name);
}

list<MdWorkshopDO> EquipmentDAO::getWorkshopidByname(std::string name)
{
	string sql = "SELECT workshop_id FROM md_workshop WHERE workshop_name= ? ";
	WorkshopMapper mapper;
	return sqlSession->executeQuery<MdWorkshopDO, WorkshopMapper>(sql, mapper, "%s", name);
}

int EquipmentDAO::modify( dvMachineryDO iObj)
{

	list<dvMachineryDO> MachineryList = getMachineryByid(iObj.getMachineryId());
	dvMachineryDO machinery;

	uint64_t invalidTypeId = numeric_limits<uint64_t>::max();

	if (!MachineryList.empty())
	{
		//获取指向第一个元素的迭代器
		auto  it= MachineryList.begin();
		
		machinery.setMachineryCode(it->getMachineryCode());
		machinery.setMachineryName(it->getMachineryName());
		machinery.setMachineryBrand(it->getMachineryBrand());
		machinery.setMachineryTypeId(it->getMachineryTypeId());
		machinery.setMachineryTypeCode(it->getMachineryTypeCode());
		machinery.setMachineryTypeName(it->getMachineryTypeName());
		machinery.setMachinerySpec(it->getMachinerySpec());
		machinery.setWorkshopId(it->getWorkshopId());
		machinery.setWorkshopCode(it->getWorkshopCode());
		machinery.setWorkshopName(it->getWorkshopName());
		machinery.setRemark(it->getRemark());
	}
	else
	{
		RS_PARAMS_INVALID;
		return 0;
	}

	//uint64_t WorkshopId;
	//uint64_t machineryTypeId;
	//list<dvMachineryTypeDO>s1 = getMachinerytypeidByname(iObj.getMachineryTypeName());
	//if (!s1.empty())
	//{
	//	 //获取指向第一个元素的迭代器
	//	list<dvMachineryTypeDO>::iterator it = s1.begin();
	//	// 获取第一个 machinery_type_id
	//	machineryTypeId = it->getMachineryTypeId();
	//}
	//

	//list<MdWorkshopDO>s2 = getWorkshopidByname(iObj.getWorkshopName());
	//if (!s2.empty())
	//{
	//	// 获取指向第一个元素的迭代器
	//	list<MdWorkshopDO>::iterator it = s2.begin();
	//	// 获取第一个 machinery_type_id
	//	WorkshopId = it->getWorkshopId();
	//}


	if (iObj.getMachineryCode().empty())
	{
		iObj.setMachineryCode(machinery.getMachineryCode());
	}
	if (iObj.getMachineryName().empty())
	{
		iObj.setMachineryName (machinery.getMachineryName());
	}
	if (iObj.getMachineryBrand().empty())
	{
		iObj.setMachineryBrand( machinery.getMachineryBrand());
	}


	if (iObj.getMachineryTypeId()!= invalidTypeId)
	{
		
		list<dvMachineryTypeDO>path1 = getMachinerytypeByid(iObj.getMachineryTypeId());
		if (!path1.empty())
		{
			auto it = path1.begin();
			iObj.setMachineryTypeCode(it->getMachineryTypeCode());
			iObj.setMachineryTypeName(it->getMachineryTypeName());
		}

	}
	else
	{
		
		iObj.setMachineryTypeId( machinery.getMachineryTypeId());
		iObj.setMachineryTypeCode(machinery.getMachineryTypeCode());
		iObj.setMachineryTypeName(machinery.getMachineryTypeName());
	}
	

	if (iObj.getMachinerySpec().empty())
	{
		iObj.setMachinerySpec(machinery.getMachinerySpec());
	}

	if (iObj.getWorkshopId()!= invalidTypeId)
	{
		list<MdWorkshopDO> path = getWorkshopByid(iObj.getWorkshopId());
		if (!path.empty())
		{
			auto it = path.begin();
			iObj.setWorkshopCode(it->getWorkshopCode());
			iObj.setWorkshopName(it->getWorkshopName());
		}
	}
	else
	{
		iObj.setWorkshopId(machinery.getWorkshopId());
		iObj.setWorkshopCode(machinery.getWorkshopCode());
		iObj.setWorkshopName(machinery.getWorkshopName());

	}
	if (iObj.getRemark().empty())
	{
		iObj.setRemark(machinery.getRemark());
	}





	string sql = "UPDATE `dv_machinery` SET `machinery_code`=?, `machinery_name`=?, `machinery_brand`=?,`machinery_type_id`=?,`machinery_type_code`=?,`machinery_type_name`=?,`machinery_spec`=?,`workshop_id`=?,`workshop_code`=?,`workshop_name`=?,`remark`=?,`update_by`=?,`update_time`=? WHERE `machinery_id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%i%s%s%s%i%s%s%s%s%s%i", iObj.getMachineryCode(), iObj.getMachineryName(), iObj.getMachineryBrand(), iObj.getMachineryTypeId(),iObj.getMachineryTypeCode(),iObj.getMachineryTypeName(), iObj.getMachinerySpec(), iObj.getWorkshopId(),iObj.getWorkshopCode(),iObj.getWorkshopName(), iObj.getRemark(),iObj.getUpdateBy(),iObj.getUpdateTime(), iObj.getMachineryId());
}

list<MdWorkshopDO> EquipmentDAO::getWorkshopByid(std::int64_t id)
{
	string sql = "SELECT workshop_id,workshop_code,workshop_name FROM md_workshop WHERE workshop_id= ? ";
	WorkshopdetailMapper mapper;
	return sqlSession->executeQuery<MdWorkshopDO, WorkshopdetailMapper>(sql, mapper, "%i", id);
}

list<dvMachineryTypeDO> EquipmentDAO::getMachinerytypeByid(std::int64_t id)
{
	string sql = "SELECT machinery_type_id,machinery_type_code,machinery_type_name FROM dv_machinery_type WHERE machinery_type_id= ? ";
	EquipmentTypeDetailMapper mapper;
	return sqlSession->executeQuery<dvMachineryTypeDO, EquipmentTypeDetailMapper>(sql, mapper, "%i", id);
}

list<dvMachineryDO> EquipmentDAO::getMachineryByid(std::int64_t id)
{
	string sql = "SELECT machinery_id,machinery_code,machinery_name,machinery_brand,machinery_type_id,machinery_type_code,machinery_type_name,machinery_spec,workshop_id,workshop_code,workshop_name,remark FROM dv_machinery WHERE `machinery_id`=?";
	EquipmentSampleMapper mapper;
	return sqlSession->executeQuery<dvMachineryDO, EquipmentSampleMapper>(sql, mapper, "%i", id);
}

uint64_t EquipmentDAO::insert( dvMachineryDO& iObj)
{
	//uint64_t machineryTypeId;
	//uint64_t WorkshopId;
	//list<dvMachineryTypeDO>s1= getMachinerytypeidByname(iObj.getMachineryTypeName());
	//if (!s1.empty())
	//{
	//	// 获取指向第一个元素的迭代器
	//	list<dvMachineryTypeDO>::iterator it = s1.begin();
	//	// 获取第一个 machinery_type_id
	//	 machineryTypeId = it->getMachineryTypeId();
	//}
	//else
	//{
	//	RS_PARAMS_INVALID;
	//	return 0;
	//}

	//list<MdWorkshopDO>s2 = getWorkshopidByname(iObj.getWorkshopName());
	//if (!s2.empty())
	//{
	//	// 获取指向第一个元素的迭代器
	//	list<MdWorkshopDO>::iterator it = s2.begin();
	//	// 获取第一个 machinery_type_id
	//	 WorkshopId = it->getWorkshopId();
	//}
	//else
	//{
	//	RS_PARAMS_INVALID;
	//	return 0;
	//}

	EquipmentDAO dao;
	list<MdWorkshopDO> path = dao.getWorkshopByid(iObj.getWorkshopId());
	if (!path.empty())
	{
		auto it = path.begin();
		iObj.setWorkshopCode(it->getWorkshopCode());
		iObj.setWorkshopName(it->getWorkshopName());
	}

	list<dvMachineryTypeDO>path1 = dao.getMachinerytypeByid(iObj.getMachineryTypeId());
	if (!path1.empty())
	{
		auto it = path1.begin();
		iObj.setMachineryTypeCode(it->getMachineryTypeCode());
		iObj.setMachineryTypeName(it->getMachineryTypeName());
	}



	string sql = "INSERT INTO `dv_machinery` (`machinery_code`, `machinery_name`, `machinery_brand`,`machinery_type_id`,`machinery_type_code`,`machinery_type_name`,`machinery_spec`,`workshop_id`,`workshop_code`,`workshop_name`,`create_by`,`create_time`,`remark`) VALUES (?, ?, ?,?,?,?,?,?,?,?,?,?,?)";

	return sqlSession->executeInsert(sql, "%s%s%s%i%s%s%s%i%s%s%s%s%s", iObj.getMachineryCode(), iObj.getMachineryName(), iObj.getMachineryBrand(),iObj.getMachineryTypeId(), iObj.getMachineryTypeCode(),iObj.getMachineryTypeName(),iObj.getMachinerySpec(), iObj.getWorkshopId(),iObj.getWorkshopCode(),iObj.getWorkshopName(),iObj.getCreateBy(),iObj.getCreateTime(), iObj.getRemark());
}
