/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/04/07 22:08:19

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
#ifdef USE_XLNT

// xlnt使用需要的相关头文件
#include "Macros.h"
#include "ExcelComponent.h"

using namespace std;
#include "gtest/gtest.h"

/**
 * #TIP 注意事项：
 * Xlnt中的字符编码必须是utf-8所以不能再代码中出现中文字硬编码的形式;
 * 如果需要写中文，通过yaml配置文件的方式书写中文
 */
#define TEST_EXCEL_FN "./public/excel/1.xlsx"
#define TEST_EXCEL_SN ZH_WORDS_GETTER("excel.sheet.s1")

TEST(ExcelTest, TestWrite) {
	// 创建测试数据
	std::vector<std::vector<std::string>> data;
	std::string info = ZH_WORDS_GETTER("excel.content.info");
	stringstream ss;
	for (int i = 1; i <= 10; i++)
	{
		std::vector<std::string> row;
		for (int j = 1; j <= 5; j++)
		{
			ss.clear();
			ss << info << "(" << i << "," << j << ")";
			row.push_back(ss.str());
			ss.str("");
		}
		data.push_back(row);
	}

	// 定义保存数据位置和页签名称
	// 注意：文件件名称和文件路径不能出现中文
	std::string fileName = TEST_EXCEL_FN;
	// 注意：因为xlnt不能存储非utf8编码的字符，所以中文字需要从配置文件中获取
	std::string sheetName = TEST_EXCEL_SN;

	// 保存到文件
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);

	// 测试创建第二个页签
	sheetName = YamlHelper().getString(&zhDictNode, "excel.sheet.s2");
	excel.writeVectorToFile(fileName, sheetName, data);
}

TEST(ExcelTest, TestRead) {
	// 注意：因为xlnt不能存储非utf8编码的字符，所以中文字需要从配置文件中获取
	std::string sheetName = TEST_EXCEL_SN;
	// 从文件中读取
	ExcelComponent excel;
	auto readData = excel.readIntoVector(TEST_EXCEL_FN, sheetName);
	ASSERT_NE(readData.size(), 0);
	// 控制台打印读取数据
	for (auto row : readData)
	{
		for (auto cellVal : row)
		{
			cout << cellVal << ",";
		}
		cout << endl;
	}
}

TEST(ExcelTest, TestModify) {
	// 创建测试数据
	std::vector<std::vector<std::string>> data;
	std::string info = ZH_WORDS_GETTER("excel.content.info");
	stringstream ss;
	for (int i = 1; i <= 10; i++)
	{
		std::vector<std::string> row;
		for (int j = 1; j <= 5; j++)
		{
			ss.clear();
			ss << info << "(" << i << "," << j << ")";
			row.push_back(ss.str());
			ss.str("");
		}
		data.push_back(row);
	}
	// 插入表头
	data.insert(data.begin(), {
		ZH_WORDS_GETTER("excel.header.h1") ,
		ZH_WORDS_GETTER("excel.header.h2") ,
		ZH_WORDS_GETTER("excel.header.h3") ,
		ZH_WORDS_GETTER("excel.header.h4") ,
		ZH_WORDS_GETTER("excel.header.h5") ,
		});
	// 测试覆盖第一个页签
	ExcelComponent excel;
	excel.loadFile(TEST_EXCEL_FN);
	excel.writeVectorToFile(TEST_EXCEL_FN, TEST_EXCEL_SN, data);
}

#endif // USE_XLNT