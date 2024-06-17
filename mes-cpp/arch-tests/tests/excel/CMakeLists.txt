# CMakeList.txt: test-excel 的 CMake 项目，在此处包括源代码并定义项目特定的逻辑。

# Excel单元测试
if(USE_XLNT)
	# 设置文件名称
	set (texcel test-excel)
	# 添加可执行文件
	add_executable (${texcel} "test-excel.cpp")
	# 链接库
	if(ZO_BT STREQUAL "r" OR UNIX)
		target_link_libraries (${texcel} xlnt )
	else()
		target_link_libraries (${texcel} xlntd )
	endif()
	message (STATUS "${texcel}: link xlnt lib")
endif()