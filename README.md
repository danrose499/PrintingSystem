Name        : final-project.cpp

Authors     : Sk Ayon, Daniel Lichter, Daniel Rosenthal

Final NAC Printing Project (Fall 2019)
============================================================================

The following is a virtual printing system that was written to emulate our school library's printing system.
Student and Admin classes (that inherit from a User base class) can have objects declared dynamically.
They are stored in a hash table (hashed from username) for 0(n) retrieval time.

Students can request to print, and their request is stored in a queue.
They can request to print from any of the printer objects.

Included are all of the relevant header files and the main CPP file.
