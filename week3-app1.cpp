// primitive types
// pointers
// pointers to pointers
// address of a variable (& operator)
// sizeof

// C has malloc and free for dynamic memory handling.
// C++ has new/delete. (C++ old dialects use these, older than C++'11 - 2011)
// destructors

// Vector object with dynamic dimensions
// print function for Vector
// static variables, static member variables
// Generic Programming = Templates in C++
// curly bracket usage for deeper lower scopes

// auto, AAA rule (almost always auto)

#include <iostream>
#include "memory.h"

int main(int argc, char* argv[])
{
    int a = 11;
    int* a_ptr = &a;
    int** a_ptr_ptr = &a_ptr;

    a = 20;
    *a_ptr = 30;
    **a_ptr_ptr = 40;
    // a_ptr[0] =

    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(int*) << std::endl;
    std::cout << a << std::endl;
    std::cout << a_ptr << std::endl;

    // int k[10];


    int* k = (int *)malloc(10 * sizeof(int)); // malloc returns void*
    std::cout << k << std::endl;
    free(k);

    k = new int[100];
    std::cout << k << std::endl;
    delete[] k;

    return 0;
}
