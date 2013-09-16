#ifndef __cplusplus
#include <stdbool.h>
#endif
#include <stddef.h>
#include <stdint.h>
#include "term.h"

#if defined (__linux__)
#error "Not using a cross compiler; this is a bad idea"
#endif

Terminal term;
 
#if defined(__cplusplus)
extern "C" /* Use C linkage for kernel_main. */
#endif
void kernel_main()
{
	Terminal_Initialize(&term, (u16_t*)VGA_ADDRESS);

	Terminal_SetColor(&term,Terminal_MakeColor(VGAColor_LightBlue,VGAColor_Black));
	Terminal_WriteString(&term,"Hello,\r\n");
	Terminal_SetColor(&term,Terminal_MakeColor(VGAColor_Red,VGAColor_Black));
	Terminal_WriteString(&term,"Kernel\r\n");
	Terminal_SetColor(&term,Terminal_MakeColor(VGAColor_White,VGAColor_Black));
	Terminal_WriteString(&term,"World!");
}
