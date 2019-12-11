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
#include <stdlib.h>
#define WORD uint32_t

/*/ intitializes um program
 * @param argc			number of files
 * @param argv			files
 */
int main(int argc, const char* argv[]){
	assert(argc == 2);
	// open our program instructions file
	FILE* program = fopen(argv[1], "rb");
	
	fseek(program, 0L, SEEK_END);
	long int number_of_bytes = ftell(program);
	rewind(program);
	
	// initialize array to hold program instructions
	WORD* program_sequence = malloc(number_of_bytes/sizeof(WORD)*sizeof(WORD));

	// load program to sequence
	unsigned char buffer[4] = {0, 0, 0, 0};
	int length = number_of_bytes/4;
	WORD* value_we_are_storing = program_sequence;
	for(int i = 0; i < length; i++){
		buffer[0] = getc(program);
		buffer[1] = getc(program);
		buffer[2] = getc(program);
		buffer[3] = getc(program);
		*(value_we_are_storing++) = buffer[0] << 24 | buffer[1] << 16 | buffer[2] << 8 | buffer[3];
	}

	begin_program(program_sequence);

}
