#include <iostream>

int main(){
    using std::cout;
    
    std::string name;

    cout << "Enter your name: ";
    std::getline(std::cin, name);

    // if(name.length() > 12){
    //     cout << "Your name cant be longer than 12 characters long" << '\n';
    // }else{
    // }

    // name.empty() ? cout << "You didn't enter a name" : cout << "Hello " << name << '\n';
    // name.clear();
    // cout << "Hello " << name ;
    
    // name.append(" is a good person");
    // cout << name ;

    // cout << '\n' << "the char at index 1 is " << name.at(1);

    // name.insert(0, "Mr. ");t

    // cout << name.find(" ")  ; // returns the index of the first occurence of the string, if it doesn't find it it will return -1

    name.erase(0, 2);

    cout << name ;

    return 0;
}