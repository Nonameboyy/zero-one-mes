#pragma once

#ifndef _WORKSTATION_DTO_H_
#define _WORKSTATION_DTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 新增工作站数据模型
 */
class AddWorkStationDTO : public oatpp::DTO
{
	DTO_INIT(AddWorkStationDTO, DTO);
	// 唯一标识（工作站ID）
	API_DTO_FIELD_DEFAULT(UInt64, workstationId, ZH_WORDS_GETTER("workstation.fields.workstationId"));
	// 工作站编号
	API_DTO_FIELD_DEFAULT(String, workstationCode, ZH_WORDS_GETTER("workstation.fields.workstationCode"));
	//工作站名称
	API_DTO_FIELD_DEFAULT(String, workstationName, ZH_WORDS_GETTER("workstation.fields.workstationName"));
	// 工作站地点
	API_DTO_FIELD_DEFAULT(String, workstationAddress, ZH_WORDS_GETTER("workstation.fields.workstationAddress"));
	//所在车间的名称
	API_DTO_FIELD_DEFAULT(String, workshopName, ZH_WORDS_GETTER("workstation.fields.workshopName"));
	//所属工序（工序名称）
	API_DTO_FIELD_DEFAULT(String, processName, ZH_WORDS_GETTER("workstation.fields.processName"));
	//是否启用—带默认值'Y'
	API_DTO_FIELD(String, enableFlag, ZH_WORDS_GETTER("workstation.fields.enableFlag"), true, "Y");
	//备注
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("workstation.fields.remark"), true, "");
	//线边库ID
	API_DTO_FIELD(UInt64, warehouseId, ZH_WORDS_GETTER("workstation.fields.warehouseId"), true, 11);
	//库区ID
	API_DTO_FIELD(UInt64, locationId, ZH_WORDS_GETTER("workstation.fields.locationId"), true, 12);
	//库位ID
	API_DTO_FIELD(UInt64, areaId, ZH_WORDS_GETTER("workstation.fields.areaId"), true, 13);
};

/**
 *  获取工作站列表数据模型
 */
class GetWorkStationListDTO : public oatpp::DTO
{
	DTO_INIT(GetWorkStationListDTO, DTO);
	// 唯一标识（工作站ID）
	API_DTO_FIELD_DEFAULT(UInt64, workstationId, ZH_WORDS_GETTER("workstation.fields.workstationId"));
	// 工作站编号
	API_DTO_FIELD_DEFAULT(String, workstationCode, ZH_WORDS_GETTER("workstation.fields.workstationCode"));
	//工作站名称
	API_DTO_FIELD_DEFAULT(String, workstationName, ZH_WORDS_GETTER("workstation.fields.workstationName"));
	// 工作站地点
	API_DTO_FIELD_DEFAULT(String, workstationAddress, ZH_WORDS_GETTER("workstation.fields.workstationAddress"));
	//所在车间的名称
	API_DTO_FIELD_DEFAULT(String, workshopName, ZH_WORDS_GETTER("workstation.fields.workshopName"));
	//所属工序（工序名称）
	API_DTO_FIELD_DEFAULT(String, processName, ZH_WORDS_GETTER("workstation.fields.processName"));
	//是否启用—带默认值'Y'
	API_DTO_FIELD(String, enableFlag, ZH_WORDS_GETTER("workstation.fields.enableFlag"), true, "Y");
	//备注
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("workstation.fields.remark"), true, "");
};

/**
 * 定义一个工作站列表分页传输对象
 */
class GetWorkStationListPageDTO : public PageDTO<GetWorkStationListDTO::Wrapper>
{
	DTO_INIT(GetWorkStationListPageDTO, PageDTO<GetWorkStationListDTO::Wrapper>);
};

/**
 * 删除工作站
 */
class RemoveWorkStationDTO : public oatpp::DTO
{
	DTO_INIT(RemoveWorkStationDTO, DTO);
	// 唯一标识（工作站ID）
	API_DTO_FIELD_DEFAULT(List<UInt64>, workstationId, ZH_WORDS_GETTER("workstation.fields.workstationId"));

};

/**
 *  修改工作站数据模型
 */
class ModifyWorkStationDTO : public oatpp::DTO
{
	DTO_INIT(ModifyWorkStationDTO, DTO);
	// 唯一标识（工作站ID）
	API_DTO_FIELD_DEFAULT(UInt64, workstationId, ZH_WORDS_GETTER("workstation.fields.workstationId"));
	// 工作站编号
	API_DTO_FIELD_DEFAULT(String, workstationCode, ZH_WORDS_GETTER("workstation.fields.workstationCode"));
	// 工作站地点
	API_DTO_FIELD_DEFAULT(String, workstationAddress, ZH_WORDS_GETTER("workstation.fields.workstationAddress"));
	// 工作站名称
	API_DTO_FIELD_DEFAULT(String, workstationName, ZH_WORDS_GETTER("workstation.fields.workstationName"));
	// 所在车间的名称
	API_DTO_FIELD_DEFAULT(String, workshopName, ZH_WORDS_GETTER("workstation.fields.workshopName"));
	// 所属工序（工序名称）
	API_DTO_FIELD_DEFAULT(String, processName, ZH_WORDS_GETTER("workstation.fields.processName"));
	// 是否启用—带默认值'Y'
	API_DTO_FIELD(String, enableFlag, ZH_WORDS_GETTER("workstation.fields.enableFlag"), true, "Y");
	// 备注
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("workstation.fields.remark"), true, "");
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_