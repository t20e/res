# C++ Pointers, Memory Address & Dynamic Memory

## Pointers

Pointers are variables that store a memory address of another variable.

- `&` Address-of operator
- `*` Dereference operator

### Creating A Point

To create a variable that points to the variable above, we use the following convention:

1. Use the letter `p` to denote it as a pointer.
2. Use the `*`
3. Use the `&` to assign it the address for where its pointing to.

```c
std::string name = "Tony";

std::string *pName = &name;

std::cout << pName; // Will print the address of variable `name`.

std::cout << *pName; // Will print the value of the variable `name`
```

### Arrays

An array variable acts like a pointer to its first element, so there's no need to create a separate pointer to access it.

```c
std::string freePizzas[5] = {"pizza1", "pizza2", "pizza3", "pizza4", "pizza5"};
std::cout << *freePizzas; // Will print the value of the first element: "pizza1"
```

### Null value

A null pointer is a pointer that doesn't point to any valid object. The `nullptr` keyword represents this.

```c
int *pointer = nullptr; // Assigned to a null pointer
int x = 123;
pointer = &x;
// <-NOTE->: Dereferencing a null pointer like below line, will lead to undefined behavior (often a crash)!
*pointer; 

// So we check to see if the pointer is a null pointer for safe coding, instead of `*pointer`
if (pointer == nullptr){}

```

## Memory Address

A Memory Address is a location in memory where data is stored, a memory address can be accessed with `&`.

- **Pass-by-Reference:** Passing arguments by reference gives a function the alias or direct reference to the original variable's memory location. The function works directly on the original data.

- **Pass-by-Value:** When you pass arguments to a function by value, i.e., the function receives a **COPY** of the original variables data. Any changes made to that copy will not affect the original.

**Getting Variable Addresses:**

```c
bool student = true;
std::cout << "--- Memory Addresses ---\n";
std::cout << "Address of the student variable: " << &student;
// &student returns the address of variable student
```

**For Functions:**

```c
void swapByReference(int &x, int &y)
{ // the &x, &y means that we are passing the original variables x, y instead of copies
    int temp = x;
    x = y;
    y = temp;
}

void swapByValue(int x, int y)
{ // Passing copies of x and y
    int temp = x;
    x = y;
    y = temp;
    std::cout << "\nIn swapByValue() the COPIES of x & y swapped: " << "x: " << x << " y: " << y << "\n";
}
int x = 1; // original
int y = 0; // original

swapByValue(x, y); // The original above DON'T change!

swapByReference(x, y); // The original above DO change!
```

## Dynamic Memory

Dynamic memory is memory that is allocated after the program is already compiled & running. Use the `new` operator to allocate memory in the heap rather than the stack.

- Useful when we don't know how much memory we will need. Makes our programs more flexible, especially when accepting user inputs.

```c
int *pNum = nullptr;

// The `new` operator will return an address and we store it in pNum, pNum is a pointer.
pNum = new int;
*pNum = 21;
std::cout << " address: " << pNum <<  "\n";
std::cout << "values: " << *pNum << "\n";

// NOTE:
//      It's good practice to free up the memory when we no longer need that memory, so we delete pNum, if you don't it may cause a memory leak.
delete pNum;
```

- NOTE: In modern C++, the manual use of `new` and `delete` are rare, the newer method is to use smart pointers, which automatically free the memory when they are no longer needed.

    ```c
    std::unique_ptr<int> pNum = std::make_unique<int>(21);
    // No `delete pNum` is needed!
    ```

**Dynamic Memory With Arrays:**

- We only use dynamic memory wth arrays if we wont know the size of the array when it's later created.

```c
char *pGrades = nullptr; // Initialize pointer to null
int size; // To ask the user how many grades to enter in pGrades.

std::cout << "\nHow many grades to enter in?: ";
std::cin >> size; // ask user

pGrades = new char[size]; // Create a dynamic array with the user specified size. 
for (int i = 0; i < size; i++)
{
    std::cout << "Enter Grade #" << i + 1 << ": ";
    std::cin >> pGrades[i];
}

std::cout << "Print out the newly added grades\n";
for (int i = 0; i < size; i++)
{
    std::cout << pGrades[i] << " ";
}
delete[] pGrades; // Free up the memory. Same note as above ->  `NOTE: In modern C++...`
```
