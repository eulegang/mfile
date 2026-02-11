#ifndef _MFILE_H
#define _MFILE_H

#include <cstddef>
#include <string>
#include <string_view>

class mfile final {
  void *data;
  size_t len;

public:
  mfile(std::string &);
  mfile(std::string &&);
  ~mfile();

  operator std::string_view();
};

#endif
