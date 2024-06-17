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

// ��������������Ҫ����ͷ�ļ�
#include "zxing/MultiFormatWriter.h"
#include "zxing/CharacterSet.h"
#include "zxing/BitMatrix.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>
using namespace ZXing;

#include "gtest/gtest.h"

// ����������Ԥ�� https://zxing-cpp.github.io/zxing-cpp/demo_writer.html
void addBarCodeToPdf(PdfComponent* pdf) {
	// �������������ز���
	int width = 200, height = 20; // ����
	int margin = 10; // ���
	int eccLevel = 0; // ecc�ȼ�0 -10
	CharacterSet encoding = CharacterSet::UTF8; // ����
	BarcodeFormat format = BarcodeFormatFromString("Code93"); //��ʽ������
	// ���������е�����
	std::string input = "11111111";
	// ������ʱ����λ��
	std::string filepath = "tmp.jpg";
	try {
		// ����ͼ��
		auto writer = MultiFormatWriter(format).setMargin(margin).setEncoding(encoding).setEccLevel(eccLevel);
		BitMatrix matrix = writer.encode(input, width, height);
		auto bitmap = ToMatrix<uint8_t>(matrix);
		// ���浽�ļ�
		int success = stbi_write_jpg(filepath.c_str(), bitmap.width(), bitmap.height(), 1, bitmap.data(), 0);
		// ���Ƶ�PDF
		if (success)
		{
			// ����ͼƬ�ļ�
			HPDF_Image image = HPDF_LoadJpegImageFromFile(pdf->getDoc(), filepath.c_str());
			// ����ͼƬ��PDF��
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
	// ����һ��ҳ��
	HPDF_Page newPage = pdf.getNewPage();
	// ����ҳ������
	HPDF_Page_SetFontAndSize(newPage, pdf.getCnSFont("SimSun"), 20);
	// ��������
	pdf.drawTextCenterH(ZH_WORDS_GETTER("pdf.title"), HPDF_Page_GetHeight(newPage) - 20);
	pdf.drawTextCenter(ZH_WORDS_GETTER("pdf.content"));
	pdf.drawTextCenterH(ZH_WORDS_GETTER("pdf.foot"), 20);
	// ���浽�ļ�
	ASSERT_EQ(pdf.saveDocToFile("test-text.pdf"), true);
}

TEST(PdfTest, TestTpl) {
	// ����ע����Ⱦģ��
	PdfComponent::registerTplRender("test", [](YAML::Node* node, PdfComponent* pdf, void* realData) {
		// ����һ��ҳ��
		HPDF_Page newPage = pdf->getNewPage();
		// ����ҳ������
		HPDF_Page_SetFontAndSize(newPage, pdf->getCnSFont("SimSun"), 20);
		// ���ƾ�̬����
		auto title = (*node)["t"].as<std::string>();
		auto foot = (*node)["f"].as<std::string>();
		pdf->drawTextCenterH(title, HPDF_Page_GetHeight(newPage) - 20);
		pdf->drawTextCenterH(foot, 20);
		// ���ƶ�̬����
		std::string content = static_cast<std::string*>(realData)->c_str();
		pdf->drawTextCenter(content);
		// ����һ������
		addBarCodeToPdf(pdf);
		// ���浽�ļ�
		pdf->saveDocToFile("test-tpl.pdf");
		});

	// ���Ի���
	PdfComponent pdf;
	auto content = ZH_WORDS_GETTER("pdf.content");
	pdf.drawWithTemplate("tpl/test.yaml", "test", &content);
}

#undef STB_IMAGE_WRITE_IMPLEMENTATION