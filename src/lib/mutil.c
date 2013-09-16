#include "mutil.h"

inline void MUtil_CreateGate( kword_t interruptNumber, m_interrupt_handler_t handler ) {
	interruptNumber <<= 4;
	* (kptr_t*)(interruptNumber) = (kptr_t) handler;
}

void memcpy( void* _dest, const void* _src, ksize_t len ) {
	ksize_t* dest = _dest;
	const ksize_t* src  = _src;

	u8_t* dest2;
	const u8_t* src2;

	while( len > sizeof( ksize_t ) ) {
		*dest = *src;
		++ dest;
		++ src;
		len -= sizeof( ksize_t );
	}

	dest2 = (u8_t*)dest;
	src2  = (u8_t*)src;

	while( len > 0 ) {
		*dest2 = *src2;
		++ dest2;
		++ src2;
		-- len;
	}

}

void memset( void* _dest, u8_t ch, ksize_t len ) {
	ksize_t rep = 0;
	ksize_t i;
	ksize_t* dest = _dest;
	u8_t* dest2;
	// optimize out
	for( i = 0 ; i < sizeof( ksize_t ); ++ i ) {
		rep |= ch;
		rep <<= 8;
	}

	for( ; len > sizeof( ksize_t ) ; len -= sizeof( ksize_t ) ) {
		*dest = rep;
		++ dest;
	}

	dest2 = (u8_t*)dest;
	for( ; len > 0; -- len ) {
		*dest2 = ch;
	}

}

ksize_t strlen( const char* str ) {
	ksize_t ret = 0;
	while( str[ret++] != 0 );
	return ret;
}
