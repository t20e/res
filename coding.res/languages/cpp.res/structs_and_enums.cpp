#include <iostream>

using std::cout;


struct Student {
    std::string name;
    double gpa;
    bool enrolled = false;
};

struct Car {
    std::string model;
    int year;
    std::string color;
};

void printCar(Car &car);
void paintCar(Car &car, std::string color);


enum Day{
    Sunday=0, Monday=1, Tuesday=2, Wednesday=3,
    Thursday=4, Friday=5, Saturday=6, 
};


int main(){

    /*
        ---enums--- a user-defined data type that consists of paired named-integer constants.alignas

        Great if you have a set of potential options.
    */
    Day today = Monday;

    switch (today){
        case Sunday: cout << "Its Sunday\n";
            break;
        case Monday: cout << "Its Monday\n";
            break;
        case Tuesday: cout << "Its Tuesday\n";
            break;
        case Wednesday: cout << "Its Wednesday\n";
            break;
        case Thursday: cout << "Its Thursday\n";
            break;
        case Friday: cout << "Its Friday\n";
            break;
        case Saturday: cout << "Its Saturday\n";
            break;
    }



    /*
        --- Struct --- A structure that group related variable under one name Structs can contain many different data types (string, int, bool, double, etc..)

            Variables in a struct are known as "members"
            Members can be access with .(dot/period) "Class Member Access Operator"
    */

    Student student1;
    student1.name = "jon stuart";
    student1.gpa = 3.4;
    student1.enrolled = true;

    cout << student1.name << "\n" << student1.gpa << "\n" << student1.enrolled;

    /*
        Passing a struct into a function is PASS-BY-VALUE instead of PASS-BY-REFERENCE, which means we are creating a copy of the struct inside the function its passed to, but its still a address reference, however u can use the & to use the original struct "void printCar(Car &car)"
    */
    Car car1;
    Car car2;

    car1.model = "mustang";
    car1.year = 2022;
    car1.color = "red";
    
    car2.model = "corvet";
    car2.year = 1975;
    car2.color = "purple";


    paintCar(car1, "silver");
    printCar(car1);

    return 0;
}


void printCar(Car &car){
    cout << "\nAddress: " << &car;
    cout << "\n" << car.model << "\n" << car.color << "\n" << car.year;
}

void paintCar(Car &car, std::string color){
    car.color = color;
}