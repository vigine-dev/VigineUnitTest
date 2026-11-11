#include <vigine/unittest/unittest.h>

#include <vector>

namespace
{
class NumberListFixture : public vigine::unittest::Fixture
{
  protected:
    void SetUp() override { _numbers = {1, 2, 3}; }

    std::vector<int> _numbers;
};
} // namespace

VIGINE_TEST_F(NumberListFixture, StartsWithThreeNumbers)
{
    VIGINE_ASSERT_EQ(3U, _numbers.size());
    VIGINE_EXPECT_EQ(1, _numbers.front());
}

VIGINE_TEST_F(NumberListFixture, EachTestGetsItsOwnCopy)
{
    _numbers.push_back(4);
    VIGINE_EXPECT_EQ(4U, _numbers.size());
}
