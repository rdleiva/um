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
#define REGISTER_SIZE uint32_t;
#define WORD_SIZE uint32_t;

/*/ If rc is not equal to zero then ra gets the value at rb.
 * No move is performed otherwise
 * @param ra        register a 
 * @param rb        register b
 * @param rc        register c
 */
void conditional_move(REGISTER_SIZE* ra, REGISTER_SIZE* rb, REGISTER_SIZE* rc){
    if(*rc != 0) *ra = *rb;
}

/*/ Loads value in memory segment identified by rb and word offset rc into ra
 * @param seg_mem   memory segment
 * @param ra        register a
 * @param rb        register b
 * @param rc        register c
 */
void load(Segment_T mem_seg, REGISTER_SIZE* ra, REGISTER_SIZE* rb, REGISTER_SIZE* rc){
    *ra = load_memory_segment(mem_seg, *rb, *rc);
}

/*/ Store value in rc into segment identified by ra at the word offset of rb
 * @param mem_seg   memory segment
 * @param ra        register a
 * @param rb        register b
 * @param rc        register c
 */
void store(Segment_T mem_seg, REGISTER_SIZE* ra, REGISTER_SIZE* rb, REGISTER_SIZE* rc){
    store_memory_segment(mem_seg, *ra, *rb, *rc);
}

/*/ Adds value in rb and rc and then stores value into ra
 * @param ra        register a
 * @param rb        register b
 * @param rc        register c
 */
void add(REGISTER_SIZE* ra, REGISTER_SIZE* rb, REGISTER_SIZE* rc){
    *ra = (*rb + *rc);
}

/*/ Multiplies the values in rb and rc and stores the product into ra
 * @param ra        register a
 * @param rb        register b
 * @param rc        register c
 */
void multiply(REGISTER_SIZE* ra, REGISTER_SIZE* rb, REGISTER_SIZE* rc){
    *ra = (*rb * *rc);
}

/*/ Divides the values in ra and rb and stores the result into ra
 * @param ra        register a
 * @param rb        register b
 * @param rc        register c
 */
void divide(REGISTER_SIZE* ra, REGISTER_SIZE* rb, REGISTER_SIZE* rc){
    assert(*rc != 0);
    *ra = (*rb / *rc);
}

/*/ Bitwise AND on rb and rc, then bitwise NON on the outcome  and stores value into ra
 * @param ra        register a
 * @param rb        register b
 * @param rc        register c
 */
void nand(REGISTER_SIZE* ra, REGISTER_SIZE* rb, REGISTER_SIZE* rc){
    *ra = ~(*rb & *rc);
}

/*/ Stops program */
void halt(){
    exit(EXIT_SUCCESS);
}

/*/ Creates new memory segment of length rc and stores it's identifier into rb
 * @param mem_seg   memory segment
 * @param rb        register b
 * @param rc        register c
 */
void map_segment(Segment_T mem_seg, REGISTER_SIZE* rb, REGISTER_SIZE* rc){
    *rb = map_memory_segment(mem_seg, *rc);
}

/*/ Unmaps the memory segment identified by rc
 * @param mem_seg   memory segment
 * @param rc        register c
 */
void unmap_segment(Segment_T mem_seg, REG_SIZE *reg_c){
    unmap_memory_segment(mem_seg, *rc);
}

/*/ Displays the value in rc on the I/O device if it is in the range of 0-255
 * @param rc        register c
 */
void output(REGISTER_SIZE* rc){
    fprintf(stdout, "%c", (char)(*rc));
}

/*/ UM waits for input on I/o device and when it arrives it is stored
 * in rc if it's in the range of 0-255. 
 * @param rc        register c
 */
void input(REGISTER_SIZE* rc){
    *rc = fgetc(stdin);
    if(*rc == (unsigned)EOF) *rc = ~0;
}

/*/ Loads memory segment identified by rb and creates a copy to replace the content
 * of memory segment 0 which is abandoned.  Program counter is then set to point to
 * the memory segment stored at memory segment 0 at the word offset of rc
 * @param mem_seg   memory segment
 * @param rb        register b
 * @param rc        register c
 */
void load_program(Segment_T mem_seg, REGISTER_SIZE* rb, REGISTER_SIZE* rc){
    if(*rb != 0) move_memory_segment(mem_seg, rb, 0);
    (void) rc;
}

/*/ Stores the value located within the word into a register located within the word
 * @param ra        register a
 * @param word      word
 */
void load_value(REGISTER_SIZE* ra, WORD_SIZE value){
    *ra = value;
}