#include <iostream>

using std::cout;

// ----- Function templates provide a blueprint for a function, allowing it to work with different data types without requiring you to write multiple overloaded functions.

// The template keyword is used to define a function template.
//  `typename T` and `typename U` are template parameters, which are placeholders for any data type (e.g., int, double, char, etc.).
template <typename T, typename U>


// This function template will return the larger of two values of potentially different data types. The 'auto' keyword for the return type allows the compiler to automatically deduce the return type based on the types of the arguments passed to the function.
auto max(T x, U y) {
    return (x > y) ? x : y;
}



/* --- Overload Functions --- are functions with the same name but different parameters.
    A functions name plus its parameters is called its SIGNATURE.
*/
void bakePizza();
void bakePizza(std::string topping1);
void bakePizza(std::string topping1, std::string topping2);


int main(){
    /*
      A function template allows you to write a generic function that can
      work with various data types. This is more efficient than creating
      a separate overloaded function for each data type combination,
      such as one for int, one for double, etc.
     */
    
    cout << "Using max(int, int): " << max(1, 2) << "\n";
    cout << "Using max(double, double): " << max(1.1, 2.2) << "\n";
    cout << "Using max(char, char): " << max('1', '2') << "\n";
    cout << "Using max(int, double): " << max(1, 2.1) << "\n"; // Demonstrates different data types

    cout << "\nC++ version: " << __cplusplus << "\n";

    return 0;
}

void bakePizza(){
    cout << "Here is your pizza" << '\n';
}
void bakePizza(std::string topping1){
    cout << "Here is your pizza toppings"<< topping1 << '\n';
}
void bakePizza(std::string topping1, std::string topping2){
    cout << "\n\n\nHere are your two pizza toppings " << topping1 << " and " << topping2 << '\n';
}