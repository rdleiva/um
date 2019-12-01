#include "bitpack.h"
#include "instructions.h"
#include "registers.h"
#include "segments.h"
#include "array.h"
#include <stdlib.h>

#define CODE_SIZE 4
#define CODE_LSB 28
#define INSTRUCTION_SIZE 3
#define A_START 9
#define WORD uint32_t

void perform_operation(uint32_t word){
	
	uint64_t code = Bitpack_getu(word, CODE_SIZE, CODE_LSB);

	if (code < 13){
		uint64_t A = Bitpack_getu(word, INSTRUCTION_SIZE, A_START-INSTRUCTION_SIZE);
		uint64_t B = Bitpack_getu(word, INSTRUCTION_SIZE, A_START-(2*INSTRUCTION_SIZE));
		uint64_t C = Bitpack_getu(word, INSTRUCTION_SIZE, A_START-(3*INSTRUCTION_SIZE));
		(*instructions[code]) (&registers[A], &registers[B], &registers[C]);
	}

	else if (code == 13){
		uint64_t A = Bitpack_getu(word, INSTRUCTION_SIZE, CODE_LSB-INSTRUCTION_SIZE);
		uint64_t value = Bitpack_getu(word, sizeof(WORD)*8 - CODE_SIZE - INSTRUCTION_SIZE, 0);
		load_value(&registers[A], value);
	}

	else{
		exit(1);
	}
}

void begin_program(Array_T program){
	initialize_program(program);
	while(1){

		uint32_t word = *(Program_Counter++);
		perform_operation(word);

	}
}
