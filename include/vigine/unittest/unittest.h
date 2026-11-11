#pragma once

#include <gtest/gtest.h>

namespace vigine::unittest
{
using Fixture = ::testing::Test;
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
#define VIGINE_ASSERT_THROW(statement, exceptionType) ASSERT_THROW(statement, exceptionType)
#define VIGINE_ASSERT_NO_THROW(statement) ASSERT_NO_THROW(statement)
