#pragma once

#include <gtest/gtest.h>

#include <string>

namespace vigine::unittest
{
using Fixture = ::testing::Test;

template <typename ParamType> using FixtureWithParam = ::testing::TestWithParam<ParamType>;

using ::testing::Values;
using ::testing::ValuesIn;
using ::testing::Range;
using ::testing::TestParamInfo;
using ::testing::AssertionResult;
using ::testing::AssertionSuccess;
using ::testing::AssertionFailure;

inline std::string currentTestName()
{
    const ::testing::TestInfo *info = ::testing::UnitTest::GetInstance()->current_test_info();
    return info != nullptr ? std::string(info->name()) : std::string();
}

inline int randomSeed() { return ::testing::UnitTest::GetInstance()->random_seed(); }

inline void captureStderr() { ::testing::internal::CaptureStderr(); }

inline std::string capturedStderr() { return ::testing::internal::GetCapturedStderr(); }
}

#define VIGINE_TEST(suite, name) TEST(suite, name)
#define VIGINE_TEST_F(fixture, name) TEST_F(fixture, name)

#define VIGINE_EXPECT_TRUE(condition) EXPECT_TRUE(condition)
#define VIGINE_EXPECT_FALSE(condition) EXPECT_FALSE(condition)
#define VIGINE_EXPECT_EQ(expected, actual) EXPECT_EQ(expected, actual)
#define VIGINE_EXPECT_NE(first, second) EXPECT_NE(first, second)
#define VIGINE_EXPECT_LT(first, second) EXPECT_LT(first, second)
#define VIGINE_EXPECT_LE(first, second) EXPECT_LE(first, second)
#define VIGINE_EXPECT_GT(first, second) EXPECT_GT(first, second)
#define VIGINE_EXPECT_GE(first, second) EXPECT_GE(first, second)
#define VIGINE_EXPECT_NEAR(first, second, tolerance) EXPECT_NEAR(first, second, tolerance)
#define VIGINE_EXPECT_FLOAT_EQ(first, second) EXPECT_FLOAT_EQ(first, second)
#define VIGINE_EXPECT_DOUBLE_EQ(first, second) EXPECT_DOUBLE_EQ(first, second)
#define VIGINE_EXPECT_STREQ(first, second) EXPECT_STREQ(first, second)
#define VIGINE_EXPECT_STRNE(first, second) EXPECT_STRNE(first, second)
#define VIGINE_EXPECT_THROW(statement, exceptionType) EXPECT_THROW(statement, exceptionType)
#define VIGINE_EXPECT_NO_THROW(statement) EXPECT_NO_THROW(statement)

#define VIGINE_ASSERT_TRUE(condition) ASSERT_TRUE(condition)
#define VIGINE_ASSERT_FALSE(condition) ASSERT_FALSE(condition)
#define VIGINE_ASSERT_EQ(expected, actual) ASSERT_EQ(expected, actual)
#define VIGINE_ASSERT_NE(first, second) ASSERT_NE(first, second)
#define VIGINE_ASSERT_LT(first, second) ASSERT_LT(first, second)
#define VIGINE_ASSERT_LE(first, second) ASSERT_LE(first, second)
#define VIGINE_ASSERT_GT(first, second) ASSERT_GT(first, second)
#define VIGINE_ASSERT_GE(first, second) ASSERT_GE(first, second)
#define VIGINE_ASSERT_NEAR(first, second, tolerance) ASSERT_NEAR(first, second, tolerance)
#define VIGINE_ASSERT_FLOAT_EQ(first, second) ASSERT_FLOAT_EQ(first, second)
#define VIGINE_ASSERT_DOUBLE_EQ(first, second) ASSERT_DOUBLE_EQ(first, second)
#define VIGINE_ASSERT_STREQ(first, second) ASSERT_STREQ(first, second)
#define VIGINE_ASSERT_STRNE(first, second) ASSERT_STRNE(first, second)
#define VIGINE_ASSERT_THROW(statement, exceptionType) ASSERT_THROW(statement, exceptionType)
#define VIGINE_ASSERT_NO_THROW(statement) ASSERT_NO_THROW(statement)

#define VIGINE_TEST_P(fixture, name) TEST_P(fixture, name)
#define VIGINE_INSTANTIATE_TEST_SUITE_P(prefix, fixture, ...) INSTANTIATE_TEST_SUITE_P(prefix, fixture, __VA_ARGS__)
#define VIGINE_ALLOW_UNINSTANTIATED_PARAMETERIZED_TEST(fixture) GTEST_ALLOW_UNINSTANTIATED_PARAMETERIZED_TEST(fixture)

#define VIGINE_SKIP() GTEST_SKIP()
#define VIGINE_SUCCEED() SUCCEED()
#define VIGINE_ADD_FAILURE() ADD_FAILURE()
#define VIGINE_FAIL() FAIL()

#define VIGINE_HAS_DEATH_TEST GTEST_HAS_DEATH_TEST
#define VIGINE_EXPECT_DEATH(statement, pattern) EXPECT_DEATH(statement, pattern)
#define VIGINE_ASSERT_DEATH(statement, pattern) ASSERT_DEATH(statement, pattern)

#define VIGINE_EXPECT_NO_FATAL_FAILURE(statement) EXPECT_NO_FATAL_FAILURE(statement)
#define VIGINE_ASSERT_NO_FATAL_FAILURE(statement) ASSERT_NO_FATAL_FAILURE(statement)
