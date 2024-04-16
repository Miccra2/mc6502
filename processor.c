#include "processor.h"

/* 
 * --- memory --- 
 */

void Initialize(MEMORY memory) {
	for (int i = 0; i < MEMORYSIZE; i++) {
		memory[i] = 0;
	}
}

void Write(int cycles, MEMORY memory, WORD address, BYTE data) {
	cycles--;
	memory[address] = data;
}

BYTE Read(int cycles, MEMORY memory, WORD address) {
	cycles--;
	return memory[address];
}

/* 
 * --- processor --- 
 */

BYTE FetchByte(int cycles, MEMORY memory, WORD address) {
	cycles--;
	return memory[address];
}

void Reset(PROCESSOR processor, MEMORY memory, WORD reset_vector) {
	processor.A = 0;
	processor.X = 0;
	processor.Y = 0;
	processor.PC = reset_vector;
	processor.SP = STACKTOP;
	processor.P.REG = 0x20;
	
	Initialize(memory);
}

void Execute(int cycles, PROCESSOR processor, MEMORY memory) {
	while (cycles > 0) {
		BYTE Instruction = FetchByte(cycles, memory, processor.PC);
		
		switch (Instruction) {
		case IMM_LDA:
			
		}
	}
}

void PrintStatus(PROCESSOR processor) {
	printf("A:  %.2X\n", processor.A);
	printf("X:  %.2X\n", processor.X);
	printf("Y:  %.2X\n", processor.Y);
	printf("PC: %.4X\n", processor.PC);
	printf("SP: %.2X\n", processor.SP);
	printf("P:\n");
	printf("    C: %i Z: %i I: %i D: %i\n", 
		processor.P.C, processor.P.Z, processor.P.I, processor.P.D);
	printf("    B: %i -: %i V: %i N: %i\n", 
		processor.P.B, processor.P.UNUSED, processor.P.V, processor.P.N);
}

void PrintAddress(MEMORY memory, WORD address) {
	printf("%.4X: %.2X\n", address, memory[address]);
}

void PrintAddresses(MEMORY memory, WORD start_address, WORD end_address) {
	for (int i = start_address; i < end_address; i += 16) {
		printf("%.4X: ", (start_address & 0xFFF0));
		
		for (int j = 0; j < 16; j++) {
			if ((i + j < start_address) || (i + j > end_address)) {
				printf("   ");
			} else {
				printf("%.2X ", memory[i + j]);
			}
		}
		
		printf("\n");
	}
}
