# CMakeList.txt: test-mail 的 CMake 项目，在此处包括源代码并定义项目特定的逻辑。

# Mail单元测试
if(UNIX)
	# 设置文件名称
	set (tmail test-mail)
	# 添加可执行文件
	add_executable (${tmail} "test-mail.cpp")
	# 链接库
	target_link_libraries (${tmail} nacos-cli)
endif()