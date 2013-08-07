#ifndef UTIL_H_
#define UTIL_H_

#include "mtypes.h"

#define Util_Zero( dest, len ) Util_MemSet( dest, 0, len )

void Util_MemCopy( void* dest, const void* src, ksize_t len );

void Util_MemSet( void* dest, u8_t ch, ksize_t len );

ksize_t Util_StrLen( const char* ch );

#endif
