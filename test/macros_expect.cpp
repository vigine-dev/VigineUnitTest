#include <vigine/unittest/unittest.h>

#include <stdexcept>

VIGINE_TEST(ExpectFamily, TrueAndFalse)
{
    VIGINE_EXPECT_TRUE(1 + 1 == 2);
    VIGINE_EXPECT_FALSE(1 + 1 == 3);
}

VIGINE_TEST(ExpectFamily, Comparisons)
{
    VIGINE_EXPECT_EQ(4, 2 + 2);
    VIGINE_EXPECT_NE(4, 5);
    VIGINE_EXPECT_LT(1, 2);
    VIGINE_EXPECT_LE(2, 2);
    VIGINE_EXPECT_GT(3, 2);
    VIGINE_EXPECT_GE(3, 3);
}

VIGINE_TEST(ExpectFamily, Near)
{
    VIGINE_EXPECT_NEAR(1.0, 1.05, 0.1);
}

VIGINE_TEST(ExpectFamily, Throws)
{
    VIGINE_EXPECT_THROW(throw std::runtime_error("failure"), std::runtime_error);
    VIGINE_EXPECT_NO_THROW(static_cast<void>(1 + 1));
}
