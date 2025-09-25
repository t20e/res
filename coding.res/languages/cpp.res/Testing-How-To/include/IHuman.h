#ifndef IHUMAN_H
#define IHUMAN_H
// Note the I before Human denotes that this is an interface.

#include <string>

// This is an INTERFACE that defines what out database can do.
class IHuman
{
public:
    // Virtual destructor is crucial for interfaces.
    virtual ~IHuman() {}

    // - VIRTUAL FUNCTIONS/METHODS is a member function that is declared within a base class and is re-defined (overridden)  by a derived class.
    //   When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class's version of the method.

    // Pure virtual functions define the "contract".
    virtual void Eat() = 0;
    virtual void Sleep() = 0;
};

#endif