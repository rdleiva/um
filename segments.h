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

/*/ unmaps memory segment 
 * @param mem_seg        	memory segment to be unmapped
 */
void unmap_memory_segment(IDENTIFIER mem_seg);

/*/ maps memory segment of size word_count
 * @param word_count		number of words to be mapped 
 * @return					pointer to free segment or new segment
 */
REGISTER map_memory_segment(uint32_t word_count);

/*/ moves memory segment from source to destination and points to new program
 * @param source        	memory segment to be moved 
 * @param program_counter   points to new program counter
 * @param destination       destination of memory segment being moved
 */
void move_memory_segment(IDENTIFIER source, IDENTIFIER program_counter);

/*/ store memory segment 
 * @param index        		index 
 * @param segment_index  	segment index
 * @param value_to_store    value to store
 */
void store_memory_segment(IDENTIFIER index, IDENTIFIER segment_index, REGISTER value_to_store);

/*/ load memory segment 
 * @param index  	 		index
 * @param segment_index 	index of segment
 */
REGISTER load_memory_segment(IDENTIFIER index, IDENTIFIER segment_index);

/*/ initialize program
 * @param program			program to be initialized
 */
void initialize_program(IDENTIFIER* program);

#endif
