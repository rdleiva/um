//==================================================================================//
// Mikel F Gjergji & Rotman Daniel Leiva Henriquez                                  //
// Professor Daniels                                                                //
// CSC411                                                                           //
// Assignment #6                                                                    //
// December 1, 2019                                                                 //
// operation_decoder.c - operation decoder implementation                           //
//==================================================================================//


#include "bitpack.h"
#include "instructions.h"
#include "registers.h"
#include "segments.h"
#include "array.h"
#include <stdlib.h>
#include <stdio.h>

#define CODE_SIZE 4
#define CODE_LSB 28
#define INSTRUCTION_SIZE 3
#define A_LSB 6
#define A_SPECIAL_LSB 25
#define B_LSB 3
#define C_LSB 0
#define VALUE_SIZE 25
#define VALUE_LSB 0
#define WORD uint32_t

/*/ takes in operation code and performs that instruction 
 * @param word		operation code
 */
// Precompute masks
WORD mask = ~(~0U << INSTRUCTION_SIZE);
WORD codemask = ~(~0U << CODE_SIZE);
WORD valuemask = ~(~0U << VALUE_SIZE);

void perform_operations(){

	uint64_t A,B,C,value,code;
	WORD word;
	while(1){

		word = *(Program_Counter++);
		code = (word >> CODE_LSB) & codemask;

		if (code < 13){
			if(code <= 6) A = (word >> A_LSB) & mask;
			if(!(code >= 9 && code <= 11)) B = (word >> B_LSB) & mask;
			C = (word >> C_LSB) & mask;
			(*instructions[code]) (&registers[A], &registers[B], &registers[C]);
		}

		else{
			A = (word >> A_SPECIAL_LSB) & mask;
			value = (word >> VALUE_LSB) & valuemask;
			load_value(&registers[A], value);
		}

	}
}

/*/ takes in program and starts it
 * @param program	program to be started
 */
void begin_program(Array_T program){
	initialize_registers();
	initialize_program(program);
	perform_operations();
}
