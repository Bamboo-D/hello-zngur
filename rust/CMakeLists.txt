set(RS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib.rs
    ${CMAKE_CURRENT_SOURCE_DIR}/src/types.rs
    ${CMAKE_CURRENT_SOURCE_DIR}/src/types/vec.rs
    ${CMAKE_CURRENT_SOURCE_DIR}/src/abstractions.rs
    ${CMAKE_CURRENT_SOURCE_DIR}/src/abstractions/traits.rs
)

set(ZNG_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/zng/lib.zng
    ${CMAKE_CURRENT_SOURCE_DIR}/zng/types.zng
    ${CMAKE_CURRENT_SOURCE_DIR}/zng/types/base.zng
    ${CMAKE_CURRENT_SOURCE_DIR}/zng/types/vec.zng
    ${CMAKE_CURRENT_SOURCE_DIR}/zng/abstractions.zng
    ${CMAKE_CURRENT_SOURCE_DIR}/zng/abstractions/traits.zng
)

add_custom_command(
    OUTPUT ${RUST_LIB}
    DEPENDS ${RS_SOURCES} ${ZNG_SOURCES}
    COMMAND ${CARGO_BUILD_CMD}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Building Rust..."
)

add_custom_target(depends-rustlib DEPENDS ${RUST_LIB})