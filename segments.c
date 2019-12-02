//==================================================================================//
// Mikel F Gjergji & Rotman Daniel Leiva Henriquez                                  //
// Professor Daniels                                                                //
// CSC411                                                                           //
// Assignment #6                                                                    //
// December 1, 2019                                                                 //
// segments.c - memory segments implementation                                      //
//==================================================================================//

#include "seq.h"
#include "list.h"
#include <inttypes.h>
#include "array.h"
#include "registers.h"
#include <stddef.h>
#include <stdio.h>
#include "segments.h"
#include "mem.h"

#define IDENTIFIER uint32_t
#define REGISTER uint32_t
#define SEGMENTS_INITIAL_SIZE 1 

Seq_T segments;
Seq_T free_segments;

/*/ unmaps memory segment 
 * @param mem_seg        	memory segment to be unmapped
 */
void unmap_memory_segment(IDENTIFIER mem_seg){
	Array_T memory_block = Seq_get(segments, mem_seg);
	Array_free(&memory_block);
	IDENTIFIER* value = CALLOC(4, 1);
	*value = mem_seg;
	Seq_addhi(free_segments, value);
}

/*/ maps memory segment of size word_count
 * @param word_count		number of words to be mapped 
 * @return					pointer to free segment or new segment
 */
REGISTER map_memory_segment(uint32_t word_count){
	// initialize array of size word_count to place in memory
	Array_T segment = Array_new(word_count, sizeof(uint32_t));

	// if we were unable to find a free segment, then add new spot in sequence
	if(Seq_length(free_segments) == 0){
		Seq_addhi(segments, segment);
		return Seq_length(segments) - 1;
	}

	// else we put our new allocation in the free spot
	else{
		IDENTIFIER* free_segment = Seq_remhi(free_segments);
		Seq_put(segments, *free_segment, segment);
		return *free_segment;
	}
}

/*/ moves memory segment from source to destination and points to new program
 * @param source        	memory segment to be moved 
 * @param program_counter   points to new program counter
 * @param destination       destination of memory segment being moved
 */
void move_memory_segment(IDENTIFIER source, IDENTIFIER program_counter, IDENTIFIER destination){
	if(source == 0){
		Program_Counter = (IDENTIFIER*)Array_get(Seq_get(segments, 0), program_counter);
		return;
	}
	// get new program to load
	Array_T new_program = Seq_get(segments, source);
	// place new program in program slot 'destination', and free previous program
	Array_T previous_program = Seq_put(segments, destination, Array_copy(new_program, Array_length(new_program)));
	Array_free(&previous_program);
	// set program counter to specified program counter
	Program_Counter = (IDENTIFIER*)Array_get(new_program, program_counter);
}

/*/ store memory segment 
 * @param index        		index 
 * @param segment_index  	segment index
 * @param value_to_store    value to store
 */
void store_memory_segment(IDENTIFIER index, IDENTIFIER segment_index, REGISTER value_to_store){
	Array_T segment = Seq_get(segments, index);
	REGISTER* value_at_index = Array_get(segment, segment_index);
	*value_at_index = value_to_store;
}

/*/ load memory segment 
 * @param index  	 		index
 * @param segment_index 	index of segment
 */
REGISTER load_memory_segment(IDENTIFIER index, IDENTIFIER segment_index){
	Array_T segment = Seq_get(segments, index);
	//printf("Array_Length:%d, Array_Index:%d\n", Array_length(segment), segment_index);
	REGISTER* value_at_index = Array_get(segment, segment_index);
	return *value_at_index;
}

/*/ initialize program
 * @param program			program to be initialized
 */
void initialize_program(Array_T program){
	segments = Seq_new(SEGMENTS_INITIAL_SIZE);
	free_segments = Seq_new(SEGMENTS_INITIAL_SIZE);
	Seq_addlo(segments, program);
	Program_Counter = (IDENTIFIER*)Array_get(program, 0);
}