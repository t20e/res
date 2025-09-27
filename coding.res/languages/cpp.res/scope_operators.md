# C++ scope operators (::) vs (.) vs (->)

**(::)** is the Resolution scope operator.

- Explicitly specify the namespace, class, or global scope that an identifier (name) belongs to.

**(.)** is the Member Access operator.

- Used to access members of an object instance when accessing the object directly **(not via a pointer, we use (->) for that)**. The object can be allocated on the stack or heap.

**(->)**

- Used for accessing members when using a pointer to an object (e.g., this->model).

```c++
#include <iostream>
#include <string>

// Using (::) for 'std::cout' explicitly grabs the `cout` object from the `std` namespace scope.
// The `using std::cout` is a using declaration that pulls the specific name `cout` into the current scope, allowing use to use `cout` without having to use the `std::` prefix.
using std::cout;
using std::endl;

// Global variable
int numCars = 100;

class Car
{
private:
    // Private member for each instance of a Car
    std::string model;

public:
    // Static member belongs to the Class type, to all instances of Car.
    static int total_cars;

    // Car constructor Declaration
    Car(std::string m);

    void displayCarInfo(int numCars)
    {
        // Local variable 'numCars'shadows the global 'numCars'
        cout << "Local function argument 'numCars' " << numCars << endl;

        // Use (::) to access the global variable 'numCars'
        cout << "Global 'numCars' " << ::numCars << endl;

        // Use (->) to access the instance variable 'model'
        cout << "Car instance model variable " << this->model << endl;

        // Use (::) to access the static class member 'total_cars'
        cout << "Car static variable total_cars " << Car::total_cars << endl;
    }
};

// Define a Static Member outside the Class Car
// The (::) operator is required to define the member that belongs to the 'Car' scope
int Car::total_cars = 0;

// Define a member function Constructor outside the Class Car
// The (::) operator is required to define the function that belongs to the 'Car' scope
Car::Car(std::string m)
{
    model = m;
    Car::total_cars++;
}

int main()
{
    // Create instances of Car
    Car car1("Honda");
    Car car2("Toyota");

    // Access the instance member 'displayCarInfo' using (.)
    cout << "\n--- Car 1 displayCarInfo() ---" << endl;
    car1.displayCarInfo(50);

    cout << "\n--- Car 2 displayCarInfo() ---" << endl;
    car2.displayCarInfo(10);

    return 0;
}
```


#### Run
```shell
# compile
clang++ i.cpp -o i
# Run executable
./i
```