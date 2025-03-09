#include <iostream>

using std::cout;


int main(){

    /*
        ------ dynamic memory = memory that is allocated after the program is already compiled & running. use the 'new' operator to allocate memory in the 
        heap rather than the stack

            Useful when we don't know how much memory we will need. Makles out programs more flexible, especially when accepting user inputs.

    */ 

    int *pNum = NULL;

    pNum = new int; // the new operator will return an addres and we store it in pNum, pNum is a pointer

    *pNum = 21;


    cout << " address: " << pNum <<  "\n";
    cout << "values: " << *pNum << "\n";


    /* ------- It's good practice to free up the memory at that address when its no longer needed, so we delete pNum, if you dont you may cause a memory leak

        so whenever you use the new operator best practice to use a delete operator when that variable is no longer needed.
    */
    
    delete pNum;



    /* ---- Arrays

    When working with arrays if we know how big the array will be then theres no point in creating dynamic memory for the array, dynamic memory is only useful when we dont/wont know the size the array can become.

    */
    char* pGrades = NULL;
    int size;

    cout << "How many grades to enter in?: ";
    std::cin >> size;


    pGrades = new char[size];


    for(int i = 0; i < size; i++){
        cout << "Enter Grade #" << i + 1 << ": ";
        std::cin >> pGrades[i];
    }

    for(int i = 0; i < size; i++){
        cout << pGrades[i] << " ";
    }
    delete[] pGrades;






    return 0;
}