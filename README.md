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

A repository that needs tests takes VigineUnitTest as a submodule and links its
test target against it. Until the interface lands there is nothing to link yet.

## How to build it

```sh
git clone --recursive https://github.com/vigine-dev/VigineUnitTest.git
cmake -S VigineUnitTest -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build
```

Requires a C++23 compiler.
