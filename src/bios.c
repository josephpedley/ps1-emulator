#include "bios.h"
#include "common/bytes.h"
#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>

bool load_bios_image(struct Bios *bios, const char *path) {
  int bios_fd = open(path, O_RDONLY);

  if (bios_fd == -1) {
    return false;
  }

  ssize_t bytes_read = read(bios_fd, bios->data, BIOS_SIZE);

  close(bios_fd);

  return bytes_read == BIOS_SIZE;
}

uint32_t load_bios_word(struct Bios *bios, uint32_t offset) 
{
     return read_u32_le(&bios->data[offset]);
}

