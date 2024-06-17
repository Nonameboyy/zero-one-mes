#pragma once
/*
* 
*/
#ifndef _PLANSUBJECT_DO_
#define _PLANSUBJECT_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class PlanSubjectTableDO
{
	//id
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 项目编码，本质可看
protected: 
	string code;
public: 
	string getCode(void) const {return code;}
public: 
	void setCode(string var) {code = var;};
	//CC_SYNTHESIZE(string, code, Code);
	// 项目名称
	CC_SYNTHESIZE(string, name, Name);
	// 项目类型
	CC_SYNTHESIZE(string, type, Type);
	// 项目内容
	CC_SYNTHESIZE(string, content, Content);
	// 项目标准
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
