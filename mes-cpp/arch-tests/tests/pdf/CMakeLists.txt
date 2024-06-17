# CMakeList.txt: test-pdf 的 CMake 项目，在此处包括源代码并定义项目特定的逻辑。

# PDF单元测试
if(USE_PDF)
	# 设置文件名称
	set (tpdf test-pdf)
	# 添加可执行文件
	add_executable (${tpdf} "test-pdf.cpp")
	# 链接库
	if (UNIX)
		target_link_libraries (${tpdf} hpdf png16 z ZXing)
	else()
		target_link_libraries (${tpdf} hpdf ZXing)
		if(ZO_BT STREQUAL "r")
			target_link_libraries (${tpdf} libpng16 )
		else()
			target_link_libraries (${tpdf} libpng16d )
		endif()
	endif()
	message (STATUS "${tpdf}: link hpdf lib")
endif()