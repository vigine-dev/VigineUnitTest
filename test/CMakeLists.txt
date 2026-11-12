vigine_unit_add_tests(vigine_unittest_selftests SOURCES
    macros_expect.cpp
    macros_assert.cpp
    macros_compare.cpp
    fixture.cpp)

add_test(NAME results_land_in_the_folder
    COMMAND ${CMAKE_COMMAND}
        -DTEST_PROGRAM=$<TARGET_FILE:vigine_unittest_selftests>
        -DRESULTS_FOLDER=${CMAKE_BINARY_DIR}/test-results/xml-check
        -P ${CMAKE_CURRENT_SOURCE_DIR}/check_results.cmake)

add_subdirectory(dll_path_case)
