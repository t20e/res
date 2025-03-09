#include<iostream>

using std::cout;

void printInfo(const std::string name, const int age);

int main(){
    /*
        ===== const parameter is read-only, makes code more secure and conveys intent 
        useful for references and pointers
    */
    std::string name = "Bro";
    int age = 21;

    printInfo(name, age);

    return 0;
}


void printInfo(const std::string name, const int age){
    cout << name << "\n";
    cout << age << "\n";
}