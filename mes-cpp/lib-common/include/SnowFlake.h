#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/11/02 14:35:47

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
#ifndef _SNOWFLAKE_H_
#define _SNOWFLAKE_H_
#include <stdint.h>
#include <mutex>

/**
 * ѩ��ID���ɹ���
 * ʹ��ʾ����
 * ����ʾ������10��ID
 * SnowFlake sf(1, 1);
 * for (int i = 0; i < 10; i++)
 *	std::cout << sf.nextId() << std::endl;
 */
class SnowFlake
{
private:
	// ��ʼʱ�������һ�����ֵ
	static const uint64_t m_start_time_stamp = 1480166465631;
	// ���к�ռ��λ��
	static const uint64_t m_sequence_bit = 12;
	// ����IDռ��λ��
	static const uint64_t m_machine_bit = 5;
	// ���ݱ�ʶռ��λ��
	static const uint64_t m_datacenter_bit = 5;

	// ��ȡλ�������ֵ
	static const uint64_t m_max_datacenter_num = -1 ^ (uint64_t(-1) << m_datacenter_bit);
	static const uint64_t m_max_machine_num = -1 ^ (uint64_t(-1) << m_machine_bit);
	static const uint64_t m_max_sequence_num = -1 ^ (uint64_t(-1) << m_sequence_bit);

	// �±�
	static const uint64_t m_machine_left = m_sequence_bit;// ����ID������12λ
	static const uint64_t m_datacenter_left = m_sequence_bit + m_machine_bit;// ���ݱ�ʶID������17λ(12+5)
	static const uint64_t m_timestamp_left = m_sequence_bit + m_machine_bit + m_datacenter_bit; // ʱ���������22λ(5+5+12)

	// ��������ID(0~31)
	uint64_t m_datacenterId;
	// ��������ID(0~31)
	uint64_t m_machineId;
	// ����������(0~4095)
	uint64_t m_sequence;
	// �ϴ�����ID��ʱ���
	uint64_t m_last_time_stamp;
	// ��ʶ�Ƿ��ʼ�����
	bool m_is_init;
	// �߳���
	std::mutex m_mtx;
	// ����µ�ʱ���
	uint64_t getNextMill();
	// �����Ժ���Ϊ��λ�ĵ�ǰʱ��
	uint64_t getNewTimeStamp();
public:
	//************************************
	// Method:    SnowFlake
	// FullName:  SnowFlake::SnowFlake
	// Access:    public 
	// Returns:   
	// Description: �����ʼ��
	// Parameter: int datacenterId ��������ID (0~31)
	// Parameter: int machineId ��������ID(0~31)
	//************************************
	SnowFlake(int datacenterId, int machineId);

	//************************************
	// Method:    nextId
	// FullName:  SnowFlake::nextId
	// Access:    public 
	// Returns:   uint64_t ���ؼ��������ID������0��ʾ����IDʧ��
	// Description: ��ȡ��һ��ID
	//************************************
	uint64_t nextId();
};


#endif // _SNOWFLAKE_H_
