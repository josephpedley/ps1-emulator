#include "interconnect.h"
#include <stdint.h>

bool memory_range_contains(struct memory_range* range, uint32_t address, uint32_t* offset)
{
   uint32_t end_of_range = range->start + range->length;
   if (range->start <= address && address < end_of_range)
   {
       *offset = address - range->start;
       return true;
   }
   return false;
}
