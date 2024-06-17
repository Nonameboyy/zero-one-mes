#pragma once
#ifndef _DETECTIONTEMPLATE_DAO_
#define _DETECTIONTEMPLATE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/DetectionTemplate/DetectionTemplateDO.h"
#include "../../domain/query/DetectionTemplate/DetectionTemplateQuery.h"
/**
 * 示例表数据库操作实现
 */
class DetectionTemplateDAO : public BaseDAO
{
public:

	// 通过ID删除检测模板
	int deleteBydetectiontemplateId(uint64_t template_id);
	// 统计检测模板数据条数
	uint64_t count(const DetectionTemplateQuery::Wrapper& query);
	 //检测模板列表函数, 分页查询数据
	list<DetectionTemplateDO> selectTemplateListWithPage(const DetectionTemplateQuery::Wrapper& query);
	 //插入数据
	uint64_t insert(const DetectionTemplateDO& iObj);
	//修改数据
	bool update(const DetectionTemplateDO& iObj);
	// 获取检验模板详情
	list<DetectionTemplateDO> selectByTemplate_code(string template_code);
};
#endif // !_Ddt_DAO_