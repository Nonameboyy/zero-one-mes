# CMakeList.txt: test-mysql 的 CMake 项目，在此处包括源代码并定义项目特定的逻辑。

# 设置文件名称
set (tmysql test-mysql)

# 添加可执行文件
add_executable (${tmysql} "test-mysql.cpp")
# 链接库
target_link_libraries (${tmysql} mysqlcppconn)
if(UNIX)
	target_link_libraries (${tmysql} nacos-cli)
endif()