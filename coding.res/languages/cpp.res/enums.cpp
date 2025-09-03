#include <iostream>

using std::cout;

 
enum Day{
    Sunday=0, Monday=1, Tuesday=2, Wednesday=3,
    Thursday=4, Friday=5, Saturday=6, 
};



int main(){
         
    /*
        enums = a user-defined data type that consists oof paired named-integer constants.alignas

        Great if you have a set of potential options.
 
    */
    // std::string today = "Sunday"; //you can use a string in a switch
    Day today = Monday;

    switch (today){
        case Sunday: cout << "Its Sunday";
            break;
        case Monday: cout << "Its Monday";
            break;
        case Tuesday: cout << "Its Tuesday";
            break;
        case Wednesday: cout << "Its Wednesday";
            break;
        case Thursday: cout << "Its Thursday";
            break;
        case Friday: cout << "Its Friday";
            break;
        case Saturday: cout << "Its Saturday";
            break;
    }



    return 0;
}