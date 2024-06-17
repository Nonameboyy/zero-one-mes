#include "stdafx.h"
#include "DetectionTemplateService.h"
#include "../../dao/DetectionTemplate/DetectionTemplateDAO.h"
#include "../../domain/dto/DetectionTemplate/DetectionTemplateDTO.h"
#include "../../domain/do/DetectionTemplate/DetectionTemplateDO.h"

bool DetectionTemplateService::RemoveDetectionTemplateData(uint64_t template_id)
{
	DetectionTemplateDAO dao;
	return dao.deleteBydetectiontemplateId(template_id) == 1;
	return true;
}

DetectionTemplatePageDTO::Wrapper DetectionTemplateService::listAllTemplateList(const DetectionTemplateQuery::Wrapper& query) {
	// �������ض���
	auto pages = DetectionTemplatePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	DetectionTemplateDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<DetectionTemplateDO> result = dao.selectTemplateListWithPage(query);
	// ��DOת����DTO
	for (DetectionTemplateDO sub : result) {
		auto dto = DetectionTemplateDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, template_code, Template_Code, template_name, Template_Name, qc_types, Qc_Types, enable_flag, Enable_Flag);
		pages->addData(dto);
	}
	return pages;
	return {};
}

uint64_t DetectionTemplateService::saveData(const DetectionTemplateDTO::Wrapper& dto)
{
	// ��װDO����
	DetectionTemplateDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Template_Id, template_id, Template_Code, template_code, Template_Name, template_name)
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Qc_Types, qc_types)
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Enable_Flag, enable_flag, Remark, remark)
	// ִ���������
	DetectionTemplateDAO dao;
	return dao.insert(data);
}

bool DetectionTemplateService::update(const DetectionTemplateDTO::Wrapper& dto)
{
	DetectionTemplateDAO dao;
	DetectionTemplateDO sub;
	//dtoת��do
	//ZO_STAR_DOMAIN_DTO_TO_DO(sub, dto, Template_Code,template_code, Template_Name, template_name, Qc_Types, qc_types, Enable_Flag, enable_flag, Remark,  remark);
	sub.setTemplate_Id(dto->template_id);
	sub.setTemplate_Code(dto->template_code);
	sub.setTemplate_Name(dto->template_name);
	sub.setQc_Types(dto->qc_types);
	sub.setEnable_Flag(dto->enable_flag);
	sub.setRemark(dto->remark);
	return dao.update(sub);
}

DetectionTemplatePageDTO::Wrapper DetectionTemplateService::queryDetecTempDetails(const string& template_code) {
	// �������ض���
	auto pages = DetectionTemplatePageDTO::createShared();
	// ��ѯ����
	DetectionTemplateDAO dao;
	list<DetectionTemplateDO> result = dao.selectByTemplate_code(template_code);
	// ��DOת����DTO
	for (DetectionTemplateDO sub : result)
	{
		auto dto = DetectionTemplateDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, template_code, Template_Code, template_name, Template_Name, qc_types, Qc_Types, enable_flag, Enable_Flag, remark, Remark)
		pages->addData(dto);
	}
	return pages;
}