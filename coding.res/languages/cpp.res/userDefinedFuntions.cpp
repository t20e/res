#include <iostream>

using std::cout; // for all function to be able to cout


void happyBirthday(std::string name, int age); // this declares the functon but we can define the content of the function after the main function this is more readable and organized, the code is ran from top to bottom so that when the function is envoked the compiler will know what the function is


// ---- RETURN keyword - used to return a value from a function
double square(double length);

std::string concatStrings(std::string firstName, std::string lastName);

// ---- Overload Functions - functions with the same name but different parameters
/*
    ******* A functions name plus its parameters is called its signature *****
*/
void bakePizza();
void bakePizza(std::string topping1);
void bakePizza(std::string topping1, std::string topping2);

/*
    Local varibles are declared inside a function and are only accessible inside that function
    Global variables are declared outside of any function and are accessible to all functions

    1. best to not use global varibles and its more safe to use local varibles
    2. if a varible is declared in the global scope and in the function scope the function will use the local first before the global
    3. or if you want to use the global varible you can use the scope resolution operator :: to access the global varible 
*/
int theBestNumber = 7;

int main(){

    using std::cout;

    std::string name = "bro";
    int age = 25;

    happyBirthday(name=name, age=age);


    double len = 27.0;
    double area = square(len=len);
    cout << "Area: " << area << '\n';


    std::string firstName = "Jon";
    std::string lastName = "Doe";

    std::string fullName = concatStrings(firstName=firstName, lastName=lastName);
    cout << "Full Name: " << fullName << '\n';

    bakePizza();
    bakePizza("pepperoni");
    bakePizza("pepperoni", "sausage");


    cout << "The best number is: " << theBestNumber << '\n';

    int bestTime = 10;

    return 0;
}
 

void happyBirthday(std::string birthBoi, int age){
    std::cout << "Happy Birthday! " << birthBoi;
    cout << "\nYou are now " << age << " years old!" << '\n';
} 

double square(double length){
    int bestTime = 10;// local variable not the same as the main function bestTime
    return length * length;
}

std::string concatStrings(std::string firstName, std::string lastName){
    return firstName + " " + lastName;
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