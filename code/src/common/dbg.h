#ifndef DBGGGG_H_
#define DBGGGG_H_

#include <Arduino.h>

#define dbgn(msg) {  Serial.println(msg); }

#define dbg(format, args...) { char dbg_buf[64]; snprintf(dbg_buf, 63, format, args); Serial.println(dbg_buf); }



//#define dbg(format, args...) ;

#endif
