//==================================================================================//
// Mikel F Gjergji & Rotman Daniel Leiva Henriquez                                  //
// Professor Daniels                                                                //
// CSC411                                                                           //
// Assignment #6                                                                    //
// December 1, 2019                                                                 //
// segments.h - memory segments interface                                           //
//==================================================================================//
#ifndef SEGMENTS_INCLUDED
#define SEGMENTS_INCLUDED

#include <inttypes.h>
#include "array.h"
#include "seq.h"
#include "list.h"
#define REGISTER uint32_t
#define IDENTIFIER uint32_t
#define WORD_SIZE uint32_t

void unmap_memory_segment(IDENTIFIER mem_seg);
REGISTER map_memory_segment(uint32_t word_count);
void move_memory_segment(IDENTIFIER source, IDENTIFIER program_counter, IDENTIFIER destination);
void store_memory_segment(IDENTIFIER index, IDENTIFIER segment_index, REGISTER value_to_store);
REGISTER load_memory_segment(IDENTIFIER index, IDENTIFIER segment_index);
void initialize_program(Array_T program);
REGISTER get_next_instruction();

#endif
