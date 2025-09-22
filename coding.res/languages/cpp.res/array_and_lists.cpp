#include <iostream>
#include <list>
#include <string>


int main() {

    // --- Array ---
    // A fixed-size array declared at compile time. Its size cannot be changed.
    int fixedArray[5] = {10, 20, 30, 40, 50};

    std::cout << "--- Array ---" << std::endl;
    std::cout << "Elements of the fixed array: ";
    // Loop through the array and print each element
    for (int i = 0; i < 5; ++i) {
        std::cout << fixedArray[i] << " ";
    }
    std::cout << std::endl;

    // Accessing an element by its index
    std::cout << "The first element (index 0) is: " << fixedArray[0] << std::endl;
    std::cout << "The last element (index 4) is: " << fixedArray[4] << std::endl;

    std::cout << std::endl;



    // --- List ---
    // A dynamic array that can grow or shrink in size at runtime.
    std::list<std::string> names;

    std::cout << "--- Lists ---" << std::endl;

    // Add elements to the end of the list
    names.push_back("Charlie");
    names.push_back("David");

    // Add elements to the front of the list
    names.push_front("Alice");
    names.push_front("Bob");

    std::cout << "Initial list: ";
    // Use a range-based for loop to iterate through the list
    for (const std::string& name : names) {
        std::cout << name << " ";
    }
    std::cout << std::endl;

    // Remove the first element
    names.pop_front();
    std::cout << "After pop_front: ";
    for (const std::string& name : names) {
        std::cout << name << " ";
    }
    std::cout << std::endl;

    // Remove the last element
    names.pop_back();
    std::cout << "After pop_back: ";
    for (const std::string& name : names) {
        std::cout << name << " ";
    }
    std::cout << std::endl;

    // Insert an element at a specific position
    // You must use an iterator to point to the insertion spot
    std::list<std::string>::iterator it = names.begin();
    it++; // Move iterator to the second element ("Charlie")
    names.insert(it, "Frank");

    std::cout << "After inserting 'Frank': ";
    for (const std::string& name : names) {
        std::cout << name << " ";
    }
    std::cout << std::endl;

    // Remove a specific element by its value
    names.remove("David");
    std::cout << "After removing 'David': ";
    for (const std::string& name : names) {
        std::cout << name << " ";
    }
    std::cout << std::endl;


    // std::string cars[3][4]; // 3 rows 4 columns

    // 3 columns unspecified rows amount
    std::string cars[][3] = {
        {
            "mustang", "Escape", "f-150"
        }, 
        {
            "Corvette", "Equinox", "Silverado"
        },
        {
            "Challenger", "Durago", "Ram"
        }
    };


    // --- Multi-Dimensional Array
    std::cout << cars[0][2];

    std::cout <<"\n\n\n";
    int rows = sizeof(cars)/sizeof(cars[0]);
    int cols = sizeof(cars[0])/sizeof(cars[0][0]);

    for(int i = 0; i < rows; i++){
        std::cout << "\n\nAddress of nest array: #" << i << " Address: " << cars[i]; // will give the memory address for each of the row nest arrays         ex :{"mustang", "Escape", "f-150"        }
        std::cout << "\ncars in this array: ";
        for(int j = 0; j < rows; j++){
           std::cout << " " << cars[i][j];
        }

    }

    return 0;

}
