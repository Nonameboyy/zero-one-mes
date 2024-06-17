/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 12:11:29
 
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
#include "../include/SqlSession.h"
#include <sstream>

void SqlSession::releasePreparedStatement()
{
	RELEASE_SQL_OBJECT(pstmt, "releasePreparedStatement");
}

void SqlSession::releaseStatement()
{
	RELEASE_SQL_OBJECT(stmt, "releaseStatement");
}

void SqlSession::releaseResultSet()
{
	RELEASE_SQL_OBJECT(res, "releaseResultSet");
}

int SqlSession::update(const string& sql, const char* fmt, va_list args)
{
	try
	{
		NULL_PTR_CHECK(conn, "connection is null");
		//1 ��ȡprepareStatement����
		pstmt = conn->prepareStatement(sql);
		//2 �������
		std::string curr(fmt);
		SQL_ARG_EXEC_1(pstmt, curr, args);
		//3 ִ�����ݲ���
		int row = pstmt->executeUpdate();
		//4 �ͷ�State
		releasePreparedStatement();
		return row;
	}
	catch (const std::exception& e)
	{
		//4 �ͷ�State
		releasePreparedStatement();
		cerr << "ExecuteUpdate Exception. " << e.what() << endl;
	}
	return 0;
}

SqlSession::SqlSession()
{
	this->conn = DbInit::getConnPool()->GetConnection();
	this->pstmt = NULL;
	this->stmt = NULL;
	this->res = NULL;
	//���ñ���
	this->setCharset("utf8");
}

SqlSession::~SqlSession()
{
	//�����ͷ����Ӷ���
	DbInit::getConnPool()->ReleaseConnection(conn);
}

bool SqlSession::execute(const string& sql)
{
	bool result = false;
	TryFinally(
		[&] {
			NULL_PTR_CHECK(conn, "connection is null");
			stmt = conn->createStatement();
			result = stmt->execute(sql);
		},
		[](const std::exception& e) {
			cerr << "Execute Exception. " << e.what() << endl;
		},
		[=] {
			releaseStatement();
		}
		);
	return result;
}

int SqlSession::executeUpdate(const string& sql, const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	int row = update(sql, fmt, args);
	va_end(args);
	return row;
}

int SqlSession::executeUpdate(const string& sql)
{
	return executeUpdate(sql, "");
}

int SqlSession::executeUpdate(const string& sql, const SqlParams& params)
{
	try
	{
		NULL_PTR_CHECK(conn, "connection is null");
		//1 ��ȡprepareStatement����
		pstmt = conn->prepareStatement(sql);
		//2 �������
		SQL_ARG_EXEC_3(params, pstmt);
		//3 ִ�����ݲ���
		int row = pstmt->executeUpdate();
		//4 �ͷ�State
		releasePreparedStatement();
		return row;
	}
	catch (const std::exception& e)
	{
		cerr << "ExecuteUpdate Exception. " << e.what() << endl;
		//4 �ͷ�State
		releasePreparedStatement();
	}
	return 0;
}

uint64_t SqlSession::executeInsert(const string& sql, const char* fmt, ...)
{
	//ִ�����ݲ���
	va_list args;
	va_start(args, fmt);
	int row = update(sql, fmt, args);
	va_end(args);

	//��ȡ����ID
	uint64_t id = 0;
	if (row == 1)
	{
		TryFinally(
			[&] {
				NULL_PTR_CHECK(conn, "connection is null");
				stmt = conn->createStatement();
				stmt->execute("SELECT LAST_INSERT_ID()");
				res = stmt->getResultSet();
				if (res->next()) {
					id = res->getInt64(1);
				}
			},
			[](const std::exception& e) {
				cerr << "Get Insert Id Exception. " << e.what() << endl;
			},
			[=] {
				releaseResultSet();
				releaseStatement();
			}
		);
	}
	return id;
}

uint64_t SqlSession::executeInsert(const string& sql)
{
	return executeInsert(sql, "");
}

uint64_t SqlSession::executeInsert(const string& sql, const SqlParams& params)
{
	//ִ�����ݲ���
	int row = executeUpdate(sql, params);

	//��ȡ����ID
	uint64_t id = 0;
	if (row == 1)
	{
		TryFinally(
			[&] {
				NULL_PTR_CHECK(conn, "connection is null");
				stmt = conn->createStatement();
				stmt->execute("SELECT LAST_INSERT_ID()");
				res = stmt->getResultSet();
				if (res->next()) {
					id = res->getInt64(1);
				}
			},
			[](const std::exception& e) {
				cerr << "Get Insert Id Exception. " << e.what() << endl;
			},
			[=] {
				releaseResultSet();
				releaseStatement();
			}
			);
	}
	return id;
}

uint64_t SqlSession::executeQueryNumerical(const string& sql, const char* fmt, ...)
{
	uint64_t result = 0;
	try
	{
		NULL_PTR_CHECK(conn, "connection is null");
		//1 ��ȡprepareStatement����
		pstmt = conn->prepareStatement(sql);
		//2 �������
		SQL_ARG_EXEC_2(pstmt, fmt);
		//3 ִ�в�ѯ
		res = pstmt->executeQuery();
		//4 �����ѯ���
		if (res->next()) {
			result = res->getUInt64(1);
		}
		//5 �ͷ���Դ
		releaseResultSet();
		releasePreparedStatement();
	}
	catch (const std::exception& e)
	{
		//5 �ͷ���Դ
		releaseResultSet();
		releasePreparedStatement();
		cerr << "ExecuteQuery Exception. " << e.what() << endl;
	}
	return result;
}

uint64_t SqlSession::executeQueryNumerical(const string& sql)
{
	return executeQueryNumerical(sql, "");
}

uint64_t SqlSession::executeQueryNumerical(const string& sql, const SqlParams& params)
{
	uint64_t result = 0;
	TryFinally(
		[&] {
			NULL_PTR_CHECK(conn, "connection is null");
			//1 ��ȡprepareStatement����
			pstmt = conn->prepareStatement(sql);
			//2 �������
			SQL_ARG_EXEC_3(params, pstmt);
			//3 ִ�в�ѯ
			res = pstmt->executeQuery();
			//4 �����ѯ���
			if (res->next()) {
				result = res->getUInt64(1);
			}
		},
		[](const std::exception& e) {
			cerr << "ExecuteQuery Exception. " << e.what() << endl;
		},
		[=] {
			//4 �ͷ���Դ
			releaseResultSet();
			releasePreparedStatement();
		}
	);
	return result;
}

bool SqlSession::setCharset(const std::string& charset)
{
	stringstream ss;
	ss << "set names '" << charset << "'";
	string sql = ss.str();
	return this->execute(sql);
}

void SqlSession::beginTransaction()
{
	if (conn)
	{
		conn->setAutoCommit(false);
	}
}

void SqlSession::commitTransaction()
{
	TryFinally(
		[=] {
			NULL_PTR_CHECK(conn, "connection is null");
			conn->commit();
		},
		[](const std::exception& e) {
			cerr << "Commit Exception. " << e.what() << endl;
		},
		[=] {
			if (conn)
			{
				conn->setAutoCommit(true);
			}
		}
	);
}

void SqlSession::rollbackTransaction()
{
	TryFinally(
		[=] {
			NULL_PTR_CHECK(conn, "connection is null");
			conn->rollback();
		},
		[](const std::exception& e) {
			cerr << "Rollback Exception. " << e.what() << endl;
		},
		[=] {
			if (conn)
			{
				conn->setAutoCommit(true);
			}
		}
	);
}
