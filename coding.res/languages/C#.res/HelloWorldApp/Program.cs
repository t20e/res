// See https://aka.ms/new-console-template for more information

// Write to console
Console.WriteLine("Hello World!");

// --------------------------------------------------------------------------
// === Variables ===
// --------------------------------------------------------------------------

// Declaring Variables/Constants
int number; // An empty variable that stores an integer
int Number = 1; // A variable that stores an integer
// NOTE: C# is case-sensiteve meaning these two variables above are two different variables (number != Number)
short num = 10;
Console.Write("\n num variable: " + num + " which is a short type");

// Create a constant (value cannot be changed)
const float Pi = 3.14f;

// Real Numbers
float x = 1.2f; // The 'f' suffix is needed for a float literal
decimal X = 1.2m; // The 'm' suffix is needed for a decimal literal

byte ir = 1; // stores 1 byte
int l = 1; // stores 4 bytes

// Non-Primitive Types: String, Array, Enum, & Class

// The Byte is an immutable value type with a range of 0 to 255.
byte y = 255;
Console.WriteLine("byte type: " + y);

// --------------------------------------------------------------------------
// === Scope ===
// --------------------------------------------------------------------------
{
    byte a = 1;
    {
        // byte b = 2;
        // Console.WriteLine(b); // Variable b is not accessible here (uncommenting this would work if b were outside the inner scope)
        byte b = 2; // b is accessible inside its scope and nested scopes
        {
            Console.WriteLine(a + b); // Variable A and B are accessible here.
            byte c = 3;
            {
                Console.WriteLine(a + b + c); // Variables A, B, and C are accessible here.
            }
        }
    }
}



// --------------------------------------------------------------------------
// === The var Keyword ===
// --------------------------------------------------------------------------

// The `var` keyword lets the compiler infer the type.
var character = 'A'; // 'var' is inferred as char
Console.WriteLine("\nvar character type: " + character.GetType());

// --------------------------------------------------------------------------
// === String Formatting and Type Ranges ===
// --------------------------------------------------------------------------

Console.WriteLine("Formatted String -> byte min and max: {0} - {1}", byte.MinValue, byte.MaxValue);
Console.WriteLine("Formatted String -> float min and max: {0} - {1}", float.MinValue, float.MaxValue);
Console.WriteLine("Formatted String -> int min and max: {0} - {1}", int.MinValue, int.MaxValue);
Console.WriteLine("Formatted String -> long min and max: {0} - {1}", long.MinValue, long.MaxValue);

// --------------------------------------------------------------------------
// === Type Conversion ===
// --------------------------------------------------------------------------

// Implicit Conversion (safe, no data loss)
byte s = 1;
int i = s; // byte to int is a widening conversion

// Another example
int p = 1;
float f = p; // int to float is a widening conversion

// Explicit Conversion (casting, potential for data loss)
int q = 1;
// byte k = q; // This would not compile without a cast
byte k = (byte)q; // Casting is required here

// Note that casting can lead to data loss.
float ts = 1.2f;
int tb = (int)ts; // The decimal part is truncated
Console.WriteLine("\n\nCasting: before: {0} -> after casting: {1}, note we lost the .2", ts, tb);

// Converting between string and numeric types
string str = "1";
int io = Convert.ToInt32(str); // Converts a string to an integer
int j = int.Parse(str); // Also converts a string to an integer
Console.WriteLine("\n\nConverting from str to int -> str value: '{0}' -> converted value: {1} using Parse: {2}", str, io, j);


// --------------------------------------------------------------------------
// === Array & Lists ===
// --------------------------------------------------------------------------

/*
     Arrays:
        * Have a fixed size that is determined at the time of creation and cannot be changed.
        * Generally offer slightly better performance for direct element access due to their contiguous memory allocation.
    Lists:
        * is a dynamic data structure that can grow or shrink in size as elements are added or removed. It manages its underlying array automatically.
        * Flexibility: Provides built-in methods for common collection operations like adding, removing, searching, and sorting elements.
        * Ease of Use: More convenient for scenarios where the number of elements is unknown or changes frequently.
        * Underlying Implementation: List<T> is implemented using an array internally, and it reallocates a larger array when its capacity is exceeded.

*/
int[] numbers; // Declaration
numbers = new int[5]; // Allocation for 5 integers

string[] cars = { "Volvo", "BMW", "Ford" };

double[] prices = new double[3] { 10.5, 20.0, 5.75 };

Console.WriteLine(cars[0]); // Accesses the first element "Volvo"
numbers[2] = 100; // Assigns 100 to the third element

// Create a List of strings
List<string> fruits = new List<string>();

// Add elements to the list
fruits.Add("Apple");
fruits.Add("Banana");
fruits.Add("Cherry");

fruits.Remove("Apple"); // Remove first occurrence of the string "Apple"


// --------------------------------------------------------------------------
// === Try-Catch Blocks for Error Handling ===
// --------------------------------------------------------------------------

try
{
    var text = "1234";
    // This will cause an OverflowException as a byte's max value is 255
    byte b = Convert.ToByte(text);
    Console.WriteLine("\n\nTry Catch " + b);
}
catch (OverflowException) // Best practice: catch specific exceptions
{
    Console.WriteLine("\n\nTry Catch error. The number is too large to be converted into a byte.");
}
catch (FormatException)
{
    Console.WriteLine("\n\nTry Catch error. The string is not in a correct format for a number.");
}

// --------------------------------------------------------------------------
// === Functions and Return Types ===
// --------------------------------------------------------------------------

void VoidFunction()
{
    // A function with the `void` keyword does not return anything
    Console.WriteLine("\nRunning VoidFunction");
}
VoidFunction();

bool BoolFunction()
{
    // A function that returns a boolean (true or false)
    Console.WriteLine("\nRunning BoolFunction");
    return true;
}
Console.WriteLine(BoolFunction());

// --------------------------------------------------------------------------
// === Classes ===
// --------------------------------------------------------------------------

public class Person
{
    // `public` makes the member accessible from outside the class.
    public string Name;

    // `private` makes the member accessible only within this class.
    private short socialSecurityNumber = 123;

    // A class method
    public void Introduce()
    {
        Console.WriteLine("Hi, my name is " + Name);
    }
}

// NOTE: you cant instantiate here.
// Create an instance of the class
// var john = new Person();
// john.Name = "John";
// john.Introduce();

// --------------------------------------------------------------------------
// === Interfaces ===
// --------------------------------------------------------------------------

public interface ITaxCalculator // Use 'I' as a prefix for interface names
{
    // Interfaces define a contract. Classes that implement this interface
    // must provide a concrete implementation for this method.
    int Calculate();
}