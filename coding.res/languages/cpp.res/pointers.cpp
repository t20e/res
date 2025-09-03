#include <iostream>

using std::cout;


int main(){
    /* ------------- pointers = variable that stores a memory address of another variable sometimes it's easier to work with an address

        & address-of operator
        * dereference operator
    */

    std::string name = "Tony";

    /*
        when making pointers its common to name it p then add the varibel where the pointer is "pName" below 
        and to also use the same date-type as the varible for the pointer, ex std::string for varible name and pointer pName they are both variables;
    */ 

    std::string *pName = &name;

    cout << pName << "\n"; // will print the address of the variable name
    cout << *pName << "\n"; // will print the value at the varible name with the dereference operator *



    int age = 21;
    int *pAge = &age;

    cout << age << "\n";
    cout << pAge << "\n";



    // arrays variable store the memory address so theres no need to make a pointer for a varible name
    std::string freePizzas[5]  = {"pizza1", "pizza2", "pizza3","pizza4", "pizza5"};
    cout << *freePizzas; // will give the first index of the array pizza1



    /*
        -------- Null Value pointers = a special value that means something has no value.
                When a pointer is holding a null value,
                that pointer is not pointing to anything ( null pointer)
            
            nullptr = keyword represents a null pointer literal

            nullptrs are helpful when determining if an address was successfully assigned to a pointer.
    */
    int *pointer = nullptr; // assigned to a null pointer
    int x = 123;

    pointer = &x;

    // *pointer; // if you deference a null pointer it can lead to undefined behavoir
    //so we check to see if the pointer is a null pointer for safe coding

    cout << "\n\n\n\nNull pointers\n\n";
    if(pointer == nullptr){
        cout << "Address was not assinged" ;
    }else{
        cout << "Address was assinged\n" ;
        cout << *pointer;
    }
    


    


    


    


    


    
    return 0;


}