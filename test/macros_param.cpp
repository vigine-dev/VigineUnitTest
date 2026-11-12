#include <vigine/unittest/unittest.h>

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

namespace
{
class DoublingCase : public vigine::unittest::FixtureWithParam<int>
{
};

VIGINE_TEST_P(DoublingCase, DoublesTheValue)
{
    VIGINE_EXPECT_EQ(GetParam() * 2, GetParam() + GetParam());
}

VIGINE_INSTANTIATE_TEST_SUITE_P(Listed, DoublingCase, vigine::unittest::Values(1, 2, 3));
VIGINE_INSTANTIATE_TEST_SUITE_P(FromVector, DoublingCase, vigine::unittest::ValuesIn(std::vector<int>{4, 5}));
VIGINE_INSTANTIATE_TEST_SUITE_P(Counted, DoublingCase, vigine::unittest::Range(0, 3));

std::string nameOfCase(const vigine::unittest::TestParamInfo<int> &info)
{
    return "Number" + std::to_string(info.param);
}

VIGINE_INSTANTIATE_TEST_SUITE_P(Named, DoublingCase, vigine::unittest::Values(7, 8), nameOfCase);

class NeverInstantiatedCase : public vigine::unittest::FixtureWithParam<int>
{
};

VIGINE_TEST_P(NeverInstantiatedCase, HasNoValues) { VIGINE_FAIL() << "never runs"; }

VIGINE_ALLOW_UNINSTANTIATED_PARAMETERIZED_TEST(NeverInstantiatedCase);

void checkPositive(int value) { VIGINE_ASSERT_GT(value, 0); }

vigine::unittest::AssertionResult isEven(int value)
{
    if (value % 2 == 0)
    {
        return vigine::unittest::AssertionSuccess();
    }
    return vigine::unittest::AssertionFailure() << value << " is odd";
}
} // namespace

VIGINE_TEST(SkipFamily, SkipsWhenTheCaseDoesNotApply)
{
    VIGINE_SKIP() << "skipped on purpose";
    VIGINE_FAIL() << "not reached after a skip";
}

VIGINE_TEST(NoFatalFamily, WatchesAHelperThatChecks)
{
    VIGINE_EXPECT_NO_FATAL_FAILURE(checkPositive(3));
    VIGINE_ASSERT_NO_FATAL_FAILURE(checkPositive(4));
}

VIGINE_TEST(ResultFamily, SuccessAndFailureAreCountedAsWritten)
{
    VIGINE_SUCCEED();
    VIGINE_EXPECT_TRUE(isEven(4));
    VIGINE_EXPECT_FALSE(isEven(5));
    VIGINE_EXPECT_STREQ(isEven(5).failure_message(), "5 is odd");
    if (false)
    {
        VIGINE_ADD_FAILURE() << "kept out of reach";
    }
}

VIGINE_TEST(RunFamily, KnowsItsNameAndSeed)
{
    VIGINE_EXPECT_EQ(vigine::unittest::currentTestName(), "KnowsItsNameAndSeed");
    VIGINE_EXPECT_GE(vigine::unittest::randomSeed(), 0);
}

VIGINE_TEST(RunFamily, CapturesWhatIsWrittenToStderr)
{
    vigine::unittest::captureStderr();
    std::fputs("heard", stderr);
    VIGINE_EXPECT_EQ(vigine::unittest::capturedStderr(), "heard");
}

#if VIGINE_HAS_DEATH_TEST
VIGINE_TEST(DeathFamilyDeathTest, ExpectedDeathIsSeen)
{
    VIGINE_EXPECT_DEATH(
        {
            std::fputs("going down", stderr);
            std::exit(3);
        },
        "going down");
}

VIGINE_TEST(DeathFamilyDeathTest, AssertedDeathIsSeen)
{
    VIGINE_ASSERT_DEATH(
        {
            std::fputs("gone", stderr);
            std::exit(4);
        },
        "gone");
}
#endif
