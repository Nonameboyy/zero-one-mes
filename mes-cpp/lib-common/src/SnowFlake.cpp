/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/11/02 14:37:39

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
#include "pch.h"
#include "../include/SnowFlake.h"
#include <thread>
#include <stdexcept>
#include <iostream>

uint64_t SnowFlake::getNextMill()
{
	uint64_t mill = getNewTimeStamp();
	while (mill <= m_last_time_stamp) {
		mill = getNewTimeStamp();
	}
	return mill;
}

uint64_t SnowFlake::getNewTimeStamp()
{
	auto t = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now());
	return t.time_since_epoch().count();
}

SnowFlake::SnowFlake(int datacenterId, int machineId)
{
	m_datacenterId = 0L;
	m_machineId = 0L;
	m_sequence = 0L;
	m_last_time_stamp = 0L;
	m_is_init = false;
	if ((uint64_t)datacenterId > m_max_datacenter_num || (uint64_t)datacenterId < 0) {
		std::cerr << "datacenterId can't be greater than max_datacenter_num_ or less than 0" << std::endl;
		return;
	}
	if ((uint64_t)machineId > m_max_machine_num || (uint64_t)machineId < 0) {
		std::cerr << "machineId can't be greater than max_machine_num_or less than 0" << std::endl;
		return;
	}
	m_datacenterId = datacenterId;
	m_machineId = machineId;
	m_is_init = true;
}

uint64_t SnowFlake::nextId()
{
	// �����ʼ�����󣬲�ִ�к����߼�
	if (!m_is_init) return 0;

	std::unique_lock<std::mutex> lock(m_mtx);
	uint64_t curTimeStamp = getNewTimeStamp();
	// �����ǰʱ��С����һ��ID���ɵ�ʱ�����˵��ϵͳʱ�ӻ��˹����ʱ��Ӧ���׳��쳣
	if (curTimeStamp < m_last_time_stamp) {
		std::cerr << "clock moved backwards. refusing to generate id" << std::endl;
		return 0;
	}
	// �����ͬһʱ�����ɵģ�����к���������
	if (curTimeStamp == m_last_time_stamp) {
		m_sequence = (m_sequence + 1) & m_max_sequence_num;
		// �������������
		if (m_sequence == 0) {
			// ��ȡ��һ������ʱ���
			curTimeStamp = getNextMill();
		}
	}
	// ʱ����ı䣬��������������
	else
	{
		m_sequence = 0;
	}
	// �����ϴ�����ID��ʱ���
	m_last_time_stamp = curTimeStamp;
	// ��λ��ͨ��������ƴ��һ�����64λ��ID
	return (curTimeStamp - m_start_time_stamp) << m_timestamp_left
		| m_datacenterId << m_datacenter_left
		| m_machineId << m_machine_left
		| m_sequence;
}
