cmake_minimum_required(VERSION 3.10)
project(hello-zngur VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23) # C++23 for std::expected; C++17 is enough if not using it.
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

# 如果是 Clang 且至少 C++23，使用 libc++
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_CXX_STANDARD GREATER_EQUAL 23)
    message(STATUS "Configuring Clang with libc++ for C++${CMAKE_CXX_STANDARD}")
    add_compile_options(-stdlib=libc++)
    add_link_options(-stdlib=libc++)
endif()

# 根据 CMake 生成变量设置 cargo 构建命令和目录
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CARGO_BUILD_CMD cargo build)
    set(TARGET_VERSION_DIR "debug")
else()
    set(CARGO_BUILD_CMD cargo build --release)
    set(TARGET_VERSION_DIR "release")
endif()

# 若为交叉编译，设置对应的目标目录
if(DEFINED ENV{CARGO_BUILD_TARGET})
    set(TARGET_VERSION_DIR "$ENV{CARGO_BUILD_TARGET}/${TARGET_VERSION_DIR}")
endif()

# 生成桥接文件和编译 rust 库
set(RUST_LIB_NAME "rust_lib")
set(RUST_LIB "${CMAKE_CURRENT_SOURCE_DIR}/rust/target/${TARGET_VERSION_DIR}/${CMAKE_STATIC_LIBRARY_PREFIX}${RUST_LIB_NAME}${CMAKE_STATIC_LIBRARY_SUFFIX}")
add_subdirectory(rust)
add_library(${RUST_LIB_NAME} STATIC IMPORTED) # 导入库作用域仅限当前目录及子目录
set_target_properties(${RUST_LIB_NAME} PROPERTIES
    IMPORTED_LOCATION ${RUST_LIB}
    INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/rust
)

if(MSVC)
    target_link_libraries(${RUST_LIB_NAME} INTERFACE ws2_32 userenv advapi32 shell32 bcrypt ncrypt crypt32 secur32 ntdll)
    target_link_options(${RUST_LIB_NAME} INTERFACE
        "$<$<CONFIG:Debug>:/NODEFAULTLIB:MSVCRT>"
        "$<$<CONFIG:Debug>:/DEFAULTLIB:MSVCRTD>"
    )
elseif(UNIX)
    target_link_libraries(${RUST_LIB_NAME} INTERFACE pthread m dl)
endif()

add_subdirectory(cpp)