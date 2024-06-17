/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "ProdOrderController.h"
#include "../../service/ProdOrder/ProdOrderService.h"
#include "../ApiDeclarativeServicesHelper.h"

ProdOrderPageJsonVO::Wrapper ProdOrderController::execQueryProdOrder(const ProdOrderQuery::Wrapper& query, const PayloadDTO& payload)
{
	return {};
}

/*
ProdOrderQueryTreeJsonVO::Wrapper ProdOrderController::execQueryTreeProdOrder(const ProdOrderTreeQuery::Wrapper& query, const PayloadDTO& payload)
{
	return {};
}
*/

ProdOrderQueryTreeJsonVO::Wrapper ProdOrderController::execQueryTreeProdOrder(const PayloadDTO& payload) {
	return {};
}

ProdOrderAddJsonVO::Wrapper ProdOrderController::execAddProdOrder(const ProdOrderDTO::Wrapper& dto)
{
	return {};
}

/*
Uint64JsonVO::Wrapper ProdOrderController::execModifyProdOrder(const ProdOrderDTO::Wrapper& dto)
{
	return {};
}

Uint64JsonVO::Wrapper ProdOrderController::execRemoveProdOrder(const UInt64& id)
{
	return {};
}

ProdOrderJsonVO::Wrapper ProdOrderController::execQueryOne(const UInt64& id, const PayloadDTO& payload)
{
	return {};
}

ProdOrderPageJsonVO::Wrapper ProdOrderController::execQueryAll(const ProdOrderQuery::Wrapper& query, const PayloadDTO& payload)
{
	return {};
}
*/
