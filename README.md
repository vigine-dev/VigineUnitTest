# VigineUnitTest

Our test interface over googletest. Every Vigine repository writes its tests
with it, so the tests of all repositories look and behave the same and none of
them talks to googletest directly.

## What it does

- Holds googletest inside, as a submodule from the vigine-dev fork, pinned at
  the fork's `vigine/main` tip.
- Gives the Vigine repositories one place to ask for their test tools instead of
  each one pulling googletest in on its own.

- Gives them the macros `VIGINE_TEST`, `VIGINE_TEST_F` and the `VIGINE_EXPECT_` and `VIGINE_ASSERT_` forms of
  `TRUE`, `FALSE`, `EQ`, `NE`, `LT`, `LE`, `GT`, `GE`, `NEAR`, `THROW` and `NO_THROW`, a fixture base
  `vigine::unittest::Fixture`, and a `main` of its own that fixes googletest's options (no colour, fixed order, XML
  results into the folder named by `VIGINE_UNITTEST_RESULTS`).
- Gives a CMake function, `vigine_unit_add_tests`, that makes the test program and lists its tests to ctest.

## How to use it

A repository does not take VigineUnitTest as a submodule. VigineUnitTest is
built once in its own folder and installed into `<vigine root>/install/<variant>`
(`~/vigine/install` on Mac and Ubuntu, `D:/work/project/install` on Windows). A
repository finds it there with `find_package(VigineUnitTest)` and writes its
tests with our interface. It never includes googletest directly; googletest's
headers are installed only under `include/vigine/unittest/thirdparty/`, because
the macros expand into them.

```cmake
find_package(VigineUnitTest REQUIRED)
enable_testing()
vigine_unit_add_tests(my_tests SOURCES one.cpp)
```

```cpp
#include <vigine/unittest/unittest.h>

VIGINE_TEST(Arithmetic, Addition)
{
    VIGINE_EXPECT_EQ(4, 2 + 2);
}
```

The test program's `main` comes from the library. The tests are listed to ctest
by discovery before each run, and the XML results go to `<build folder>/test-results`.

## How to build it

It is built by its recipe, `vigine.build.toml`, through the build step. The
recipe has two variants, `debug` and `release`, each built in `build/<variant>`
with our compiler by three steps: configure (Ninja, every setting explicit),
build, and test (`ctest --test-dir build/<variant> --output-junit
test-results/ctest.xml`, so the run is recorded in the passport). The result is
installed into `install/<variant>`.
