# CMakeList.txt: test-jwt 的 CMake 项目，在此处包括源代码并定义项目特定的逻辑。

# 设置文件名称
set (tjwt test-jwt)

# 添加可执行文件
add_executable (${tjwt} "test-jwt.cpp")
if(WIN32)
	target_compile_definitions(${tjwt} PRIVATE -DCPP_JWT_USE_VENDORED_NLOHMANN_JSON)
endif()