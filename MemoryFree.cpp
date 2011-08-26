// code from http://www.arduino.cc/playground/Code/AvailableMemory

#include "MemoryFree.h";
#include "Serialprint.h"

extern unsigned int __bss_end;
extern void *__brkval;


int freeMemory() {
  int free_memory;

  if((int)__brkval == 0)
     free_memory = ((int)&free_memory) - ((int)&__bss_end);
  else
    free_memory = ((int)&free_memory) - ((int)__brkval);

  return free_memory;
}

void printFreeMemory() {
  Serialprint("freeMemory: %d\n", freeMemory());
}

