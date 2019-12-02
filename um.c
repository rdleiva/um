//==================================================================================//
// Mikel F Gjergji & Rotman Daniel Leiva Henriquez                                  //
// Professor Daniels                                                                //
// CSC411                                                                           //
// Assignment #6                                                                    //
// December 1, 2019                                                                 //
// um.c - universal virtual machine                                                 //
//==================================================================================//
#include "operation_decoder.h"
#include "assert.h"
#include <stdio.h>
#include <inttypes.h>
#include "array.h"
#include "mem.h"
#include "bitpack.h"
#define WORD uint32_t

int main(int argc, const char* argv[]){
	assert(argc == 2);
	// open our program instructions file
	FILE* program = fopen(argv[1], "rb");
	
	fseek(program, 0L, SEEK_END);
	long int number_of_bytes = ftell(program);
	rewind(program);
	
	// initialize array to hold program instructions
	Array_T program_sequence = Array_new(number_of_bytes/sizeof(WORD), sizeof(WORD));

	// load program to sequence
	WORD word = 0;
	long int position_in_array = 0;
	unsigned char ch;
	while(position_in_array < Array_length(program_sequence)){
		ch = getc(program);
		word = Bitpack_newu(word, 8, 32 - 8, (unsigned)ch);
		ch = getc(program);
		word = Bitpack_newu(word, 8, 32 - 16, (unsigned)ch);
		ch = getc(program);
		word = Bitpack_newu(word, 8, 32 - 24, (unsigned)ch);
		ch = getc(program);
		word = Bitpack_newu(word, 8, 32 - 32, (unsigned)ch);
		WORD* value_we_are_storing = Array_get(program_sequence, position_in_array++);
		*value_we_are_storing = word;
	}

	begin_program(program_sequence);

}
