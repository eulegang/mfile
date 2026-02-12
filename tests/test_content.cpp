#include "mfile.h"
#include <gtest/gtest.h>

TEST(mfile, content) {
  mfile file;
  try {
    // assumes base source directory
    file = mfile{"test.txt"};
  } catch (...) {
    // runs in build directory for ctest
    file = mfile{"../test.txt"};
  }

  EXPECT_EQ((std::string_view)file, "hello world\n");
}

TEST(mfile, bytes) {
  mfile file;
  try {
    // assumes base source directory
    file = mfile{"test.txt"};
  } catch (...) {
    // runs in build directory for ctest
    file = mfile{"../test.txt"};
  }

  const uint8_t content[] = {'h', 'e', 'l', 'l', 'o', ' ',
                             'w', 'o', 'r', 'l', 'd', 10};
  std::span<const uint8_t> sp = file;

  EXPECT_EQ(memcmp(content, sp.data(), 12), 0);
}
