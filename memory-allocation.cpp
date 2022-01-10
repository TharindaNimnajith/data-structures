/*
Difference between Static and Dynamic Memory Allocation in C++

Memory Allocation:
Memory allocation is a process by which computer programs and services are
assigned with physical or virtual memory space. The memory allocation is done
either before or at the time of program execution. There are two types of
memory allocations:
  01. Compile-time or Static Memory Allocation
  02. Run-time or Dynamic Memory Allocation

Static Memory Allocation:
Static Memory is allocated for declared variables by the compiler. The address
can be found using the address of operator and can be assigned to a pointer.
The memory is allocated during compile time.

Dynamic Memory Allocation:
Memory allocation done at the time of execution (run time) is known as dynamic
memory allocation. Functions calloc() and malloc() support allocating dynamic
memory. In the Dynamic allocation of memory space is allocated by using these
functions when the value is returned by functions and assigned to pointer
variables.

Differences:
01. In the static memory allocation, variables get allocated permanently,
    till the program executes or function call finishes. In the Dynamic memory
    allocation, variables get allocated only if your program unit gets active.
02. Static memory allocation is done before program execution. Dynamic memory
    allocation is done during program execution.
03. Static memory allocation uses stack for managing the static allocation of
    memory. Dynamic memory allocation uses heap for managing the dynamic
    allocation of memory.
04. In static memory allocation, there is no memory re-usability (cannot reuse
    the unused memory).	In dynamic memory allocation, there is memory
    re-usability and memory can be freed when not required.
05. In static memory allocation, once the memory is allocated, the memory size
    can not change.	In dynamic memory allocation, when memory is allocated the
    memory size can be changed.
06. In static memory allocation scheme, execution is faster than dynamic memory
    allocation.
07. In static memory allocation scheme, memory is allocated at compile time. In
    dynamic memory allocation scheme, memory is allocated at run time.
08. In static memory allocation scheme, allocated memory remains from start to
    end of the program.	In dynamic memory allocation scheme, allocated memory
    can be released at any time during the program.
09. Static memory allocation example: array
    Dynamic memory allocation example: linked list
*/

// Creating array of objects on the stack and heap:

class MyArray
{
private:
    int i;

public:
    MyArray(int a) : i(a) {}
}
// stack
MyArray stackArray[100];
// heap
MyArray *heapArray = new MyArray[100];
delete[] heapArray;

// since c++11, there's a safe alternative to new[] and delete[] which is
// zero-overhead unlike std::vector
// vector is a dynamic array, which by default allocates elements from the heap
#include <vector>
std::vector<myarray> bestArray(100);
std::vector<myarray> bestArray{1, 2, 3};

// c++11
#include <memory>
std::unique_ptr<int[]> array(new int[size]);

// c++14
#include <memory>
auto array = std::make_unique<int[]>(size);

// dynamic array of integers
int size;
int *array = new int[size];

// using the Standard Template Library (simple, easy to use, no need to worry
// about memory allocations)
// http://www.cplusplus.com/reference/stl/vector/vector
// declare the size of the vector
int size = 5;
// create a vector to hold "size" int's all initialized to zero
vector<int> myvector(size, 0);
// assign values like a c++ array
myvector[0] = 1234;
