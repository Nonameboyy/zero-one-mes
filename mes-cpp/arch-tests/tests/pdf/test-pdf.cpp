/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/04/08 11:02:33

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
#include <iostream>
#include "Macros.h"
#include "PdfComponent.h"

// 条形码码生成需要导入头文件
#include "zxing/MultiFormatWriter.h"
#include "zxing/CharacterSet.h"
#include "zxing/BitMatrix.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>
using namespace ZXing;

#include "gtest/gtest.h"

// 条形码在线预览 https://zxing-cpp.github.io/zxing-cpp/demo_writer.html
void addBarCodeToPdf(PdfComponent* pdf) {
	// 设置条码绘制相关参数
	int width = 200, height = 20; // 长宽
	int margin = 10; // 间距
	int eccLevel = 0; // ecc等级0 -10
	CharacterSet encoding = CharacterSet::UTF8; // 编码
	BarcodeFormat format = BarcodeFormatFromString("Code93"); //格式化类型
	// 定义条码中的内容
	std::string input = "11111111";
	// 条码临时保存位置
	std::string filepath = "tmp.jpg";
	try {
		// 生成图形
		auto writer = MultiFormatWriter(format).setMargin(margin).setEncoding(encoding).setEccLevel(eccLevel);
		BitMatrix matrix = writer.encode(input, width, height);
		auto bitmap = ToMatrix<uint8_t>(matrix);
		// 保存到文件
		int success = stbi_write_jpg(filepath.c_str(), bitmap.width(), bitmap.height(), 1, bitmap.data(), 0);
		// 绘制到PDF
		if (success)
		{
			// 加载图片文件
			HPDF_Image image = HPDF_LoadJpegImageFromFile(pdf->getDoc(), filepath.c_str());
			// 绘制图片到PDF中
			HPDF_UINT iw = HPDF_Image_GetWidth(image);
			HPDF_UINT ih = HPDF_Image_GetHeight(image);
			HPDF_Page_DrawImage(pdf->getCurrPage(), image, 30, 70, iw, ih);
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

TEST(PdfTest, TestText) {
	PdfComponent pdf;
	// 创建一个页面
	HPDF_Page newPage = pdf.getNewPage();
	// 设置页面字体
	HPDF_Page_SetFontAndSize(newPage, pdf.getCnSFont("SimSun"), 20);
	// 绘制字体
	pdf.drawTextCenterH(ZH_WORDS_GETTER("pdf.title"), HPDF_Page_GetHeight(newPage) - 20);
	pdf.drawTextCenter(ZH_WORDS_GETTER("pdf.content"));
	pdf.drawTextCenterH(ZH_WORDS_GETTER("pdf.foot"), 20);
	// 保存到文件
	ASSERT_EQ(pdf.saveDocToFile("test-text.pdf"), true);
}

TEST(PdfTest, TestTpl) {
	// 测试注册渲染模板
	PdfComponent::registerTplRender("test", [](YAML::Node* node, PdfComponent* pdf, void* realData) {
		// 创建一个页面
		HPDF_Page newPage = pdf->getNewPage();
		// 设置页面字体
		HPDF_Page_SetFontAndSize(newPage, pdf->getCnSFont("SimSun"), 20);
		// 绘制静态数据
		auto title = (*node)["t"].as<std::string>();
		auto foot = (*node)["f"].as<std::string>();
		pdf->drawTextCenterH(title, HPDF_Page_GetHeight(newPage) - 20);
		pdf->drawTextCenterH(foot, 20);
		// 绘制动态数据
		std::string content = static_cast<std::string*>(realData)->c_str();
		pdf->drawTextCenter(content);
		// 绘制一个条码
		addBarCodeToPdf(pdf);
		// 保存到文件
		pdf->saveDocToFile("test-tpl.pdf");
		});

	// 测试绘制
	PdfComponent pdf;
	auto content = ZH_WORDS_GETTER("pdf.content");
	pdf.drawWithTemplate("tpl/test.yaml", "test", &content);
}

#undef STB_IMAGE_WRITE_IMPLEMENTATION