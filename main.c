#include "processor.h"

int main(int argc, char *argv[]) {
	PROCESSOR cpu;
	MEMORY mem;
	
	Reset(cpu, mem, RESET_VECTOR);
	
	// inline program - start
	mem[0xFFFC] = 0xA9;
	mem[0xFFFD] = 69;
	// inline program - end
	
	PrintAddress(mem, 0xFFFC);
	PrintAddress(mem, 0xFFFD);
	PrintStatus(cpu);
	Execute(1, cpu, mem);
	PrintStatus(cpu);
	Execute(1, cpu, mem);
	PrintStatus(cpu);

	return 0;
}
