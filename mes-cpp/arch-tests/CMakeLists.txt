# CMakeList.txt: arch-tests 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 设置文件名称
set (appName arch-tests)

# 设置可执行文件输出目录为
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/${appName}/bin)

# 包含库目录
include_directories ("./")
include_directories ("../lib-oatpp/include")
include_directories ("../lib-mysql/include")
include_directories ("../lib-common/include")

# 链接库路径，程序运行的时候也在这里找
link_directories (${PROJECT_BINARY_DIR}/lib-oatpp)
link_directories (${PROJECT_BINARY_DIR}/lib-mysql)
link_directories (${PROJECT_BINARY_DIR}/lib-common)

# 如果是Linux环境
if(UNIX)
	link_directories (${PROJECT_SOURCE_DIR}/lib-common/lib64)
	link_directories (${PROJECT_SOURCE_DIR}/lib-oatpp/lib64)
	link_directories (${PROJECT_SOURCE_DIR}/lib-dy/lib64)
# 如果是Windows环境
elseif(WIN32)
	link_directories (${PROJECT_SOURCE_DIR}/lib-common/${ZO_LB_NAME}/${ZO_LBT_NAME})
	link_directories (${PROJECT_SOURCE_DIR}/lib-oatpp/${ZO_LB_NAME}/openssl)
	link_directories (${PROJECT_SOURCE_DIR}/lib-oatpp/${ZO_LB_NAME}/${ZO_LBT_NAME})
	link_directories (${PROJECT_SOURCE_DIR}/lib-mysql/${ZO_LB_NAME}/vs14/${ZO_LBT_NAME})
endif()

# 链接自定义静态库模块
link_libraries ("lib-common" "lib-oatpp" "lib-mysql")

# 链接其他系统库
if (UNIX)
	link_libraries (jsoncpp pthread stdc++fs OpenSSL::SSL CURL::libcurl)
else()
	link_libraries (libcrypto libssl ws2_32)
endif()
# 链接单元测试
link_libraries (gtest gtest_main)
# 链接Yaml
if(USE_YML)
	if(ZO_BT STREQUAL "r" OR UNIX)
		link_libraries (yaml-cpp )
	else()
		link_libraries (yaml-cppd )
	endif()
	message (STATUS "${appName}: link yamlcpp lib")
endif()

# 复制配置到调试时可执行文件所在的目录
# 中文词典
file (COPY "zh-dict.yaml" DESTINATION ${PROJECT_BINARY_DIR}/${appName}/bin)
# 模板文件目录
file (GLOB tplDir "tpl/*")
file (COPY ${tplDir} DESTINATION "${PROJECT_BINARY_DIR}/${appName}/bin/tpl")
# Ubuntu系统特殊处理
if(IS_UBUNTU)
	# 复制动态库到可执行文件目录
	file (GLOB dylibdir "${PROJECT_SOURCE_DIR}/lib-dy/lib64/*")
    file (COPY ${dylibdir} DESTINATION "${PROJECT_BINARY_DIR}/${appName}/bin")
endif()
# Windows平台特殊处理
if(WIN32)
	# 复制dll文件到可执行文件目录
	file (GLOB_RECURSE dycopy ${ZO_DY_DIR}/*.dll)
	file (COPY ${dycopy} DESTINATION "${PROJECT_BINARY_DIR}/${appName}/bin")
	# 复制项目配置到可执行文件目录
	file (GLOB conf "conf/*")
	file (COPY ${conf} DESTINATION ${PROJECT_BINARY_DIR}/${appName}/bin/conf)
endif()

# 添加单元测试子目录
add_subdirectory ("tests/jwt")
add_subdirectory ("tests/mysql")
add_subdirectory ("tests/rocketmq")
add_subdirectory ("tests/excel")
add_subdirectory ("tests/pdf")
add_subdirectory ("tests/mongo")
add_subdirectory ("tests/redis")
add_subdirectory ("tests/mail")
add_subdirectory ("tests/sms")
add_subdirectory ("tests/fastdfs")