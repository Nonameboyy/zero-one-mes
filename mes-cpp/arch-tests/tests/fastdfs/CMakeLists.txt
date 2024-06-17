# CMakeList.txt: test-fastdfs 的 CMake 项目，在此处包括源代码并定义项目特定的逻辑。

# FastDfs单元测试
if(USE_DFS)
	# 设置文件名称
	set (tdfs test-fastdfs)
	# 添加可执行文件
	add_executable (${tdfs} "test-fastdfs.cpp")
	# 链接库
	if (UNIX)
		target_link_libraries (${tdfs} fdfsclient fastcommon nacos-cli)
	elseif(WIN32)
		target_compile_definitions(${tdfs} PRIVATE -D_HAS_STD_BYTE=0)
	endif()
	message (STATUS "${tdfs}: link fdfsclient lib")
endif()
