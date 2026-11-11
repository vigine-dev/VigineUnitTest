# VigineUnitTest

Our test interface over googletest. Every Vigine repository writes its tests
with it, so the tests of all repositories look and behave the same and none of
them talks to googletest directly.

## What it does

- Holds googletest inside, as a submodule from the vigine-dev fork, pinned at
  the fork's `vigine/main` tip.
- Gives the Vigine repositories one place to ask for their test tools instead of
  each one pulling googletest in on its own.

The interface itself is not written yet; the folders `include/vigine/unittest`,
`src`, `test` and `cmake` are in place for it.

## How to use it

A repository does not take VigineUnitTest as a submodule. VigineUnitTest is
built once in its own folder and installed into `<vigine root>/install/<variant>`
(`~/vigine/install` on Mac and Ubuntu, `D:/work/project/install` on Windows). A
repository finds it there with `find_package(VigineUnitTest)` and writes its
tests with our interface; the interface comes in the next step. It never
includes googletest directly.

## How to build it

It is built by its recipe, `vigine.build.toml`, through the build step (the
recipe comes with the interface). The build goes into `build/debug` and
`build/release` with our compiler, and the result is installed into
`install/<variant>`.
