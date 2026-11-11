#include <vigine/unittest/unittest.h>

#include <stdexcept>

VIGINE_TEST(AssertFamily, TrueAndFalse)
{
    VIGINE_ASSERT_TRUE(1 + 1 == 2);
    VIGINE_ASSERT_FALSE(1 + 1 == 3);
}

VIGINE_TEST(AssertFamily, Comparisons)
{
    VIGINE_ASSERT_EQ(4, 2 + 2);
    VIGINE_ASSERT_NE(4, 5);
    VIGINE_ASSERT_LT(1, 2);
    VIGINE_ASSERT_LE(2, 2);
    VIGINE_ASSERT_GT(3, 2);
    VIGINE_ASSERT_GE(3, 3);
}

VIGINE_TEST(AssertFamily, Near)
{
    VIGINE_ASSERT_NEAR(1.0, 1.05, 0.1);
}

VIGINE_TEST(AssertFamily, Throws)
{
    VIGINE_ASSERT_THROW(throw std::runtime_error("failure"), std::runtime_error);
    VIGINE_ASSERT_NO_THROW(static_cast<void>(1 + 1));
}
