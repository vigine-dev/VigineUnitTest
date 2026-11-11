#include <gtest/gtest.h>

#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>
#include <system_error>

namespace
{
constexpr const char *resultsFolderVariable = "VIGINE_UNITTEST_RESULTS";
constexpr int refusedExitCode = 2;

// Returns false after printing why when the variable is set but does not name an existing folder.
bool applyResultsFolder()
{
    const char *folderText = std::getenv(resultsFolderVariable);
    if (folderText == nullptr)
    {
        return true;
    }
    const std::filesystem::path folder(folderText);
    std::error_code failure;
    if (folder.empty() || !std::filesystem::is_directory(folder, failure))
    {
        std::cerr << "vigine unittest: " << resultsFolderVariable << " is set to \"" << folderText
                  << "\", which is not an existing folder; create it or unset the variable\n";
        return false;
    }
    // A trailing separator makes googletest write <folder>/<test program name>.xml.
    const std::string folderWithSeparator = folder.generic_string() + "/";
    GTEST_FLAG_SET(output, "xml:" + folderWithSeparator);
    return true;
}

// Every option googletest decides by system, by terminal or by environment variable is stated here.
void applyFixedOptions()
{
    // Colour escape codes in a captured log or an XML consumer are noise; "auto" depends on the terminal.
    GTEST_FLAG_SET(color, "no");
    // The test order must be the same on every system and every run.
    GTEST_FLAG_SET(shuffle, false);
    GTEST_FLAG_SET(random_seed, 0);
    // A thrown exception is a failed test, never a crash, on every system (Windows would otherwise
    // default to structured exception handling of its own).
    GTEST_FLAG_SET(catch_exceptions, true);
    // Failures are reported and the run goes on; a debugger break is never triggered by the library.
    GTEST_FLAG_SET(break_on_failure, false);
    GTEST_FLAG_SET(throw_on_failure, false);
    // Disabled tests stay disabled.
    GTEST_FLAG_SET(also_run_disabled_tests, false);
    // Death tests re-run the program from scratch, so they behave the same with or without threads.
    GTEST_FLAG_SET(death_test_style, "threadsafe");
    // Values are printed as UTF-8 on every system, never as a locale code page.
    GTEST_FLAG_SET(print_utf8, true);
    // The same amount of stack in every failure message on every system.
    GTEST_FLAG_SET(stack_trace_depth, 100);
}
} // namespace

int main(int argc, char **argv)
{
    // The options are set before the command line is parsed, because googletest wires its XML writer while
    // parsing: they replace its defaults and its environment variables; a flag on the command line still wins.
    applyFixedOptions();
    if (!applyResultsFolder())
    {
        return refusedExitCode;
    }
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
