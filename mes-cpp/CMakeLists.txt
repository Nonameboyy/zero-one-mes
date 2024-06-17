# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

# 指定工程名
project ("zero-one-mes")

# 设置安装目录前缀
if(NOT WIN32)
	set (CMAKE_INSTALL_PREFIX "../install/${PROJECT_NAME}" CACHE PATH "install path prefix" FORCE )
endif()

# C++标准
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

# 判断构建类型
if ((NOT CMAKE_BUILD_TYPE) 
	OR (CMAKE_BUILD_TYPE STREQUAL "") 
	OR (CMAKE_BUILD_TYPE STREQUAL "Release")
	OR (CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo"))
	set (ZO_BT "r")
else()
	set (ZO_BT "d")
endif()

# 根据平台设置一些变量名
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
	message (STATUS "Platform is x64")
	set(ZO_LB_NAME "lib64")
else()
	message (STATUS "Platform is x86")
	set(ZO_LB_NAME "lib")
endif()
if(ZO_BT STREQUAL "r")
	message (STATUS "Build type is RELEASE")
	set(ZO_LBT_NAME "release")
	set(ZO_DY_DIR ${PROJECT_SOURCE_DIR}/lib-dy/${ZO_LB_NAME}/release)
else()
	message (STATUS "Build type is DEBUG")
	set(ZO_LBT_NAME "debug")
	set(ZO_DY_DIR ${PROJECT_SOURCE_DIR}/lib-dy/${ZO_LB_NAME}/debug)
endif()

# 添加公用宏定义
if (ZO_BT STREQUAL "r")
	add_definitions(-DOATPP_DISABLE_ENV_OBJECT_COUNTERS)
endif()
if (UNIX)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS)
	add_definitions(-DCPP_JWT_USE_VENDORED_NLOHMANN_JSON)
	add_definitions(-DLINUX)
	add_definitions(-DCHECK_TOKEN)
	add_definitions(-DSTOP_PWD="01star")
	add_definitions(-DOATPP_SWAGGER_SERVICE_NAME="${PROJECT_NAME} for linux")
	add_definitions(-DOATPP_SWAGGER_RES_PATH="res")
	add_definitions(-DBSONCXX_STATIC -DMONGOCXX_STATIC -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF)
else()
	add_definitions(-DOATPP_SWAGGER_SERVICE_NAME="${PROJECT_NAME} for windows")
	add_definitions(-DOATPP_SWAGGER_RES_PATH="res")
endif()

# 在camke .. 的时候会输出提示目录路径
message (STATUS "Prefix dir is ${CMAKE_INSTALL_PREFIX}")
message (STATUS "Binary dir is ${PROJECT_BINARY_DIR}")
message (STATUS "Source dir is ${PROJECT_SOURCE_DIR}")

# 判断是否是Ubuntu系统
option (IS_UBUNTU "is ubuntu" OFF)
cmake_host_system_information(RESULT PRETTY_NAME QUERY OS_VERSION)
if (${PRETTY_NAME} MATCHES "Ubuntu")
	option (IS_UBUNTU "is ubuntu" ON)
endif()

# Liunx环境库依赖检查
if (NOT WIN32)
	# 检查OpenSSL库是否存在
	find_package (OpenSSL REQUIRED)
	if (OPENSSL_FOUND)
	  include_directories (${OPENSSL_INCLUDE_DIRS})
	  message (STATUS "OpenSSL Found!")
	endif()
	# 检查CURL库是否存在
	find_package (CURL REQUIRED)
	if (CURL_FOUND)
	  include_directories (${CURL_INCLUDE_DIRS})
	  message (STATUS "CURL Found!")
	endif()
endif()

# 设置选项开关
option (USE_XLNT "use xlnt" ON)
option (USE_DFS "use fastdfs" ON)
option (USE_YML "use yaml" ON)
if (NOT WIN32)
	option (USE_NACOS "use nacos, need open yaml" ON)
endif()
option (USE_REDIS "use redis" ON)
option (USE_ROCKETMQ "use rocketmq" ON)
option (USE_MONGO "use mongodb" ON)
if (NOT WIN32)
	option (USE_ALISMS "use aliyun sms" ON)
endif()
option (USE_PDF "use libharu pdf" ON)

# 选项宏定义
# 为了保证排除后编译通过，在单独使用这些库的地方加上对应的宏定义
if (USE_XLNT)
	add_definitions(-DUSE_XLNT)
endif()
if (USE_DFS)
	add_definitions(-DUSE_DFS)
endif()
if (USE_YML)
	add_definitions(-DUSE_YML)
endif()
if (USE_NACOS)
	add_definitions(-DUSE_NACOS)
endif()
if (USE_REDIS)
	add_definitions(-DUSE_REDIS)
endif()
if (USE_ROCKETMQ)
	add_definitions(-DUSE_ROCKETMQ)
endif()
if (USE_MONGO)
	add_definitions(-DUSE_MONGO)
endif()
if (USE_ALISMS)
	add_definitions(-DUSE_ALISMS)
endif()
if (USE_PDF)
	add_definitions(-DUSE_PDF)
endif()

# 定义一个预编译标头宏
MACRO(ADD_MSVC_PRECOMPILED_HEADER PrecompiledHeader PrecompiledSource SourcesVar)
  IF(MSVC)
    GET_FILENAME_COMPONENT(PrecompiledBasename ${PrecompiledHeader} NAME_WE)
    SET(PrecompiledBinary "${CMAKE_CURRENT_BINARY_DIR}/${PrecompiledBasename}.pch")
    SET(Sources ${${SourcesVar}})
    SET_SOURCE_FILES_PROPERTIES(${PrecompiledSource}
                                PROPERTIES COMPILE_FLAGS "/Yc\"${PrecompiledHeader}\" /Fp\"${PrecompiledBinary}\""
                                           OBJECT_OUTPUTS "${PrecompiledBinary}")
    SET_SOURCE_FILES_PROPERTIES(${Sources}
                                PROPERTIES COMPILE_FLAGS "/Yu\"${PrecompiledHeader}\" /FI\"${PrecompiledHeader}\" /Fp\"${PrecompiledBinary}\""
                                           OBJECT_DEPENDS "${PrecompiledBinary}") 
    LIST(APPEND ${SourcesVar} ${PrecompiledSource})
  ENDIF(MSVC)
ENDMACRO(ADD_MSVC_PRECOMPILED_HEADER)

# 包含子项目
add_subdirectory ("lib-oatpp")
add_subdirectory ("lib-mysql")
add_subdirectory ("lib-common")
if(UNIX)
	add_subdirectory ("nacos-register")
endif()
# 单元测试模块
if(DEFINED UNIT_TEST)
	add_subdirectory ("arch-tests")
endif()
# 这是示例模块，后期可以不编译它
# add_subdirectory ("arch-demo")
# 在后面添加你的模块
add_subdirectory ("mes-c1-workstation")
add_subdirectory ("mes-c1-workfixture")
add_subdirectory ("mes-c1-equipmentmanagement")
add_subdirectory ("mes-c2-equipmentledger")
add_subdirectory ("mes-c2-inspection.maintenanceitems")
add_subdirectory ("mes-c2-inspection.maintenanceplan")
add_subdirectory ("mes-c2-repairorder")
add_subdirectory ("mes-c3-promanager")
add_subdirectory ("mes-c3-quamanager")
add_subdirectory ("mes-c4-prodmgmt")
add_subdirectory ("mes-c4-whmgmt")
add_subdirectory ("mes-c5-QualityControl")
add_subdirectory ("mes-c5-WarehouseManagement")
add_subdirectory ("mes-c6-quality")
add_subdirectory ("mes-c6-storage-product")
add_subdirectory ("mes-c6-storage-return")
add_subdirectory ("mes-c7-settings")
add_subdirectory ("mes-c7-rejection")
add_subdirectory ("mes-c7-storage")

