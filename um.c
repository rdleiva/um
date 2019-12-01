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

int main(int argc, const char* argv[]){
	assert(argc == 2);
	// open our program instructions file
	FILE* program = fopen(argv[1], "rb");
	
	fseek(program, 0L, SEEK_END);
	long int number_of_bytes = ftell(program);
	rewind(program);
	
	// initialize array to hold program instructions
	Array_T program_sequence = Array_new(number_of_bytes, sizeof(WORD));

	// load program to sequence
	WORD word = 0;
	char arr[sizeof(WORD)];
	int iterator = 0;
	int position_in_array = 0;
	while(1){
		int ch = getc(file);
		if(ch == EOF) break;
		arr[iterator++] = ch;
		if(iterator == sizeof(WORD)){
			word = *((WORD*) arr);
			WORD* value_we_are_storing = Array_get(program_sequence, position_in_array++);
			*value_we_are_storing = word;
			iterator = 0;
		}
	}
	
	begin_program(program_sequence);
}
