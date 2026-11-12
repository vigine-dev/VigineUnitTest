#include <vigine/unittest/unittest.h>

#include <string>

VIGINE_TEST(CompareFamily, FloatsEqualWithinFourUnitsInTheLastPlace)
{
    VIGINE_EXPECT_FLOAT_EQ(0.1F + 0.2F, 0.3F);
    VIGINE_ASSERT_FLOAT_EQ(1.5F, 1.5F);
}

VIGINE_TEST(CompareFamily, DoublesEqualWithinFourUnitsInTheLastPlace)
{
    VIGINE_EXPECT_DOUBLE_EQ(0.1 + 0.2, 0.3);
    VIGINE_ASSERT_DOUBLE_EQ(2.5, 2.5);
}

VIGINE_TEST(CompareFamily, CStringsEqual)
{
    const std::string text = "vigine";
    VIGINE_EXPECT_STREQ(text.c_str(), "vigine");
    VIGINE_ASSERT_STREQ("same", "same");
}

VIGINE_TEST(CompareFamily, CStringsDiffer)
{
    VIGINE_EXPECT_STRNE("one", "two");
    VIGINE_ASSERT_STRNE("one", "");
}
