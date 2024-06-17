
#include "stdafx.h"
#include "AddDeviceDAO.h"
#include "AddDeviceMapper.h"
#include <sstream>






uint64_t AddDeviceDAO::insert(const Dv_check_machineryDO& iObj)
{
	/*string sql = "INSERT INTO `dv_check_subject`"
"(plan_id, subject_id, subject_name, subject_type, subject_content, subject_standard,
remark, attr1, attr2, attr3, attr4, create_by, create_time, update_by, update_time)"
"SELECT m.subject_id,m.subject_name,m.subject_type,m.subject_content,m.subject_standard,m.remark,m.attr1,m.attr2,m.attr3,m.attr4,m.create_by,m.create_time,m.update_by,m.update_time"
"FROM dv_subject m"
"JOIN dv_check_plan p ON m.subject_id = ? AND p.plan_id = ？";*/
	list<dvMachineryDO > s1 = getDvDevice(iObj.getMachinery_id());
	dvMachineryDO sub;
	if (!s1.empty())
	{
		// 获取指向第一个元素的迭代器
		auto it = s1.begin();
		sub.setMachineryCode(it->getMachineryCode());
		sub.setMachineryName(it->getMachineryName());
		sub.setMachineryBrand(it->getMachineryBrand());
		sub.setMachineryTypeId(it->getMachineryTypeId());
		sub.setMachineryTypeCode(it->getMachineryTypeCode());
		sub.setMachineryTypeName(it->getMachineryTypeName());
		sub.setMachineryTypeId(it->getMachineryTypeId());
		sub.setWorkshopId(it->getWorkshopId());
		sub.setWorkshopCode(it->getWorkshopCode());
		sub.setWorkshopName(it->getWorkshopName());
		sub.setStatus(it->getStatus());
		sub.setRemark(it->getRemark());
		
		/*sub.setAttr1(it->getAttr1());
		sub.setAttr2(it->getAttr2());
		sub.setCreateBy(it->getCreateBy());
		sub.setCreateTime(it->getCreateTime());
		sub.setUpdateBy(it->getUpdateBy());
		sub.setUpdateTime(it->getUpdateTime());*/
	}


	string sql = "INSERT INTO `dv_check_machinery` (`plan_id`, `machinery_id`, `machinery_code`,`machinery_name`,`machinery_brand`,`machinery_spec`,`remark`,`create_by`,`create_time`) VALUES (?, ?, ?,?,?,?,?,?,?)";

	return sqlSession->executeInsert(sql, "%i%i%s%s%s%s%s%s%s", iObj.getPlan_id(), iObj.getMachinery_id(), sub.getMachineryCode(), sub.getMachineryName(), sub.getMachineryBrand(), sub.getMachinerySpec(), sub.getRemark(), iObj.getCreate_by(), iObj.getCreate_time());


}
list<dvMachineryDO> AddDeviceDAO::getDvDevice(uint64_t id)
{

	string sql = "SELECT machinery_code,machinery_name,machinery_brand,machinery_spec,remark,create_time FROM dv_machinery WHERE `machinery_id`=?";
	AddMachineryMapper mapper;
	return sqlSession->executeQuery<dvMachineryDO, AddMachineryMapper>(sql, mapper, "%i", id);


}

//string sql = "DELETE from `dv_subject` WHERE `subject_id` in(" + uObj.getSubjectId() + ")";