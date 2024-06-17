#include "stdafx.h"
#include "ModifyWhStorageorderController.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "../../../service/ProchAndStorage/MaterialsInfo/WhStorageorderService.h"

Uint64JsonVO::Wrapper ModifyWhStorageorderController::execModifyWhStorageorder(const ModifyWhStorageorderDTO::Wrapper& dto)
{
	//定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	//参数校验
//非空校验(对数据库中非空null参数)
	if (!dto || !dto->item_id || !dto->quantity_recived || !dto->line_id) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//必传的值不能为null
	if (!dto->iqc_check || !dto->warehouse_code || !dto->area_code || !dto->area_name || !dto->location_name
		|| !dto->item_code || !dto->item_name || !dto->warehouse_name || !dto->unit_of_measure || !dto->location_code) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//定义一个service
	WhStorageorderService service;

	//执行数据修改
	if (service.modifyWhStorageorder(dto)) {
		jvo->success(dto->line_id);
	}
	else
	{
		jvo->fail(dto->line_id);
	}
	//响应结果给前端
	return jvo;
}