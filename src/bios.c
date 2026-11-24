#include "bios.h"
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
     return (uint32_t)(bios->data[offset]) | ((uint32_t)bios->data[offset +1] << 8)
                                           | ((uint32_t)bios->data[offset+2] << 16)
                                           | ((uint32_t)bios->data[offset+3] << 24);


}

