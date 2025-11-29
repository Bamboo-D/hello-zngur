add_executable(hello_zngur main.cpp)

add_dependencies(hello_zngur depends-rustlib)
target_link_libraries(hello_zngur PRIVATE ${RUST_LIB_NAME})
target_include_directories(hello_zngur PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(tests)