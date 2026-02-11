#ifndef _MFILE_H
#define _MFILE_H

#include <cstddef>
#include <string>
#include <string_view>

class map_file final {
  void *data;
  size_t len;

public:
  map_file(std::string &);
  ~map_file();

  operator std::string_view();
};

#endif
