#include<iostream>

using std::cout;

void swap(std::string &x, std::string &y);

int main(){
    /*
    ---- Memory address = a location in memory where data is stored, a memory address can be accessed with & (address-of operator)

    ---- pass by value is when u pass arguments into a function and inside the function it makes copeies of the value
        if u instead of to make changes to the original value, then u must pass the memory addess, this by passes the local varibles
    */

    std::string name = "Bro";
    int age = 21;
    bool student = true;

    cout << "Address of the name varible: " << &name << "\n";
    cout << "Address of the age varible: " << &age << "\n";
    cout << "Address of the student varible: " << &student << "\n";

    std::string x = "Kool-Aid";
    std::string y = "Water";

    swap(x, y);
    cout << "X: " << x;
    cout << "\nY: " << y;

    return 0;
}

void swap(std::string &x, std::string &y){
    std::string temp;
    temp = x;
    x = y;
    y=temp;
}