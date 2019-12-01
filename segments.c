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
#define IDENTIFIER uint32_t
#define REGISTER uint32_t
#define SEGMENTS_INITIAL_SIZE 2

Seq_T segments;
List_T free_segments = NULL;

void unmap_memory_segment(IDENTIFIER mem_seg){
	Array_T memory_block = Seq_get(segments, mem_seg);
	Array_free(&memory_block);
	List_push(free_segments, &mem_seg);
}

REGISTER map_memory_segment(uint32_t word_count){
	// pops first item from list and if still null, means no free spots in current sequence of segments
	IDENTIFIER* free_segment;
	List_pop(free_segments, &free_segment);
	
	// initialize array of size word_count to place in memory
	Array_T segment = Array_new(word_count, sizeof(uint32_t));

	// if we were unable to find a free segment, then add new spot in sequence
	if(!free_segment){
		Seq_addhi(segments, segment);
		return Seq_length(segments) - 1;
	}

	// else we put our new allocation in the free spot
	else{
		Seq_put(segments, *free_segment, segment);
		return *free_segment;
	}
}

void move_memory_segment(IDENTIFIER source, IDENTIFIER program_counter, IDENTIFIER destination){
	// get new program to load
	Array_T new_program = Seq_get(segments, source);
	// place new program in program slot 0, and free previous program
	Array_T previous_program = Seq_put(segments, 0, Array_copy(new_program, Array_size(new_program)));
	Array_free(&previous_program);
	// set program counter to specified program counter
	Program_Counter = Array_get(new_program, program_counter);
}

void store_memory_segment(IDENTIFIER index, IDENTIFIER segment_index, REGISTER value_to_store){
	Array_T segment = Seq_get(segments, index);
	REGISTER* value_at_index = Array_get(segment, segment_index);
	*value_at_index = value_to_store;
}

REGISTER load_memory_segment(IDENTIFIER index, IDENTIFIER segment_index){
	Array_T segment = Seq_get(segments, index);
	REGISTER* value_at_index = Array_get(segment, segment_index);
	return *value_at_index;
}

void initialize_program(Array_T program){
	segments = Seq_new(SEGMENTS_INITIAL_SIZE);
	List_push(free_segments, SEGMENTS_INITIAL_SIZE-1);
	Seq_put(segments, 0, program);
	Program_Counter = Array_get(program, 0);
}
