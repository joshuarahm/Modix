#ifndef TERMINAL_H_
#define TERMINAL_H_

#include "mtypes.h"

enum VGAColor {
	   VGAColor_Black = 0
	,  VGAColor_Blue = 1
	,  VGAColor_Green = 2
	,  VGAColor_Cyan = 3
	,  VGAColor_Red = 4
	,  VGAColor_Magenta = 5
	,  VGAColor_Brown = 6
	,  VGAColor_LightGrey = 7
	,  VGAColor_DarkGrey = 8
	,  VGAColor_LightBlue = 9
	,  VGAColor_LightGreen = 10
	,  VGAColor_LightCyan = 11
	,  VGAColor_LightRed = 12
	,  VGAColor_LightMagenta = 13
	,  VGAColor_LightBrown = 14
	,  VGAColor_White = 15
};

#define VGA_HEIGHT 24
#define VGA_WIDTH 80
#define VGA_BUFFER_SIZE (VGA_HEIGHT*VGA_WIDTH)

#define VGA_ADDRESS 0xB8000

typedef struct {
	u32_t row;
	u32_t col;
} CursorPosition;

typedef struct {
	u8_t _m_CurrentColor;
	u16_t* _m_Buffer;

	CursorPosition _m_CursorPosition;
} Terminal;

u8_t Terminal_MakeColor( enum VGAColor fg, enum VGAColor bg );

u16_t Terminal_MakeVGAEntry( char c, u8_t color );

/*
 * Starts a terminal fresh
 */
void Terminal_Initialize( Terminal* term, u16_t* buffer ) ;

void Terminal_SetColor( Terminal* term, u8_t color );

/*
 * Adds an entry into the terminal's buffer
 */
void Terminal_PutEntryAt( Terminal* term, char c,
	u8_t color, u32_t x, u32_t y ) ;

void Termainal_WriteChar( Terminal* term, char c );

void Terminal_WriteString( Terminal* term, const char* str );

void Terminal_ReadLine( Terminal* term, char *buf, ksize_t len );


#endif
