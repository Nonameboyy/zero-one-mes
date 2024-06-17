/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。ksw12355
 @Date: 2024/05/25 

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
#ifndef _MD_WORKSHOP_H_
#define _MD_WORKSHOP_H_

class MdWorkshopDO
{
		// 车间ID
		CC_SYNTHESIZE(uint64_t, workshop_id, WorkshopId)
		// 车间编码
		CC_SYNTHESIZE(std::string, workshop_code, WorkshopCode)
		// 车间名称
		CC_SYNTHESIZE(std::string, workshop_name, WorkshopName)
		// 备注
		CC_SYNTHESIZE(std::string, remark, Remark)
		// 预留字段 1 ~ 4
		CC_SYNTHESIZE(std::string, attr1, Attr1)
		CC_SYNTHESIZE(std::string, attr2, Attr2)
		CC_SYNTHESIZE(int, attr3, Attr3)
		CC_SYNTHESIZE(int, attr4, Attr4)
		// 创建者
		CC_SYNTHESIZE(std::string, create_by, CreateBy)
		// 创建时间
		CC_SYNTHESIZE(std::string, create_time, CreateTime)
		// 更新者
		CC_SYNTHESIZE(std::string, update_by, UpdateBy)
		// 更新时间
		CC_SYNTHESIZE(std::string, update_time, UpdateTime)
};

#endif // 