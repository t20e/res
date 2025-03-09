#include <iostream>

int main(){
    using std::cout;

    std::string name;

    // if (name.empty()){
    //     cout << "Enter a name" << '\n';
    //     getline(std::cin, name);
    // } else {
    //     cout << "Hello " << name << '\n';
    // }


    // ----- WHILE LOOP
    // while (name.empty()){
    //     cout << "Enter a name" << '\n';
    //     getline(std::cin, name);
    // }

    // cout << "Hello " << name << '\n';
    


    // ----- DO WHILE LOOP
    // do some code first then check the conditions
    int number;
    
    do{ // do this code once then check the condition at the bottom
        cout << "Enter a positive number: ";
        std::cin >> number;
    }while(number < 0);


    cout << "You entered: " << number << '\n';




    return 0;



}