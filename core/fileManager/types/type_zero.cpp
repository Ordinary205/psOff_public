#include "type_zero.h"

class TypeZero: public IFile {
  public:
  TypeZero(): IFile(FileType::Device) {}

  virtual ~TypeZero() {}

  // ### Interface
  size_t  read(void* buf, size_t nbytes) final;
  size_t  write(void* buf, size_t nbytes) final;
  int64_t lseek(int64_t offset, SceWhence whence) final;
  void    sync() final;

  void* getNative() final { return nullptr; }
};

std::unique_ptr<IFile> createType_zero() {
  return std::make_unique<TypeZero>();
}

size_t TypeZero::read(void* buf, size_t nbytes) {
  for (size_t i = 0; i < nbytes; i++) {
    ((char*)buf)[i] = '\0';
  }

  return nbytes;
}

size_t TypeZero::write(void* buf, size_t nbytes) {
  return 0;
}

int64_t TypeZero::lseek(int64_t offset, SceWhence whence) {
  return -1;
}

void TypeZero::sync() {}