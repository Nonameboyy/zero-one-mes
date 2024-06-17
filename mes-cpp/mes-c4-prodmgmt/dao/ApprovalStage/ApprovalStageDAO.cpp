#include "stdafx.h"
#include "ApprovalStageDAO.h"
#include "ApprovalStageMapper.h"
#include <sstream>

// �ύ���������������
int ApprovalStageDAO::SubmitForApproval(const ApprovalStageDO& uObj)
{
	string sql = "UPDATE `pro_feedback` SET `status`='DONE' WHERE `record_id`=?";
	return sqlSession->executeUpdate(sql, "%ull",  uObj.getc_record_id());
}
//����ͨ������������
int ApprovalStageDAO::ApprovalPassed(const ApprovalStageDO& uObj)
{
	string sql = "UPDATE `pro_feedback` SET `status`='COMPLETED'  WHERE `record_id`=?";
	return sqlSession->executeUpdate(sql, "%ull", uObj.getc_record_id());
}
//������ͨ����������ͨ����ݸ�
int ApprovalStageDAO::ApprovalNotPassed(const ApprovalStageDO& uObj)
{
	string sql = "UPDATE `pro_feedback` SET `status`='PREPARE' WHERE `record_id`=?";
	return sqlSession->executeUpdate(sql, "ull",  uObj.getc_record_id());
}