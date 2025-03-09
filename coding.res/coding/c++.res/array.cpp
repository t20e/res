#include <iostream>

using std::cout;


double getTotal(double prices[], int size); // this parameter when passed in as an argument will not be the actual array it will just be a pointer that points to where the array is stored, so the function wont know the size of the array unless its also passed in as an argument


int searchArray(int arr[], int size, int element);
void sortArr(int arr[], int size);


int main(){

    /*
        Arrays ---- are a data structure that can store multiple values, values are accessed by index
                   can only store values of the same data type
    
    */
    // std::string car = "corvette";// string
    std::string car[] = {"corvette", "mustang", "camry"}; // array
    cout << car; // will show the memory address of the array location

    car [0] = "porsche"; // will change the first element in the array to porsche

    cout << "\n" << car[0]; // will show the first element in the array
    cout << "\n" << car[2]; // will show the third element in the array

    std::string names[3]; // initialize empty array that can store 3 strings


    double prices[] = { 5.00, 7.50, 9.99, 15.00};

    cout << "\n" << prices[0]; // will show 5.00

    // sizeof() --- determines the size of the a varible, data type, class, object, etc.. in bytes
    cout << "\nSize of the array varible prices: " << sizeof(prices) << " in bytes\n"; // will show 32 bytes
    // the size of a string is always 32 bytes, to where the string text is located, a string is a reference data type

    char grade = 'f';
    cout << "\nSize of the char varible grade: " << sizeof(grade) << " in bytes\n"; // will show 1 byte

    cout << "\nSize of the array varible car: " << sizeof(car) << " in bytes\n"; 


    // we can use the size of an element to calculate how many elements are within an array
    int size = sizeof(prices) / sizeof(prices[0]);
    cout << "\nNum elements of the array prices: " << size << " elements\n"; // will show 4 elements
    
    cout << "\n You can also use the object type as divided by, prices varible has " << sizeof(prices) / sizeof(double) << " elements\n"; // will show 4 elements


    // ================== Iterating through an array ==================

    std::string students[] = {"SpongeBob", "Patrick", "Squidward", "bob"};

    for(int i = 0; i < sizeof(students) / sizeof(std::string); i++){
        cout << "\n" << students[i];
    }

    // ================== Foreach Loop =========================
    // loop that eases the traversal over an iterable data set
    // its less flexible than a for loop

    cout << "\n\n\nForeach";
    for(std::string student: students){
        cout << "\n" << student ;
    }

    
    int sizeForPrices = sizeof(prices)/sizeof(prices[0]);
    double total = getTotal(prices, sizeForPrices);
    cout << "\n\n Prices total $" << total;
    

    // ======================= Search an array
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sizeOfNumbers = sizeof(numbers)/sizeof(numbers[0]);
    int index;
    int myNum;

    cout << "\n\n\nenter element to search for in array\n";
    std::cin >> myNum;

    //search code below
    // index = searchArray(numbers, sizeOfNumbers, myNum);
    // if (index != -1){
    //     cout << "\n\nThe element: " << myNum << " is at index: " << index << " in the numbers array!\n\n";
    // }else{
    //     cout << "\n\nThe element: " << myNum << " is not in the numbers array!\n\n";
    // }



    // ============================= Sort Array
    // this is a bubble sort not the most effienct
    int nums[] = {56,156,516,78,471,1,456,89,123,849,123,894,123489,13489,1234,134,139,789,156};
    sortArr(nums, sizeof(nums)/ sizeof(nums[0]));



    //  fill() fills a range of elemets with a specified value

    std::string foods[100];
    cout << "\n\n\n PIZZA\n";
    fill(foods, foods + 100, "pizaa");
    for (int i = size - 1; i >= 0; i--) 
        {cout << foods[i] << ", ";}

    return 0;
}


double getTotal(double prices[], int size){ // this parameter when passed in as an argument will not be the actual array it will just be a pointer that points to where the array is stored, so the function wont know the size of the array unless its also passed in as an argument
    double sum = 0;

    for(int i = 0; i < size; i++){
        sum += prices[i];
    }

    return sum;
}


int searchArray(int arr[], int size, int element){
    for(int i = 0; i < size; i++){
        if (arr[i] == element){
            return i;
        }
    }
    return -1; // -1 used often for something wasnt found
}




void sortArr(int arr[], int size){

    cout << "\n\n\nSORINTG THIS ARRAY: ";
    for (int i = size - 1; i >= 0; i--) 
        {cout << arr[i] << ", ";}
    int temp;
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1; j++){
            if(arr[j] < arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }    
    }
    cout << "\n\n\SORTED ARRAY: ";
    for (int i = size - 1; i >= 0; i--) 
        {cout << arr[i] << ", ";}
}