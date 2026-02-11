#include <fcntl.h>
#include <sys/mman.h>
#include <system_error>
#include <unistd.h>

#include "mfile.h"

struct closer {
  int fd;

  closer(int fd) : fd{fd} {}
  ~closer() { close(fd); }
};

mfile::mfile(std::string &path) {
  int fd = open(path.c_str(), 0);

  if (fd == -1)
    throw std::system_error();

  closer closer(fd);

  off_t s = lseek(fd, 0, SEEK_END);

  if (fd == -1)
    throw std::system_error();

  len = s;
  data = mmap(NULL, len, PROT_READ, MAP_PRIVATE, fd, 0);

  if (data == MAP_FAILED)
    throw std::system_error();
}

mfile::mfile(std::string &&path) {
  int fd = open(path.c_str(), 0);

  if (fd == -1)
    throw std::system_error();

  closer closer(fd);

  off_t s = lseek(fd, 0, SEEK_END);

  if (fd == -1)
    throw std::system_error();

  len = s;
  data = mmap(NULL, len, PROT_READ, MAP_PRIVATE, fd, 0);

  if (data == MAP_FAILED)
    throw std::system_error();
}

mfile::~mfile() { munmap(data, len); }

mfile::operator std::string_view() {
  return std::string_view((const char *)data, len);
}
