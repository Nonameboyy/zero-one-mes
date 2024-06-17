#include "stdafx.h"
#include "WarehouseDeleteService.h"
#include "../../dao/WarehouseDelete/WarehouseDeleteDAO.h"

bool WarehouseDeleteService::WarehouseDelete(const WarehouseDeleteDTO::Wrapper& dto)
{
	std::vector<uint64_t> recpt_id;
	for (const auto& id : *(dto->recpt_id)) {
		recpt_id.push_back(id);
	}
	WarehouseDeleteDAO dao;
	return dao.deleteById(recpt_id) == 1;
}