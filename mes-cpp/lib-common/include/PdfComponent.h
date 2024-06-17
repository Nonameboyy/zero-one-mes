#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/12/28 21:31:30

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
#ifndef _PDFCOMPONENT_H_
#define _PDFCOMPONENT_H_

#ifdef LINUX
#include "haru/linux/hpdf.h"
#else
#include "haru/win/hpdf.h"
#endif
#include <string>
#include <functional>
#include "yaml-cpp/node/node.h"
#include <map>

class PdfComponent;
// ����һ��ģ����Ⱦ����
using PdfTplRenderCf = void(*)(YAML::Node*, PdfComponent*, void* realData);

/**
 * ��дһ��PDF��������ڷ�װlibharu�ⳣ�ò���
 * ע�⣺libharu����ϵ��ԭ�������½ǲ������Ͻ�
 */
class PdfComponent final
{
private:
	// �ĵ����
	HPDF_Doc _doc;
	// ��ǰҳ����
	HPDF_Page _currPage;
	// ��¼ע�����Ⱦģ��
	static std::map<std::string, PdfTplRenderCf> tplRender;
public:
	// �����ʼ��
	PdfComponent();
	// �����ͷ���Դ
	~PdfComponent();
	// ��ȡ�ĵ����
	HPDF_Doc getDoc() const;
	// ��ȡ��ǰҳ����
	HPDF_Page getCurrPage() const;
	//************************************
	// Method:    getBase14Font
	// FullName:  PdfComponent::getBase14Font
	// Access:    public 
	// Returns:   HPDF_Font
	// Description: ��ȡPDF����PBase14������������ο���https://github.com/libharu/libharu/wiki/Fonts
	// Parameter: const std::string& name ��������
	//************************************
	HPDF_Font getBase14Font(const std::string& name);
	//************************************
	// Method:    getCnSFont
	// FullName:  PdfComponent::getCnSFont
	// Access:    public 
	// Returns:   HPDF_Font
	// Description: ��ȡHaru�������ļ���������
	// Parameter: const std::string& name �������ƣ�Ŀǰ֧�֣�SimSun, SimHei
	// Parameter: bool isVertical �Ƿ�������ʾ
	//************************************
	HPDF_Font getCnSFont(const std::string& name, bool isVertical = false);
	//************************************
	// Method:    getCnTFont
	// FullName:  PdfComponent::getCnTFont
	// Access:    public 
	// Returns:   HPDF_Font
	// Description: ��ȡHaru�������ķ�����������Ŀǰֻ֧��һ�֣�MingLiU
	// Parameter: bool isVertical �Ƿ�������ʾ
	//************************************
	HPDF_Font getCnTFont(bool isVertical = false);
	//************************************
	// Method:    getTtFont
	// FullName:  PdfComponent::getTtFont
	// Access:    public 
	// Returns:   HPDF_Font
	// Description: ��ȡTTF����
	// Parameter: const std::string& fontPath �����ļ�ȫ·��
	// Parameter: const std::string& encoding �������ƣ�Ĭ��ΪCP1252
	//************************************
	HPDF_Font getTtFont(const std::string& fontPath, const std::string& encoding = "CP1252");
	//************************************
	// Method:    getNewPage
	// FullName:  PdfComponent::getNewPage
	// Access:    public 
	// Returns:   HPDF_Page
	// Description: ��ȡһ���µ�ҳ��
	// Parameter: HPDF_PageSizes pageSize ҳ���С��Ĭ��A4
	// Parameter: HPDF_PageDirection direction ҳ�淽��Ĭ������
	//************************************
	HPDF_Page getNewPage(HPDF_PageSizes pageSize = HPDF_PageSizes::HPDF_PAGE_SIZE_A4, HPDF_PageDirection direction = HPDF_PageDirection::HPDF_PAGE_PORTRAIT);
	//************************************
	// Method:    drawText
	// FullName:  PdfComponent::drawText
	// Access:    public 
	// Returns:   void
	// Description: ��������
	// Parameter: const std::string& text ��������
	// Parameter: HPDF_REAL posx x����
	// Parameter: HPDF_REAL posy y����
	// Parameter: HPDF_Page page ҳ������Ĭ��ֵΪ��ǰҳ����
	//************************************
	void drawText(const std::string& text, HPDF_REAL posx, HPDF_REAL posy, HPDF_Page page = 0);
	//************************************
	// Method:    drawTextCenter
	// FullName:  PdfComponent::drawTextCenter
	// Access:    public 
	// Returns:   void
	// Description: �������֣�������ҳ���о�����ʾ
	// Parameter: const std::string& text ��������
	// Parameter: HPDF_Page page ҳ������Ĭ��ֵΪ��ǰҳ����
	//************************************
	void drawTextCenter(const std::string& text, HPDF_Page page = 0);
	//************************************
	// Method:    drawTextCenterH
	// FullName:  PdfComponent::drawTextCenterH
	// Access:    public 
	// Returns:   void
	// Description: �������֣�������ˮƽ������ʾ
	// Parameter: const std::string& text ��������
	// Parameter: HPDF_REAL posy y����
	// Parameter: HPDF_Page page ҳ������Ĭ��ֵΪ��ǰҳ����
	//************************************
	void drawTextCenterH(const std::string& text, HPDF_REAL posy, HPDF_Page page = 0);
	//************************************
	// Method:    drawTextCenterV
	// FullName:  PdfComponent::drawTextCenterV
	// Access:    public 
	// Returns:   void
	// Description: �������֣������ִ�ֱ������ʾ
	// Parameter: const std::string& text ��������
	// Parameter: HPDF_REAL posx x����
	// Parameter: HPDF_Page page ҳ������Ĭ��ֵΪ��ǰҳ����
	//************************************
	void drawTextCenterV(const std::string& text, HPDF_REAL posx, HPDF_Page page = 0);
	//************************************
	// Method:    registerTplRender
	// FullName:  PdfComponent::registerTplRender
	// Access:    public static 
	// Returns:   void
	// Description: ע����Ⱦģ��
	// Parameter: const std::string& tplName ģ������
	// Parameter: PdfTplRenderCf cf ��Ⱦ�ص�����
	//************************************
	static void registerTplRender(const std::string& tplName, PdfTplRenderCf cf);
	//************************************
	// Method:    drawWithTemplate
	// FullName:  PdfComponent::drawWithTemplate
	// Access:    public 
	// Returns:   void
	// Description: ͨ��ģ�����
	// Parameter: const std::string& tplPath ģ�������ļ�
	// Parameter: const std::string& tplName ģ������
	// Parameter: void* realData ʵʱ�������ݣ����ڴ��ݶ�̬����
	//************************************
	void drawWithTemplate(const std::string& tplPath, const std::string& tplName, void* realData);
	//************************************
	// Method:    saveDocToFile
	// FullName:  PdfComponent::saveDocToFile
	// Access:    public 
	// Returns:   bool ����ɹ�����true
	// Description: �����ĵ����ļ�
	// Parameter: const std::string& fullPath �ļ�ȫ·��
	//************************************
	bool saveDocToFile(const std::string& fullPath);
};

#endif // !_PDFCOMPONENT_H_