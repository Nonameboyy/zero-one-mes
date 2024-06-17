# CMakeList.txt: test-mongo 的 CMake 项目，在此处包括源代码并定义项目特定的逻辑。

# MongoDB单元测试
if(USE_MONGO)
	# 设置文件名称
	set (tmongo test-mongo)
	# 添加可执行文件
	add_executable (${tmongo} "test-mongo.cpp")
	# 链接库
	if (WIN32)
		target_link_libraries (${tmongo} bsoncxx mongocxx )
	else()
		target_link_libraries (${tmongo} bsoncxx bson-1.0 mongocxx mongoc-1.0 nacos-cli)
	endif()
	message (STATUS "${tmongo}: link mongodb lib")
endif()