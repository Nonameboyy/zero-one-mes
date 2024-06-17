/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/12/28 21:32:53

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
#ifdef USE_PDF

#include "pch.h"
#include "../include/PdfComponent.h"
#include "yaml-cpp/yaml.h"
#include "CharsetConvertHepler.h"
#include <iostream>

std::map<std::string, PdfTplRenderCf> PdfComponent::tplRender;

PdfComponent::PdfComponent()
{
	/**
	 * 异常处理函数，相关错误码定义在hpdf_error.h中
	 * 错误码信息参考：https://github.com/libharu/libharu/wiki/Error-handling
	 */
	auto fun = [](HPDF_STATUS error_no, HPDF_STATUS detail_no, void* user_data) {
		printf("ERROR: error_no=%04X, detail_no=%d\n", (unsigned int)error_no, (int)detail_no);
		/* throw exception on error */
		throw std::runtime_error("trigger hpdf_error_handler.");
		};
	_doc = HPDF_New(fun, NULL);
	if (!_doc)
	{
		throw std::runtime_error("error: cannot create PdfDoc object.");
	}
	_currPage = 0;
}

PdfComponent::~PdfComponent()
{
	if (_doc)
	{
		HPDF_Free(_doc);
	}
}

HPDF_Doc PdfComponent::getDoc() const
{
	return _doc;
}

HPDF_Page PdfComponent::getCurrPage() const
{
	return _currPage;
}

HPDF_Font PdfComponent::getBase14Font(const std::string& name)
{
	return HPDF_GetFont(_doc, name.c_str(), NULL);
}

HPDF_Font PdfComponent::getCnSFont(const std::string& name, bool isVertical /*= false*/)
{
	HPDF_UseCNSFonts(_doc);
	HPDF_UseCNSEncodings(_doc);
	const char* encoding = "GBK-EUC-H";
	if (isVertical)encoding = "GBK-EUC-V";
	return HPDF_GetFont(_doc, name.c_str(), encoding);
}

HPDF_Font PdfComponent::getCnTFont(bool isVertical /*= false*/)
{
	HPDF_UseCNTFonts(_doc);
	HPDF_UseCNTEncodings(_doc);
	const char* encoding = "ETen-B5-H";
	if (isVertical)encoding = "ETen-B5-V";
	return HPDF_GetFont(_doc, "MingLiU", encoding);
}

HPDF_Font PdfComponent::getTtFont(const std::string& fontPath, const std::string& encoding /*= "CP1252"*/)
{
	HPDF_UseUTFEncodings(_doc);
	HPDF_SetCurrentEncoder(_doc, encoding.c_str());
	const char* f = HPDF_LoadTTFontFromFile(_doc, fontPath.c_str(), HPDF_TRUE);
	return HPDF_GetFont(_doc, f, encoding.c_str());
}

HPDF_Page PdfComponent::getNewPage(HPDF_PageSizes pageSize /*= HPDF_PageSizes::HPDF_PAGE_SIZE_A4*/, HPDF_PageDirection direction /*= HPDF_PageDirection::HPDF_PAGE_PORTRAIT*/)
{
	_currPage = HPDF_AddPage(_doc);
	HPDF_Page_SetSize(_currPage, pageSize, direction);
	return _currPage;
}

void PdfComponent::drawText(const std::string& text, HPDF_REAL posx, HPDF_REAL posy, HPDF_Page page /*= 0*/)
{
	if (!page) page = _currPage;
	if (!page) return;
	HPDF_Page_BeginText(page);
	HPDF_Page_MoveTextPos(page, posx, posy);
	HPDF_Page_ShowText(page, CharsetConvertHepler::utf8ToGbk(text).c_str());
	HPDF_Page_EndText(page);
}

void PdfComponent::drawTextCenter(const std::string& text, HPDF_Page page /*= 0*/)
{
	if (!page) page = _currPage;
	HPDF_REAL posx, posy, tw, th;
	tw = HPDF_Page_TextWidth(page, CharsetConvertHepler::utf8ToGbk(text).c_str());
	th = HPDF_Page_GetCurrentFontSize(page);
	posx = (HPDF_Page_GetWidth(page) - tw) / 2;
	posy = (HPDF_Page_GetHeight(page) - th) / 2;
	drawText(text, posx, posy, page);
}

void PdfComponent::drawTextCenterH(const std::string& text, HPDF_REAL posy, HPDF_Page page /*= 0*/)
{
	if (!page) page = _currPage;
	HPDF_REAL posx, tw;
	tw = HPDF_Page_TextWidth(page, CharsetConvertHepler::utf8ToGbk(text).c_str());
	posx = (HPDF_Page_GetWidth(page) - tw) / 2;
	drawText(text, posx, posy, page);
}

void PdfComponent::drawTextCenterV(const std::string& text, HPDF_REAL posx, HPDF_Page page /*= 0*/)
{
	if (!page) page = _currPage;
	HPDF_REAL posy, th;
	th = HPDF_Page_GetCurrentFontSize(page);
	posy = (HPDF_Page_GetHeight(page) - th) / 2;
	drawText(text, posx, posy, page);
}

void PdfComponent::registerTplRender(const std::string& tplName, PdfTplRenderCf cf)
{
	tplRender.insert(std::make_pair(tplName, cf));
}

void PdfComponent::drawWithTemplate(const std::string& tplPath, const std::string& tplName, void* realData)
{
	// 判断是否存在注册模板
	auto itCf = tplRender.find(tplName);
	if (itCf == tplRender.end())
	{
		throw std::runtime_error("pdf render template not exist.");
	}
	try
	{
		// 加载模板配置文件
		auto tmplConf = YAML::LoadFile(tplPath);
		// 执行渲染
		itCf->second(&tmplConf, this, realData);
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}

bool PdfComponent::saveDocToFile(const std::string& fullPath)
{
	try
	{
		HPDF_SaveToFile(_doc, fullPath.c_str());
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
		return false;
	}
	return true;
}

#endif // USE_PDF