#include <vigine/unittest/unittest.h>

#include <dllpathprobe.h>

VIGINE_TEST(DllPathCase, ALibraryInAnotherFolderIsFound)
{
    VIGINE_EXPECT_EQ(42, vigineDllPathProbeAnswer());
}
