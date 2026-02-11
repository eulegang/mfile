#include "mfile.h"
#include <gtest/gtest.h>

const std::string test_content = "#include \"gtest/gtest.h\"\n"
                                 "\n"
                                 "int main(int argc, char **argv) {\n"
                                 "  testing::InitGoogleTest(&argc, argv);\n"
                                 "  return RUN_ALL_TESTS();\n"
                                 "}\n";

TEST(mfile, content) {
  mfile file;
  try {
    // assumes base source directory
    file = mfile{"tests/main.cpp"};
  } catch (...) {
    // runs in build directory for ctest
    file = mfile{"../tests/main.cpp"};
  }

  EXPECT_EQ((std::string_view)file, test_content);
}
