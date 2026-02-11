#ifndef _MFILE_H
#define _MFILE_H

#include <cstddef>
#include <string>
#include <string_view>

class mfile final {
  void *data;
  size_t len;

public:
  mfile();
  mfile(std::string &);
  mfile(std::string &&);
  ~mfile();

  mfile(const mfile &) = delete;
  mfile &operator=(const mfile &) = delete;

  mfile(mfile &&);
  mfile &operator=(mfile &&);

  operator bool() const;
  operator std::string_view() const;
};

#endif
