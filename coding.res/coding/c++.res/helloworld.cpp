/*
----- C++ Resouce

C++ is a lower level language; its below python but above machine languages like ASM

We need to translate our human code to machine code we do this with a compiler, Clang is one.

----- Whenever we need to run out code, the compiler translates the code into machine code then it runs it.
1. To compile a file run this command
$ clang++ fileName.cpp -o outputFileName
2. then run it with
$ ./outputFileName

    ** you can also use different versions to compile it below is version 14
        $ g++ -std=c++14 functionTemplates.cpp -o functionTemplates





*/


#include <iostream>
#include <vector> // for typedef
#include <cmath>
namespace first{
    int x = 201;
}

namespace second{
    int x = 2;
}
namespace grades{
    int grade = 75;
}


// TYPEDEF instead of having to write this line everytime "std::vector<std::pair<std::string" we create an alias to the name pairlist_t the "_t" is the convention to show that it is a typedef, example below in the  ----- typedef
typedef std::vector<std::pair<std::string, int> > pairlist_t;
// typedef std::string text_t;
// ALSO typedef has been replaced by the using keyword, example in the following line
using text_t = std::string;

int main(){

    // this is a comment

    /*
        this is a multi-line comment
    */ 
    using namespace first; // this will override the x varible by using the first namespace  above

    using std::cout; // this will allow us to use cout without the std:: prefix, however be careful if you use just std it will bring in that whole library from std


    std::cout << "Hello World! :)" << std::endl; // when we need to make the output of a print go to the next line we put a "<< std::end;" after the first cout, or you can use '\n' instead of std::endl
    std::cout << "bad apples:)" << '\n';
    std::cout << "good apples:)" << '\n';



    // ----- INTEGER (int) - stores a whole number
    int x; // this is a variable declaration
    x = 5; // this is a variable assignment
    std::cout << x << std::endl;
    int y = 10;
    std::cout << y<< '\n';
    int sum = x + y;
    std::cout << sum << '\n';
    int age = 25;



    // ----- DOUBLE (double) - stores a decimal number
    double price = 10.99;
    double gpa = 3.5;
    double temperature = 25.1;
    std::cout << price << '\n';
    

    // ----- CHARACTER (char) - stores a single character
    char grade = 'A';
    char firstInitial = 'D';
    std::cout << "Grade: ";
    std::cout << grade << '\n';


    // ----- BOOLEAN (bool) - stores true or false
    bool isRaining = false;
    std::cout << "Is it raining? ";
    std::cout << isRaining << '\n';


    // ----- STRING (std::string) - stores a sequence of characters, is an object
    std::string name = "Tony";
    std::string day = "Monday";
    std::cout << '\n' << "Hello " << name << '\n' ;
    std::cout << "You are " << age << " years old" << '\n';


    // ----- CONSTANTS (const) - a value that cannot be changed, it is read only
    const double PI = 3.14159;
    double radius = 10;
    double circumference = 2 * PI * radius;

    std::cout << "Circumference: " << circumference << "cm" << '\n';

    const int LIGHT_SPEED = 299792458;
    const int WIDTH = 1200;




    // ----- NameSpace - provides a soultion for prevennting naming conflicts in large projects, you can use namespace for two enitys with the same name
    std::cout << '\n' << "NAME SPACE:" << '\n';
    std::cout << x << '\n';
    std::cout << first::x << '\n';
    std::cout << x << '\n';
    cout << "hello new print" << '\n';




    // ----- typedef reserved keyword used toc create an additional name (alias) for another data type new identifier for an exisdting type , helps with readablitiy and typos'
    cout << '\n' << "Typedef:" << '\n';
    pairlist_t pairlist;
    text_t firstName = "ben"; // this is shorter and does the same thing as this line std::string firstName = "Ben";
    cout << "first name: "  << firstName << '\n';



    // ----- Arithmetic Operators - return the result of a specific arthmetic opertation ( + - * / %)
    cout << '\n' << "Arithmetic Operators:" << '\n';
    int students = 20;
    // students = students + 1;
    students += 2;
    students++; // increment by 1
    students-= 5;
    students--; // decrement by 1

    // students = students * 2;
    students *= 2;
    students /=2;
    students /=5; // since students is an int any decimal points will be truncated
    cout << "students: " << students << '\n';

    int remainder = students % 2; // divide the students into groups of 2 and return the remainder
    cout << "remainder: " << remainder << '\n';

    // useful math funtions in c++
    // more useful ref here https://cplusplus.com/reference/cmath/#google_vignette
    double f = 3;
    double g = 2;
    double z;
    // z = std::max(x, y);
    // z = std::min(f, g);
    // z = pow(2, 3);
    // z = sqrt(25);
    // z = abs(-5); // will give positive of a negative number
    z = round(first::x);
    cout << "Z: " << z << '\n';




    // ----- TYPE CONVERSION - converting one data type to another
    /*
        Implicit - done automatically by the compiler
        Explicit - done manually by the programmer
    */
   double p = (int) 3.14;
   cout << "p: " << p << '\n'; 

    char m = 100;
    cout << "m: " << m << '\n'; // the char 100 converted to a char is the letter 'd'
    cout << (char) 100 << '\n';

    int correct = 8;
    int questions = 10;
    double score = correct/ (double) questions * 100; // without the double conversion it would return 0.0 because it would truncate the decimal after doing 8/10
    cout << "score: " << score << '\n'; 

    // ----- USER INPUT - getting input from the user

    // text_t nameInput;
    // cout << "Enter your name: ";
    // std::getline(std::cin, nameInput); // this will get the whole line of input from the user, vs the following line would skip the next input if the string contained a space
    // // std::cin >> nameInput;
    // cout << "Hello " << nameInput << '\n';
    // int age2;
    // cout << "Enter your age: ";
    // std::cin >> age2;
    // cout << "You are " << age2 << " years old" << '\n';


    
    // ----- TERNARY OPERATOR
    grades::grade >= 60 ? cout << "YOU PASS" : cout << "Fail";
    bool isNice = false;

    isNice ? cout << "You are nice" : cout << "You are not nice";


    // ----- Logical Operators - used to combine conditional statements
    /*
        && - AND - both conditions must be true
        || - OR - either condition must be true
        ! - NOT - reverses the result
    */
    int temp = 55;
    cout << '\n';
    if (temp > 12 && temp < 30){
        cout << '\n' << "The temperature is good\n";
    } else if (temp > 30 || temp < 12){
        cout << "The temperature is bad\n\n\n :)" ;
    } else {
        cout << "The temperature is ok" << '\n';
    }
    

    return 0; // if we reach this point, the function has finished successfully if a 1 is returned that a problem occured
}

