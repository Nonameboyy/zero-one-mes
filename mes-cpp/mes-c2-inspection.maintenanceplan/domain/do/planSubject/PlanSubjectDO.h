#pragma once
/*
* 
*/
#ifndef _PLANSUBJECT_DO_
#define _PLANSUBJECT_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class PlanSubjectTableDO
{
	//id
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ��Ŀ���룬���ʿɿ�
protected: 
	string code;
public: 
	string getCode(void) const {return code;}
public: 
	void setCode(string var) {code = var;};
	//CC_SYNTHESIZE(string, code, Code);
	// ��Ŀ����
	CC_SYNTHESIZE(string, name, Name);
	// ��Ŀ����
	CC_SYNTHESIZE(string, type, Type);
	// ��Ŀ����
	CC_SYNTHESIZE(string, content, Content);
	// ��Ŀ��׼
	CC_SYNTHESIZE(string, standard, Standard);
public:
	PlanSubjectTableDO() {
		id = 0;
		code = "";
		name = "";
		type = "";
		content = "";
		standard = "";
	}
};

#endif // !_PLANSUBJECT_DO_
