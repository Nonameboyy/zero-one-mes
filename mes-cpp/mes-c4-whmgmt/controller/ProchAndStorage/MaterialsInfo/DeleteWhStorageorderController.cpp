#include "stdafx.h"
#include "DeleteWhStorageorderController.h"
#include "../../ApiDeclarativeServicesHelper.h"
#include "../../../service/ProchAndStorage/MaterialsInfo/WhStorageorderService.h"


//ִ��ɾ������
Uint64JsonVO::Wrapper DeleteWhStorageorderController::execDeleteWhStorageorder(const List<UInt64>& ids)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	//����У��
	if (!ids->empty()) {
		for (auto it = ids->begin(); it != ids->end(); it++) {
			if (*it <= 0) {
				jvo->init(UInt64(-1), RS_PARAMS_INVALID);
				return jvo;
			}
		}
	}
	else {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	//����һ��service
	WhStorageorderService service;
	//���б�ids�е�ÿ��idִ������ɾ��
	if (service.deleteWhStorageorder(ids)) {
		for (auto it = ids->begin(); it != ids->end(); ++it) {
			jvo->success(*it);
		}
	}
	else {
		for (auto it = ids->begin(); it != ids->end(); ++it) {
			jvo->fail(*it);
		}
	}
	//��Ӧ���
	return jvo;
}