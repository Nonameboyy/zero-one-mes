#include "stdafx.h"
#include "PlanSubjectController.h"
#include "../../service/planSubject/planSubjectService.h"
#include "../ApiDeclarativeServicesHelper.h"



	/*
	//return PlanSubjectTableJsonVO::Wrapper();
	
	
	// 定义一个Service
	PlanSubjectService service;

	
	// 查询数据
	auto result = service.listAll(query);

	
	// 响应结果
	auto jvo = PlanSubjectTablePageJsonVO::createShared();
	
	jvo->success(result);
	
	return {};
	//return jvo;
	*/
	


PlanSubjectTablePageJsonVO::Wrapper PlanSubjectController::execPlanSubjectTablePage(const PlanSubjectQuery::Wrapper& query, const PayloadDTO& payload)
{
	return {};
	//PlanSubjectTablePageJsonVO::Wrapper();
}

PlanSubjectDetailPageJsonVO::Wrapper PlanSubjectController::execPlanSubjectDetailPage(const PlanSubjectQuery::Wrapper& query)
{
	//return PlanSubjectDetailPageJsonVO::Wrapper();
	return {};
}

















//#include "stdafx.h"
//#include "PlanSubjectController.h"
//
//#include "Macros.h"
//#include "DbInit.h"
//#include "SqlSession.h"
//#include "TransactionManager.h"
//#include "LibTest.h"
//#include "NacosClient.h"
//
//#include "gtest/gtest.h"
//
//PlanSubjectTableJsonVO::Wrapper PlanSubjectController::execPlanSubjectTable(const PlanSubjectQuery::Wrapper& query)
//{
//	SqlSession sqlsession;
//
//	//return DeptTableJsonVO::Wrapper();
//	//query.createShared();
//	string qsql = "SELECT * FROM `lib_test` WHERE id=?";
//	string qfullSql = "SELECT * FROM `lib_test`";
//	LibTestMapper mapper;
//	list<LibTest> results = sqlsession.executeQuery<LibTest, LibTestMapper>(qsql, mapper, "cs", "2");
//	cout << "query id is 2:" << endl;
//	if (results.size() != 0) {
//		LibTest sub = results.front();
//		cout << sub.id << ":" << sub.first << "-" << sub.last << "-" << sub.age << endl;
//	}
//	cout << "query all:" << endl;
//	results = sqlsession.executeQuery<LibTest, LibTestMapper>(qfullSql, mapper);
//	for (LibTest sub : results)
//	{
//		cout << sub.id << ":" << sub.first << "-" << sub.last << "-" << sub.age << endl;
//	}
//
//	return {};
//}