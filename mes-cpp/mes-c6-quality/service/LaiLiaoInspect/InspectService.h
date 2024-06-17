#pragma once
#ifndef _INSPECT_SERVICE_
#define _INSPECT_SERVICE_
#include <list>
#include "domain/vo/LaiLiaoInspect/InspectVO.h"
#include "domain/query/LaiLiaoInspect/InspectQuery.h"
#include "domain/dto/LaiLiaoInspect/InspectDTO.h"

/**
 * ������Ϣ�ķ������
 */
class InspectService
{
public:
	// ��ҳ��ѯ���ϼ����б�
	InspectPageDTO::Wrapper listAll(const InspectQuery::Wrapper& query);
	// ��ҳ��ѯ���ϼ��������
	Inspect_detailDTO::Wrapper list_detailone(const uint64_t iqc_id);
	// ��������
	uint64_t saveData(const InspectDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const InspectDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
	//ȷ�ϼ��鵥
	bool Is_Ok(const Item_idDTO::Wrapper& dto);
	//��ɼ��鵥
	bool Finished(const Item_idDTO::Wrapper& dto);

	//�������鵥
	string exportTable(const Inspect_tableQuery::Wrapper& query);
};

#endif // !_INSPECT_SERVICE_
