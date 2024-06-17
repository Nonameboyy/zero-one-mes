# CMakeList.txt: test-redis 的 CMake 项目，在此处包括源代码并定义项目特定的逻辑。

# Redis单元测试
if(USE_REDIS)
	# 设置文件名称
	set (tredis test-redis)
	# 添加可执行文件
	add_executable (${tredis} "test-redis.cpp")
	# 链接库
	target_link_libraries (${tredis} redis++ hiredis)
	if(UNIX)
		target_link_libraries (${tredis} nacos-cli)
	endif()
	message (STATUS "${tredis}: link redis lib")
endif()