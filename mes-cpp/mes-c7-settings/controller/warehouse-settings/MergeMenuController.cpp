#include "stdafx.h"
#include "MergeMenuController.h"
#include "../../service/warehouse-setting/MergeMenuService.h"
#include "../ApiDeclarativeServicesHelper.h"

MergeMenuJsonVO::Wrapper MergeMenuController::executeQueryMergeMenu(const PayloadDTO& payload) {
	MergeMenuService service;
	auto result = service.listadress();
	auto jvo = MergeMenuJsonVO::createShared();
	for (auto one : result) {
		jvo->data->push_back(WarehouseCascadeDTO::Wrapper(dynamic_pointer_cast<WarehouseCascadeDTO>(one), WarehouseCascadeDTO::Wrapper::Class::getType()));
	}
	return jvo;
}

