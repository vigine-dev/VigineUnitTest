#include <vigine/unittest/main.h>
#include <vigine/unittest/unittest.h>

VIGINE_TEST(OwnMain, TheTestsRunThroughTheEntry)
{
    VIGINE_EXPECT_EQ(2, 1 + 1);
}

int main(int argc, char **argv)
{
    return vigine::unittest::run(argc, argv);
}
