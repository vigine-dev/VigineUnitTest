include_guard(GLOBAL)
include(GoogleTest)

# vigine_unit_add_tests(<target> SOURCES <files...>)
# Makes the test program <target>, links vigine::unittest, lists its tests to ctest before each run, and sends
# the XML results to <build folder>/test-results (VIGINE_UNITTEST_RESULTS).
function(vigine_unit_add_tests target)
    cmake_parse_arguments(PARSE_ARGV 1 unit "" "" "SOURCES")
    if(NOT unit_SOURCES)
        message(FATAL_ERROR "vigine_unit_add_tests(${target}): SOURCES lists no files")
    endif()
    if(unit_UNPARSED_ARGUMENTS)
        message(FATAL_ERROR "vigine_unit_add_tests(${target}): unknown arguments ${unit_UNPARSED_ARGUMENTS}")
    endif()
    set(resultsFolder "${CMAKE_BINARY_DIR}/test-results")
    file(MAKE_DIRECTORY "${resultsFolder}")
    add_executable(${target} ${unit_SOURCES})
    target_link_libraries(${target} PRIVATE vigine::unittest)
    gtest_discover_tests(${target}
        DISCOVERY_MODE PRE_TEST
        PROPERTIES ENVIRONMENT "VIGINE_UNITTEST_RESULTS=${resultsFolder}")
endfunction()
