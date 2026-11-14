#pragma once

namespace vigine::unittest
{
// Runs the tests of this program with the library's fixed options and results folder; a program with a main of its
// own calls it last, after what it must do before the tests.
int run(int argc, char **argv);
} // namespace vigine::unittest
