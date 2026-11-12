include(GenerateExportHeader)

add_library(vigine_dllpath_probe SHARED dllpathprobe.cpp)
generate_export_header(vigine_dllpath_probe BASE_NAME dllpathprobe)
target_include_directories(vigine_dllpath_probe PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR})
set_target_properties(vigine_dllpath_probe PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/out
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/out)
