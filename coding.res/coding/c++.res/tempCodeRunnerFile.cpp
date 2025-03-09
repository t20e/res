#include <iostream>

using std::cout;

template <typename T, typename U>

// int max(int x, int y){
    //     return (x > y) ? x : y;
    // }

// T max(T x, U y){
//     return (x > y) ? x : y;
// }

auto max(T x, U y){
    return (x > y) ? x : y;
}

int main(){
    /*
    
        ----- function templates = describle what a function looks like.
            Can be used to generate as many overloaded functions as needed, each using different data types.

            *** we could make overloaded function for max with 3 different functions to handle when char or int or doubles are passed in or we can be more effiecent and use function templates

            a function template will accept any data type,

            we need to use template <typename T> to be able to do this


            *** Scenario: what if we need to use different datatypes in the same function, example below what if i need to pass in a double and an int instead of just 2 ints.

                Aadd template <typename T, typename U>

                Where T and U are the two type of data-types we can use
                We can also add auto to return either the T or U data-type, the compile will deduce what the return type should be.

    */

    cout << max(1, 2) << "\n";
    cout << max(1.1, 2.2) << "\n";
    cout << max('1', '2') << "\n";
    cout << max(1, 2.1) << "\n";












    return 0;
}