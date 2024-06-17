# CMakeList.txt: test-rocket 的 CMake 项目，在此处包括源代码并定义项目特定的逻辑。

# RocketMQ单元测试
if(USE_ROCKETMQ)
	# 设置文件名称
	set (trocket test-rocket)
	# 添加可执行文件
	add_executable (${trocket} "test-rocket.cpp")
	# 链接库
	target_link_libraries (${trocket} oatpp )
	if (WIN32)
		target_link_libraries (${trocket} rocketmq-client-cpp )
		target_compile_definitions(${trocket} PRIVATE -DCPP_JWT_USE_VENDORED_NLOHMANN_JSON)
	else()
		target_link_libraries (${trocket} rocketmq nacos-cli)
	endif()
	message (STATUS "${trocket}: link rocketmq lib")
endif()