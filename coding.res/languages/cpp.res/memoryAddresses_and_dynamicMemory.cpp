#include <iostream>
#include <string>

using std::cout;
using std::string;

void swapByReference(std::string &x, std::string &y)
{
    string temp = x;
    x = y;
    y = temp;
}

void swapByValue(std::string x, std::string y)
{
    string temp = x;
    x = y;
    y = temp;
    cout << "\nIn swapByValue() the copies of x & y swapped: " << "x: " << x << " y: " << y << "\n";
}

/**
 * @brief Demonstrate Memory Addresses
 *
 * @return int
 */
int main()
{
    /*
        ---Memory Address---: A location in memory where data is stored, a memory address can be accessed with & (address-of operator) for example $name.

        * Pass-by-Value: When you pass arguments to functions by value i.e., name instead of $name, the function receives a COPY of the original variables data. Any changes made to that copy will not affect the original.

        * Pass-by-Reference: Passing arguments by reference gives the function an alias or direct reference to the original variable's memory location. The function works directly on the original data.
    */

    std::string name = "Bro";
    int age = 21;
    bool student = true;

    cout << "--- Memory Addresses ---\n";
    cout << "Address of the name variable: " << &name << "\n";
    cout << "Address of the age variable: " << &age << "\n";
    cout << "Address of the student variable: " << &student << "\n";


    std::string x = "Kool-Aid";
    std::string y = "Water";

    cout << "\n\n--- Demonstrating Pass by Value ---\n";
    cout << "\n-- Before swapByValue() --\n";
    cout << "x:" << x << "\n";
    cout << "y:" << y << "\n";

    swapByValue(x, y);
    cout << "\n-- After swapByValue() --\n";
    cout << "x:" << x << "\n";
    cout << "y:" << y << "\n";
    cout << "\nConclusion: The original x and y DON'T swapped, only the copies inside the swapByValue() function swapped.\n";


    cout << "\n\n--- Demonstrating Pass by Reference ---\n";
    cout << "\n-- Before swapByReference() --\n";
    cout << "x:" << x << "\n";
    cout << "y:" << y << "\n";

    swap(x, y);
    cout << "\n-- After swapByReference() --\n";
    cout << "x:" << x << "\n";
    cout << "y:" << y << "\n";
    cout << "Conclusion: the ORIGINAL x and y swapped.\n";



    /*
        --- Dynamic memory: --- is memory that is allocated after the program is already compiled & running. use the 'new' operator to allocate memory in the heap rather than the stack.

            * Useful when we don't know how much memory we will need. Makes our programs more flexible, especially when accepting user inputs.
    */ 

    int *pNum = NULL;

    pNum = new int; // the new operator will return an addres and we store it in pNum, pNum is a pointer

    *pNum = 21;


    cout << " address: " << pNum <<  "\n";
    cout << "values: " << *pNum << "\n";


    /* 
        --- It's good practice to free up the memory at that address when its no longer needed, so we delete pNum, if you dont you may cause a memory leak

        so whenever you use the new operator best practice to use a delete operator when that variable is no longer needed.
    */
    delete pNum;



    /* Dynamic memory with arrays

    When working with arrays if we know how big the array will be then theres no point in creating dynamic memory for the array, dynamic memory is only useful when we dont or wont know the size of the array.
    */
    char* pGrades = NULL;
    int size;

    cout << "\nHow many grades to enter in?: ";
    std::cin >> size;

    pGrades = new char[size];

    for(int i = 0; i < size; i++){
        cout << "Enter Grade #" << i + 1 << ": ";
        std::cin >> pGrades[i];
    }

    cout << "Print out the newly added grades\n";
    for(int i = 0; i < size; i++){
        cout << pGrades[i] << " ";
    }
    delete[] pGrades;


    return 0;
}
