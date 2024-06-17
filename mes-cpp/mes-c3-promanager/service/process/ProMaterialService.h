#pragma once
#ifndef _PROMATERIAL_SERVICE_
#define _PROMATERIAL_SERVICE_
#include <list>
#include "domain/vo/process/ProMaterialVO.h"
#include "domain/query/process/ProMaterialQuery.h"
#include "domain/dto/process/ProMaterialDTO.h"


/**
 * ��Ʒ�Ƴ����Ϸ���ʵ�֣���ʾ������ʾ������ʵ��
 */

class ProMaterialService
{
public:
	// ��ҳ��ѯ��������
	ProMaterialPageDTO::Wrapper listAll(const ProMaterialQuery::Wrapper& query);
};

#endif // !_PROMATERIAL_SERVICE_

