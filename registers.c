//==================================================================================//
// Mikel F Gjergji & Rotman Daniel Leiva Henriquez                                  //
// Professor Daniels                                                                //
// CSC411                                                                           //
// Assignment #6                                                                    //
// December 1, 2019                                                                 //
// registers.c - registers implementation                                           //
//==================================================================================//

#include "registers.h"
#include "mem.h"

void initialize_registers(){
	registers = CALLOC(8, sizeof(REGISTER));
	Program_Counter = 0;
}
