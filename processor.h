#include <stdio.h>
#include <string.h>

#include "x65types.h"
#include "addressing.c"

/*
 * --- instructions ---
 */

// LDA
#define IMM_LDA  0xA9	// 0b 1010 1001
#define ZPG_LDA  0xA5	// 0b 1010 0101
#define ZPGX_LDA 0xB5	// 0b 1011 0101
#define ABS_LDA  0xAD	// 0b 1010 1101
#define ABSX_LDA 0xBD	// 0b 1011 1101
#define ABSY_LDA 0xB9	// 0b 1011 1001
#define INDX_LDA 0xA1	// 0b 1010 0001
#define INDY_LDA 0xB1	// 0b 1011 0001
