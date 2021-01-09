# Sorting
You are to write three C++ programs.

The first program will be an implementation of insertion sort using linked lists to store
the data. Make sure your implementation is correct and efficient (for insertion sort). The
linked list must be implemented by you, and all movement in the lists must be done using
pointers. You must read the integers from the files and build a linked list in the order that
matches the file and then sort that linked list. You may not change what data is in any
node after the data is initially stored into a node.

The second program is an implementation of heapsort.
The third program will implement bottom up mergesort.

Use arrays or vectors for your heapsort and mergesort programs. You are not required to
use classes or objects for any of the programs other than a Node class or struct, though, of
course, you may. If you build a linked list class, put your sort inside that class. You are
expected to use reasonable program design – programs that have no functions except
main will do no better than a C. Note that your sorting functions are NOT to be
templated (I do not want you just copying code out of the book).

For each program, you are to read a file of integers (longs), sort them, and write them into
an output file. The input files will contain one integer per line, and the output files must
be in the same format. Your program will accept the names of the input and output files
as command line parameters. Your program must be able to handle files of up to at least
1,000,000 longs.

Hints for figuring out whether or not your programs work – check out the sort and diff
commands for Linux (they are covered in your Linux handout).
