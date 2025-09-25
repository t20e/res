#include "iostream"

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    if (a == 0 || b == 0)
    {
        throw std::invalid_argument("Division by zero!");
    }
    return a / b;
}

int confirmNum(int a)
{
    // Argument a must equal 5;
    if (a == 5)
    {
        return true;
    }
    return false;
}

bool is_even(int number){
    return (number % 2) == 0;
}
