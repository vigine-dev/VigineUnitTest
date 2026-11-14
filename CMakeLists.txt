cmake_minimum_required(VERSION 3.25)

project(VigineUnitTest VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# googletest's options, every one stated:
#   BUILD_GMOCK ON          the mocking library is part of the interface.
#   INSTALL_GTEST OFF       we install googletest ourselves, into include/vigine/unittest/thirdparty.
#   gtest_force_shared_crt  ON: on Windows gtest links the DLL runtime (/MD), like the rest of the Vigine
#                           builds; a static runtime here would clash with theirs. No effect elsewhere.
#   gtest_disable_pthreads  OFF: threads stay on where the system has them.
#   gtest_hide_internal_symbols ON: matches the hidden visibility the recipe sets.
set(BUILD_GMOCK ON CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(gtest_disable_pthreads OFF CACHE BOOL "" FORCE)
set(gtest_hide_internal_symbols ON CACHE BOOL "" FORCE)
add_subdirectory(external/googletest EXCLUDE_FROM_ALL)

set(VIGINE_UNITTEST_THIRDPARTY_DIR ${CMAKE_INSTALL_INCLUDEDIR}/vigine/unittest/thirdparty)

# Our macros expand into googletest, so a consumer needs googletest's headers; they live only here.
foreach(googletestTarget gtest gmock)
    set_target_properties(${googletestTarget} PROPERTIES INTERFACE_INCLUDE_DIRECTORIES
        "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/external/googletest/googletest/include;${PROJECT_SOURCE_DIR}/external/googletest/googlemock/include>;$<INSTALL_INTERFACE:${VIGINE_UNITTEST_THIRDPARTY_DIR}>")
endforeach()

add_library(vigine_unittest STATIC src/unittestrun.cpp src/unittestmain.cpp)
add_library(vigine::unittest ALIAS vigine_unittest)
set_target_properties(vigine_unittest PROPERTIES EXPORT_NAME unittest)
target_include_directories(vigine_unittest PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")
target_link_libraries(vigine_unittest PUBLIC gtest gmock)

install(TARGETS vigine_unittest gtest gmock EXPORT VigineUnitTestTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES include/vigine/unittest/unittest.h include/vigine/unittest/main.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/vigine/unittest)
install(DIRECTORY external/googletest/googletest/include/gtest
    DESTINATION ${VIGINE_UNITTEST_THIRDPARTY_DIR})
install(DIRECTORY external/googletest/googlemock/include/gmock
    DESTINATION ${VIGINE_UNITTEST_THIRDPARTY_DIR})

set(VIGINE_UNITTEST_PACKAGE_DIR ${CMAKE_INSTALL_LIBDIR}/cmake/VigineUnitTest)
install(EXPORT VigineUnitTestTargets NAMESPACE vigine:: FILE VigineUnitTestTargets.cmake
    DESTINATION ${VIGINE_UNITTEST_PACKAGE_DIR})
configure_package_config_file(cmake/VigineUnitTestConfig.cmake.in
    ${PROJECT_BINARY_DIR}/VigineUnitTestConfig.cmake
    INSTALL_DESTINATION ${VIGINE_UNITTEST_PACKAGE_DIR})
write_basic_package_version_file(${PROJECT_BINARY_DIR}/VigineUnitTestConfigVersion.cmake
    COMPATIBILITY SameMajorVersion)
install(FILES
    ${PROJECT_BINARY_DIR}/VigineUnitTestConfig.cmake
    ${PROJECT_BINARY_DIR}/VigineUnitTestConfigVersion.cmake
    cmake/VigineUnitTestFunctions.cmake
    DESTINATION ${VIGINE_UNITTEST_PACKAGE_DIR})

include(cmake/VigineUnitTestFunctions.cmake)
enable_testing()
add_subdirectory(test)
