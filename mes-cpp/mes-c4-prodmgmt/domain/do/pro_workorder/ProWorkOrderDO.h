#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: amie
 @Date: 2022/10/25 11:52:32

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
#ifndef _ProWorkOrder_DO_
#define _ProWorkOrder_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class ProWorkOrderDO
{
	CC_SYNTHESIZE(string, workorder_code, workOrderCode);
	CC_SYNTHESIZE(string, workorder_name,workOrderName);
	CC_SYNTHESIZE(string, workorder_type,workOrderType);
	CC_SYNTHESIZE(string, order_source,orderSource);
	CC_SYNTHESIZE(string, source_code,sourceCode);
	CC_SYNTHESIZE(int,product_id, productId);
	CC_SYNTHESIZE(string, product_code, productCode);
	CC_SYNTHESIZE(string, product_name, productName);
	CC_SYNTHESIZE(string, product_spc, productSpc);
	CC_SYNTHESIZE(string, unit_of_measure, unitOfMeasure);
	CC_SYNTHESIZE(string, batch_code, batchCode);
	CC_SYNTHESIZE(double, quantity, pQuantity);
	CC_SYNTHESIZE(double, quantity_produced, quantityProduced);
	CC_SYNTHESIZE(double, quantity_changed, quantityChanged);
	CC_SYNTHESIZE(double, quantity_scheduled, quantityScheduled);
	CC_SYNTHESIZE(int, client_id, clientId);
	CC_SYNTHESIZE(string, client_code, clientCode);
	CC_SYNTHESIZE(string, client_name, clientName);
	CC_SYNTHESIZE(int, vendor_id, vendorId);
	CC_SYNTHESIZE(string, vendor_code, vendorCode);
	CC_SYNTHESIZE(string, vendor_name, vendorName);
	CC_SYNTHESIZE(string, finish_date, finishDate);
	CC_SYNTHESIZE(string, request_date, requestDate);
	CC_SYNTHESIZE(string, status, status);
public:
	ProWorkOrderDO() {
		workorder_code = "";
		workorder_name = "";
		workorder_type = "";
		order_source = "";
		source_code = "";
		product_id = 0;
		product_code = "";
		product_name = "";
		product_spc = "";
		unit_of_measure = "";
		batch_code = "";
		quantity = 0.0;
		quantity_produced = 0.0;
		quantity_changed = 0.0;
		quantity_scheduled = 0.0;
		client_id = 0;
		client_code = "";
		client_name = "";
		vendor_id = 0;
		vendor_code = "";
		vendor_name = "";
		finish_date = "";
		request_date = "";
		status = "";
	}
};

#endif // !_ProWorkOrderBom_DO_
