#include <vigine/unittest/unittest.h>

#include <filesystem>
#include <iostream>
#include <string>

VIGINE_TEST(Helpers, CapturedStdoutHoldsWhatWasPrinted)
{
    vigine::unittest::captureStdout();
    std::cout << "printed line" << std::endl;
    const std::string printed = vigine::unittest::capturedStdout();
    VIGINE_EXPECT_EQ(std::string("printed line\n"), printed);
}

VIGINE_TEST(Helpers, UniqueTempDiffersOnEveryCall)
{
    const auto first  = vigine::unittest::uniqueTemp("case");
    const auto second = vigine::unittest::uniqueTemp("case");
    VIGINE_EXPECT_NE(first, second);
    VIGINE_EXPECT_EQ(0U, first.filename().string().rfind("case_", 0));
}

VIGINE_TEST(Helpers, UniqueTempKeepsTheExtensionLast)
{
    const auto path = vigine::unittest::uniqueTemp("store.json");
    VIGINE_EXPECT_EQ(std::string(".json"), path.extension().string());
    VIGINE_EXPECT_EQ(0U, path.filename().string().rfind("store_", 0));
}
