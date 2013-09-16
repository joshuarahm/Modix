#ifndef MUTIL_H_
#define MUTIL_H_

#include "mtypes.h"

/* Create a gate to handle interrupts from a device */
void MUtil_CreateGate( kword_t int_num, m_interrupt_handler_t handler );

/* Copy a region of memory */
void memcpy( void* _dest, const void* src, ksize_t len );

/* set a region of memory */
void memset( void* _dest, u8_t ch, ksize_t len );

ksize_t strlen( const char* str ) ;

#endif
