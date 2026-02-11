#include "mfile.h"
#include <gtest/gtest.h>

TEST(mfile, filled_check) {
  mfile file;

  EXPECT_FALSE(file);

  try {
    // assumes base source directory
    file = mfile{"tests/main.cpp"};
  } catch (...) {
    // runs in build directory for ctest
    file = mfile{"../tests/main.cpp"};
  }

  EXPECT_TRUE(file);
}
