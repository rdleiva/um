//==================================================================================//
// Mikel F Gjergji & Rotman Daniel Leiva Henriquez                                  //
// Professor Daniels                                                                //
// CSC411                                                                           //
// Assignment #6                                                                    //
// December 1, 2019                                                                 //
// instructions.h - instructions interface                                          //
//==================================================================================//

#ifndef INSTRUCTIONS_INCLUDED
#define INSTRUCTIONS_INCLUDED
#include <stdio.h>
#include <inttypes.h>
#include "segments.h"
#define NUMBER_OF_INSTRUCTIONS 14

/*/ If rc is not equal to zero then ra gets the value at rb.
 * No move is performed otherwise
 * @param ra        register a 
 * @param rb        register b
 * @param rc        register c
 */
void conditional_move(REGISTER* ra, REGISTER* rb, REGISTER* rc);

/*/ Loads value in memory segment identified by rb and word offset rc into ra
 * @param seg_mem   memory segment
 * @param ra        register a
 * @param rb        register b
 * @param rc        register c
 */
void load(REGISTER* ra, REGISTER* rb, REGISTER* rc);

/*/ Store value in rc into segment identified by ra at the word offset of rb
 * @param mem_seg   memory segment
 * @param ra        register a
 * @param rb        register b
 * @param rc        register c
 */
void store(REGISTER* ra, REGISTER* rb, REGISTER* rc);

/*/ Adds value in rb and rc and then stores value into ra
 * @param ra        register a
 * @param rb        register b
 * @param rc        register c
 */
void add(REGISTER* ra, REGISTER* rb, REGISTER* rc);

/*/ Multiplies the values in rb and rc and stores the product into ra
 * @param ra        register a
 * @param rb        register b
 * @param rc        register c
 */
void multiply(REGISTER* ra, REGISTER* rb, REGISTER* rc);

/*/ Divides the values in ra and rb and stores the result into ra
 * @param ra        register a
 * @param rb        register b
 * @param rc        register c
 */
void divide(REGISTER* ra, REGISTER* rb, REGISTER* rc);

/*/ Bitwise AND on rb and rc, then bitwise NON on the outcome  and stores value into ra
 * @param ra        register a
 * @param rb        register b
 * @param rc        register c
 */
void nand(REGISTER* ra, REGISTER* rb, REGISTER* rc);

/*/ Stops program */
void halt(REGISTER* ra, REGISTER* rb, REGISTER* rc);

/*/ Creates new memory segment of length rc and stores it's identifier into rb
 * @param mem_seg   memory segment
 * @param rb        register b
 * @param rc        register c
 */
void map_segment(REGISTER* ra, REGISTER* rb, REGISTER* rc);

/*/ Unmaps the memory segment identified by rc
 * @param mem_seg   memory segment
 * @param rc        register c
 */
void unmap_segment(REGISTER* ra, REGISTER* rb, REGISTER *rc);

/*/ Displays the value in rc on the I/O device if it is in the range of 0-255
 * @param rc        register c
 */
void output(REGISTER* ra, REGISTER* rb, REGISTER* rc);

/*/ UM waits for input on I/o device and when it arrives it is stored
 * in rc if it's in the range of 0-255. 
 * @param rc        register c
 */
void input(REGISTER* ra, REGISTER* rb, REGISTER* rc);

/*/ Loads memory segment identified by rb and creates a copy to replace the content
 * of memory segment 0 which is abandoned.  Program counter is then set to point to
 * the memory segment stored at memory segment 0 at the word offset of rc
 * @param mem_seg   memory segment
 * @param rb        register b
 * @param rc        register c
 */
void load_program(REGISTER* ra, REGISTER* rb, REGISTER* rc);

// Access to array of instruction functions
void(*instructions[NUMBER_OF_INSTRUCTIONS-1])(REGISTER* ra, REGISTER* rb, REGISTER* rc) = {
	conditional_move,
	load,
	store,
	add,
	multiply,
	divide,
	nand,
	halt,
	map_segment,
	unmap_segment,
	output,
	input,
	load_program
};

/*/ Stores the value located within the word into a register located within the word
 * @param ra        register a
 * @param word      word
 */
void load_value(REGISTER* ra, WORD_SIZE value);

#endif
