enable_testing()

function(add_cpp_test cpp_path)
    string(REPLACE "/" "_" tmp ${cpp_path})
    get_filename_component(tmp ${tmp} NAME_WE)
    set(test_name "test_${tmp}")

    add_executable(${test_name} "${cpp_path}")
    target_link_libraries(${test_name} PRIVATE ${RUST_LIB_NAME})
    target_include_directories(${test_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
    add_test(NAME ${test_name} COMMAND ${test_name})
endfunction()

add_cpp_test("types/vec.cpp")
add_cpp_test("types/string.cpp")
add_cpp_test("types/result.cpp")
add_cpp_test("abstractions/traits.cpp")