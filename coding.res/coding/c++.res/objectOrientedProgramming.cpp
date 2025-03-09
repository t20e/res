#include <iostream>
#include <cmath>

using std::cout;


class Human{

    /*
        ------- Object = A collection of attributes and methods, They have characteristics and could perform actions 

        Can be used to minic real world items

        Created from a class which acts as a "Blue-print"

        *** Attributes are characterists of an object like name, occupatio, and age below

        *** Methods are the functions that the object can perform like eat(), Drink(), sleep()


    */

    public: // public accesses-able
        std::string name = "rick"; // default attribute when we set the variable instead of leaving it undefined;
        std::string occupation;
        int age;

        void eat(){// method
            cout << "this person is eating";
        }
        void drink(){
            cout << "this person is drinking";
        }
        void sleep(){
            cout << "this person is sleeping";
        }

};
 

class Student{
    /*
        ------ Constructor = special method that is automatically called when an object is instantiated useful for assigning values to attributes as arguments
    
        C++ has a default constructor, but we can also make out own

    */
    public:
        std::string name;
        int age;
        double gpa;


    // constructor here
    Student(  std::string name, int age, double gpa){
        // When we instantiate a Student object we will automatically call this function
        this->name = name;
        this->age = age;
        this->gpa = gpa;
    }

};


class Car{
    public:
    std::string model;
    std::string color;
    std::string make;
    int year;
    
    
    Car(  std::string model, std::string color, std::string make, int year){
        this->make = make;
        this->color=color;
        this->year = year;
        this->model = model;
    }
};


class Pizza{

    /*
    Overloaded Constructors = multiple constructors w/ same name but different parameters allows for varying arguments when instantiating an object
    */
    public:
        std::string topping1;
        std::string topping2;

    Pizza(){}
    Pizza(std::string topping1){
        this->topping1 = topping1;
    }
    Pizza(std::string topping1, std::string topping2){
        this->topping1 = topping1;
        this->topping2 = topping2;
    }
   
};


/*
    ----- Abstraction = hiding unnecessary data from outside a class
    ----- Getter = function that makes private attribute READABLE
    ----- Setter = function that makes private attribute WRITEABLE
*/
class Stove{
    
    // you can also invoke the setters methods in the constructor of a class

    private: // this is the rule of abstraction, were hiding data from a user that they dont need, and we no longer have access to the temperature class from outside the class
        int temperature = 0;
    
    public:
    // int temperature = 0; // this is accessable from outside of the class since its in the public: domain, meaning people can change it

    int getTemperature(){
        return temperature;
    }
    void setTemperature(int temperature){
        if(temperature < 0){
            this->temperature = 0;
        }else if(temperature >= 10){
            this->temperature = 10;
        }else{
            this->temperature = temperature;
        }
    }

};


/*
    Inheritance = A class can recieve attributes and methods from another class 

        Children classes inherit from a Parent class
        helps to reuse similar code found within multiple classes
*/


class Animal{
    public:
        bool alive = true;


    void eat(){
        cout << "this animal is eating\n";
    }
};

// dog class is inherinting from the animal class
class Dog: public Animal{
    public:

    void bark(){
        cout << "the dog goes woof\n";
    }
};


class Cat : public Animal{
    public:


    void meow(){
        cout << " the cat goes meow\n";
    }
};



class Shape{
    public:
        double area;
        double volume;
};

class Cube : public Shape{
    public:
        double side;
    Cube(double side){
        this->side=side;
        this->area = side * side * 6;
        this->volume = pow(side, 3);
    }
};


class Sphere : public Shape{
    public:
        double radius;

    Sphere(double radius){
        this->radius=radius;

        this->area = 4 * 3.14159 * (radius * radius);
        this->volume = (4 / 3.0) * 3.14159 * pow(radius, 3);
    }
};


int main(){

    Human human1;

    human1.name = "rick";
    human1.occupation = "scientist";
    human1.age = 19;
    cout << human1.name << "\n";
    cout << human1.age << "\n";
    cout << human1.occupation << "\n";
    human1.drink();
    
    
    cout << "\n\n\n\nSTUDENT\n\n";
    Student student1("spongebob", 12, 4.1);
    cout << student1.name << "\n";
    cout << student1.age << "\n";
    cout << student1.gpa << "\n";
    
    
    cout << "\n\n\n\nCAR:\n\n";
    Car car1("corvette", "blue", "chevy", 2019);
    cout << car1.color << "\n";
    cout << car1.make << "\n";
    cout << car1.model << "\n";
    cout << car1.year << "\n";





    cout << "\n\n\n\nPizza:\n\n";
    Pizza pizza1("Cheese");

    Pizza pizza2("onions", "Mushrooms");


    Pizza pizza3;


    cout << pizza1.topping1 << "\n";
    cout << pizza2.topping2 << "\n";
    
    
    
    
    cout << "\n\n\n\nStove:\n\n";
    Stove stove1;
    cout << stove1.getTemperature() << "\n";
    stove1.setTemperature(5);
    cout << stove1.getTemperature() << "\n";
    
    
    
    cout << "\n\n\n\nInheritance:\n\n";
    Dog dog1;
    cout << "DOG alive:" << dog1.alive << "\n";
    dog1.eat();
    dog1.bark();



    Cat cat1;
    cat1.meow();




    cout << "\n\n\n\nShapes:\n\n";
    Cube cube1(10);
    cout << "Cube Area: " << cube1.area << "cm\n" << "Cube Volume: " << cube1.volume << "cm" << "\n\n\n";
    
    Sphere sphere1(5);
    cout << "sphere Area: " << sphere1.area << "cm\n" << "sphere Volume: " << sphere1.volume << "cm" << "\n";

    return 0;
}