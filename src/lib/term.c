
#include "term.h"
#include "mutil.h"

inline u8_t Terminal_MakeColor( enum VGAColor fg, enum VGAColor bg ) {
	return fg | bg << 4;
}

inline u16_t Terminal_MakeVGAColor( char c, u8_t color ) {
	u16_t c16 = c;
	u16_t color16 = color;
	return c16 | color16 << 8;
}

void Terminal_Initialize( Terminal* term, u16_t* buffer ) {
	ksize_t i;

	memset( term, 0, sizeof( term ) );
	term->_m_Buffer = buffer;
	Terminal_SetColor( term, Terminal_MakeColor( VGAColor_White, VGAColor_Black ) );
	
	for( i = 0; i < VGA_BUFFER_SIZE; ++ i ) {
		buffer[i] = Terminal_MakeVGAColor( ' ', term->_m_CurrentColor );
	}
};

inline void Terminal_SetColor( Terminal* term, u8_t color ) {
	term->_m_CurrentColor = color;
}

inline void Terminal_PutEntryAt( Terminal* term, char c, u8_t color, u32_t x, u32_t y ) {
	ksize_t index = y * VGA_WIDTH + x;
	term->_m_Buffer[index] = Terminal_MakeVGAColor(c, color);
}

void Terminal_WriteChar( Terminal* term, char c ) {
	if( c == '\n' ) {
		++ term->_m_CursorPosition.row;
	} else if( c == '\r' ) {
		term->_m_CursorPosition.col = -1;
	} else {
		Terminal_PutEntryAt( term, c, term->_m_CurrentColor, term->_m_CursorPosition.col,
			term->_m_CursorPosition.row );
		++ term->_m_CursorPosition.col;
	}
}

void Terminal_WriteString( Terminal* term, const char* data) {
	ksize_t datalen = strlen(data);
	ksize_t i;
	for (  i = 0; i < datalen; i++ )
		Terminal_WriteChar(term, data[i]);
}

void Terminal_ReadLine( Terminal* term, char *buf, ksize_t len ) {
	(void) term;
	(void) buf;
	(void) len;
}
