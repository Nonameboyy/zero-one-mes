#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 15:33:44
 
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
#ifndef _EXCELCOMPONENT_H_
#define _EXCELCOMPONENT_H_
#include <xlnt/xlnt.hpp>
#include <string>
#include <vector>
/**
 * Excel���
 * ע�⣺xlntֻ֧��xlsx�ļ���ʽ
 */
class ExcelComponent
{
private:
	xlnt::workbook wb;
	xlnt::worksheet sheet;
	// �и�
	double rowHeight = 20;
	// �п�
	double colWidth = 20;
	// ����Sheet
	void createSheet(const std::string& sheetName);
public:
	ExcelComponent();
	// �����и�
	void setRowHeight(double rowHeight);
	// �����п�
	void setColWidth(double colWidth);
	// ��չ�����
	void clearWorkbook();
	
	//************************************
	// Method:    readIntoVector
	// FullName:  ExcelComponent::readIntoVector
	// Access:    public 
	// Returns:   std::vector<std::vector<std::string>> ָ��ҳǩ���ݵĶ�άvector
	// Description: ��ȡָ���ļ�ָ��ҳǩ������
	// Parameter: const std::string & fileName �ļ����Ƶ�ȫ·����ע���ļ�·���ָ���ʹ��/
	// Parameter: const std::string & sheetName ҳǩ����
	//************************************
	std::vector<std::vector<std::string>> readIntoVector(const std::string& fileName, const std::string& sheetName);
	
	//************************************
	// Method:    writeVectorToFile
	// FullName:  ExcelComponent::writeVectorToFile
	// Access:    public 
	// Returns:   void
	// Description: �������ݵ�ָ��ҳǩ�������浽�ļ���
	// Parameter: const std::string & fileName �ļ����Ƶ�ȫ·����ע���ļ�·���ָ���ʹ��/
	// Parameter: const std::string & sheetName �������ݱ��浽��ҳǩ����
	// Parameter: const std::vector<std::vector<std::string>> & data �������������
	//************************************
	void writeVectorToFile(const std::string& fileName, const std::string& sheetName, const std::vector<std::vector<std::string>>& data);

	// ����ָ��Excel�ļ����ڴ�
	void loadFile(const std::string& filename);
};
#endif // _EXCELCOMPONENT_H_
