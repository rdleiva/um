//==================================================================================//
// Mikel F Gjergji & Rotman Daniel Leiva Henriquez                                  //
// Professor Daniels                                                                //
// CSC411                                                                           //
// Assignment #6                                                                    //
// December 1, 2019                                                                 //
// registers.h - registers interface                                                //
//==================================================================================//

#include <inttypes.h>
#define REGISTER uint32_t

REGISTER *registers;
REGISTER *Program_Counter;
void initialize_registers();
