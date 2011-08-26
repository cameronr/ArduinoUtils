// Code from: http://www.utopiamechanicus.com/399/low-memory-serial-print/
//
#ifndef _SERIALPRINT_H_
#define _SERIALPRINT_H_

#include <avr/pgmspace.h>

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif


#ifdef __cplusplus
extern "C" {
#endif // __cpluscplus

void StreamPrint_progmem(Print &out, PGM_P format, ...);

#define Serialprint(format, ...) StreamPrint_progmem(Serial,PSTR(format),##__VA_ARGS__)
#define Streamprint(stream,format, ...) StreamPrint_progmem(stream,PSTR(format),##__VA_ARGS__)

#ifdef __cplusplus
} // extern "C"
#endif // __cpluscplus

#endif // _SERIALPRINT_H_

