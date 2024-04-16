#define MEMORYSIZE 0x10000

typedef unsigned char BYTE;
typedef unsigned short WORD;

typedef BYTE MEMORY[MEMORYSIZE];

typedef union _STASTUS_REGISTER {
	BYTE DATA;
	struct _FLAG {
		BYTE C : 1;	// carry flag
		BYTE Z : 1;	// zero flag
		BYTE I : 1;	// interrupt disable flag
		BYTE D : 1;	// decimal mode enable flag
		BYTE B : 1;	// break flag
		BYTE UNUSED : 1;
		BYTE V : 1;	// overflow flag
		BYTE N : 1;	// negative flag
	} FLAG;
} STATUS_REGISTER;

typedef struct _PROCESSOR {
	BYTE A;		// accumulator
	BYTE X;		// index x
	BYTE Y;		// index y
	WORD PC;	// program counter
	BYTE SP;	// stack pointer
	BYTE P;		// (or PS) processor status
} PROCESSOR;
