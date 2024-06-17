# CMakeList.txt: lib-oatpp 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 包含库目录
include_directories ("./")
include_directories ("include")

# 获取需要编译的源文件
file (GLOB_RECURSE SC_FILES src/*.cpp)

# 设置预编译标头
if(WIN32)
	ADD_MSVC_PRECOMPILED_HEADER("pch.h" "pch.cpp" SC_FILES)
endif()

# 生成静态库
add_library (lib-oatpp STATIC ${SC_FILES})

# 静态库输出名修改
set_target_properties (lib-oatpp PROPERTIES OUTPUT_NAME oatpp-http)
# 防止同名库被删除
set_target_properties (lib-oatpp PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# 安装库
install (TARGETS lib-oatpp ARCHIVE DESTINATION libstatic)
install (DIRECTORY include/ DESTINATION include/lib-oatpp)
