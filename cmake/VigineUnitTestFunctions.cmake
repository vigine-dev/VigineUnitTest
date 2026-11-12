include_guard(GLOBAL)
include(GoogleTest)

# vigine_unit_add_tests(<target> SOURCES <files...>)
# Makes the test program <target>, links vigine::unittest, lists its tests to ctest before each run, and sends
# the XML results to <build folder>/test-results (VIGINE_UNITTEST_RESULTS).
# On Windows a program does not start when a DLL it links lies in another folder, so each test also gets the folders
# of its runtime DLLs in front of PATH (the run), and the DLLs are copied beside the program after each build
# (ctest's discovery run cannot carry an environment: CMake 3.29's gtest_discover_tests runs the program in ctest's own).
function(vigine_unit_add_tests target)
    cmake_parse_arguments(PARSE_ARGV 1 unit "" "" "SOURCES")
    if(NOT unit_SOURCES)
        message(FATAL_ERROR "vigine_unit_add_tests(${target}): SOURCES lists no files")
    endif()
    if(unit_UNPARSED_ARGUMENTS)
        message(FATAL_ERROR "vigine_unit_add_tests(${target}): unknown arguments ${unit_UNPARSED_ARGUMENTS}")
    endif()
    set(resultsFolder "${CMAKE_BINARY_DIR}/test-results")
    set(extraTestProperties)
    file(MAKE_DIRECTORY "${resultsFolder}")
    add_executable(${target} ${unit_SOURCES})
    target_link_libraries(${target} PRIVATE vigine::unittest)
    if(WIN32)
        if(CMAKE_VERSION VERSION_LESS 3.27)
            message(FATAL_ERROR "vigine_unit_add_tests(${target}): on Windows it needs CMake 3.27 (TARGET_RUNTIME_DLL_DIRS), this is ${CMAKE_VERSION}")
        endif()
        set(runtimeDllFolders "$<TARGET_RUNTIME_DLL_DIRS:${target}>")
        set(extraTestProperties ENVIRONMENT_MODIFICATION
            "$<JOIN:$<LIST:TRANSFORM,${runtimeDllFolders},PREPEND,PATH=path_list_prepend:>,\\;>")
        add_custom_command(TARGET ${target} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E $<IF:$<BOOL:$<TARGET_RUNTIME_DLLS:${target}>>,copy_if_different,true>
                $<TARGET_RUNTIME_DLLS:${target}> $<TARGET_FILE_DIR:${target}>
            COMMAND_EXPAND_LISTS
            VERBATIM)
    endif()
    gtest_discover_tests(${target}
        DISCOVERY_MODE PRE_TEST
        PROPERTIES ENVIRONMENT "VIGINE_UNITTEST_RESULTS=${resultsFolder}" ${extraTestProperties})
endfunction()
