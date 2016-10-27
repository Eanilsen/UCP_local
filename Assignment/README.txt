Assignment in Unix & C Programming (COMP1000)
Even A. Nilsen 18946147

sorting_assignment.c
The main file tying the program together. This is also the main target of the
makefile.

linked_list.c
My own implementation of a linked list data structure. It is a doubly linked list.

filereader.c
Handles file input and output.

util.c
Contains different utility functions. Is used by many of the other files.

insertion_sort.c
Faulty implementation of a generic insertion sort function. I was not able to fix
it in time. "make test" will build a testing executable for this file.

input.csv
A .csv file made for testing the program.

HELP.md
File made for easier formatting of the help target in the makefile.

Makefile
Working makefile for the program

Required functionality
The program successfully takes command line arguments and uses the flags ("-i" & "-o")
to differ between input and output files. It also reads from and writes to a file
after checking that the file format is correct. My implementation of the linked 
list is, to the best of my knowledge, working without problems. I attempted to
get the insertion sort function to work, but I regrettably did not.

Defects and bugs
Except for the insertion sort getting a segmentation error, the program is bugfree.

My code was tested on:
314.219 Service Tag: GFWZF2S
