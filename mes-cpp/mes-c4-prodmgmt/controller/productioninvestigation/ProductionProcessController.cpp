#include "ProductionProcessController.h"
#include "../../service/productioninvestigation/ProductionProcessService.h"
ProductionProcessPageJsonVO::Wrapper ProductionProcessController::execQueryProcess(const ProductionProcessQuery::Wrapper& query)
{
	// 定义一个Service
	ProductionProcessService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ProductionProcessPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
