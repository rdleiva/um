//==================================================================================//
// Mikel F Gjergji & Rotman Daniel Leiva Henriquez                                  //
// Professor Daniels                                                                //
// CSC411                                                                           //
// Assignment #6                                                                    //
// December 1, 2019                                                                 //
// instructions.c - instructions implenentation                                     //
//==================================================================================//

#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "segments.h"
#include "instructions.h"
#include "assert.h"

/*/ If rc is not equal to zero then ra gets the value at rb.
 * No move is performed otherwise
 * @param ra        register a 
 * @param rb        register b
 * @param rc        register c
 */
void conditional_move(REGISTER* ra, REGISTER* rb, REGISTER* rc){
    if(*rc != 0) *ra = *rb;
}

/*/ Loads value in memory segment identified by rb and word offset rc into ra
 * @param ra        memory segment to be loaded
 * @param rb        register b
 * @param rc        register c
 */
void load(REGISTER* ra, REGISTER* rb, REGISTER* rc){
    *ra = load_memory_segment(*rb, *rc);
}

/*/ Store value in rc into segment identified by ra at the word offset of rb
 * @param ra        memory segment to be stored
 * @param rb        register b
 * @param rc        register c
 */
void store(REGISTER* ra, REGISTER* rb, REGISTER* rc){
    store_memory_segment(*ra, *rb, *rc);
}

/*/ Adds value in rb and rc and then stores value into ra
 * @param ra        register a
 * @param rb        register b
 * @param rc        register c
 */
void add(REGISTER* ra, REGISTER* rb, REGISTER* rc){
    *ra = (*rb + *rc);
}

/*/ Multiplies the values in rb and rc and stores the product into ra
 * @param ra        register a
 * @param rb        register b
 * @param rc        register c
 */
void multiply(REGISTER* ra, REGISTER* rb, REGISTER* rc){
    *ra = (*rb * *rc);
}

/*/ Divides the values in ra and rb and stores the result into ra
 * @param ra        register a
 * @param rb        register b
 * @param rc        register c
 */
void divide(REGISTER* ra, REGISTER* rb, REGISTER* rc){
    //assert(*rc != 0);
    *ra = (*rb / *rc);
}

/*/ Bitwise AND on rb and rc, then bitwise NON on the outcome  and stores value into ra
 * @param ra        register a
 * @param rb        register b
 * @param rc        register c
 */
void nand(REGISTER* ra, REGISTER* rb, REGISTER* rc){
    *ra = ~(*rb & *rc);
}

/*/ Stops program */
void halt(REGISTER* ra, REGISTER* rb, REGISTER* rc){
    (void)ra;
    (void)rb;
    (void)rc;
    exit(EXIT_SUCCESS);
}

/*/ Creates new memory segment of length rc and stores it's identifier into rb
 * @param ra        void
 * @param rb        identifier storage
 * @param rc        lenth of memory segment to be mapped
 */
void map_segment(REGISTER* ra, REGISTER* rb, REGISTER* rc){
    (void)ra;
    *rb = map_memory_segment(*rc);
}

/*/ Unmaps the memory segment identified by rc
 * @param ra        void
 * @param rb        void
 * @param rc        memory segment to be unmapped
 */
void unmap_segment(REGISTER* ra, REGISTER* rb, REGISTER *rc){
    (void)ra;
    (void)rb;
    unmap_memory_segment(*rc);
}

/*/ Displays the value in rc on the I/O device if it is in the range of 0-255
 * @param ra        void
 * @param rb        void
 * @param rc        output
 */
void output(REGISTER* ra, REGISTER* rb, REGISTER* rc){
    (void)ra;
    (void)rb;
    fprintf(stdout, "%c", (char)(*rc));
}

/*/ UM waits for input on I/o device and when it arrives it is stored
 * in rc if it's in the range of 0-255. 
 * @param ra        void
 * @param rb        void
 * @param rc        input
 */
void input(REGISTER* ra, REGISTER* rb, REGISTER* rc){
    (void)ra;
    (void)rb;
    *rc = fgetc(stdin);
    if(*rc == (unsigned)EOF) *rc = ~0;
}

/*/ Loads memory segment identified by rb and creates a copy to replace the content
 * of memory segment 0 which is abandoned.  Program counter is then set to point to
 * the memory segment stored at memory segment 0 at the word offset of rc
 * @param ra        void
 * @param rb        register b
 * @param rc        register c
 */
void load_program(REGISTER* ra, REGISTER* rb, REGISTER* rc){
    (void)ra;
    move_memory_segment(*rb, *rc);
}

/*/ Stores the value located within the word into a register located within the word
 * @param ra        register a
 * @param value     value to be loaded into ra
 */
void load_value(REGISTER* ra, WORD_SIZE value){
    *ra = value;
}

/*/ Instructions Array*/
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
