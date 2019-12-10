# um

Mikel F Gjergji & Rotman Daniel Leiva Henriquez
Professor Daniels
CSC411
Assignment #6
Universal Virtual Machine
December 2, 2019

Acknowledges help you may have received from or collaborative work you may have 
undertaken with others
	- We used Professor Daniels bitpack to do our bitpacking.

Identifies what has been correctly implemented and what has not
	- All of our modules have been implemented correctly and perform their intended function.

Briefly enumerates any significant departures from your design
	- One significant departure from our original design was the addition of a sequence to keep track of free memory segments.
	- The other significant change was the use of an array of functions instead of a struct of functions

Succinctly describes the architecture of your system. Identify the modules used, what abstractions they implement, what secrets they know, and how they relate to one another. Avoid narrative descriptions of the behavior of particular modules.
The um.c program will rely on instructions.h, registers.h, and segments.h interfaces to run the virtual machine.
- um calls the operation decoder to initialize program and run all instructions
- instructions.h interface will handle all of the 14 instructions functions available to give functionality to the virtual machine.
- registers.h interface will manage the 8 registers available to the virtual machine.
- segments.h interface will manage all the segments of memory when requested by the
virtual machine.Segments.h interface will also make use of Hanson’s sequence data structure to manage all memory segments which are arrays of words of size 32bits stored in uint32_t. Since Hanson sequences have indexing, the segment arrays will be identiﬁed by their corresponding index. Segment[0] will always be the current program running.
- The virtual machine um.c will call the begin_program function in operation_decoder module with the array of instructions loaded from the program file.
- Operation_decoder then runs intialize_registers and initialize_program function to initialize both the registers to zero, and load the program into segment 0.

Explains how long it takes your UM to execute 50 million instructions, and how you know
	- Our um runs in reasonable time of 3 seconds when ran against the midmark benchmark..

Says approximately how many hours you have spent analyzing the assignment
	- We spent about 4 hours analyzing the assignment.

Says approximately how many hours you have spent preparing your design
	- We spent about 4 hours preparing our design.

Says approximately how many hours you have spent solving the problems after your analysis
	- We spent about 12 hours solving implementation problems and trying to get the um to work.