//==================================================================================//
// Mikel F Gjergji & Rotman Daniel Leiva Henriquez                                  //
// Professor Daniels                                                                //
// CSC411                                                                           //
// Assignment #6                                                                    //
// December 1, 2019                                                                 //
// operation_decoder.h - operation decoder interface                                //
//==================================================================================//

#ifndef OPERATION_DECODER_INCLUDED
#define OPERATION_DECODER_INCLUDED

#include <inttypes.h>
#include "array.h"

/*/ takes in operation code and performs that instruction 
 * @param word		operation code
 */
void perform_operations();

/*/ takes in program and starts it
 * @param program	program to be started
 */
void begin_program(uint32_t* program);
#endif
