#include <iostream>
#include <cmath>


int main(){
    using std::cout;

    // int age;

    // cout << "Enter your age: ";

    // std::cin >> age;

    // if (age >= 18){
    //     cout << "You are an adult" << '\n';
    // } else if (age >= 13){
    //     cout << "You are a teenager" << '\n';
    // } else {
    //     cout << "You are a child" << '\n';
    // }

    // ----- SWITCHES
    int month;
    cout << "Enter the month number (1-12): ";
    std::cin >> month;

    switch (month){
        case 1:
            cout << "January" << '\n';
            break;// need a breal tp stop switch
        case 2:
            cout << "February" << '\n';
            break;
        case 3:
            cout << "March" << '\n';
            break;
        case 4:
            cout << "April" << '\n';
            break;
        case 5:
            cout << "May" << '\n';
            break;
        case 6:
            cout << "June" << '\n';
            break;
        case 7:
            cout << "July" << '\n';
            break;
        case 8:
            cout << "August" << '\n';
            break;
        case 9:
            cout << "September" << '\n';
            break;
        case 10:
            cout << "October" << '\n';
            break;
        case 11:
            cout << "November" << '\n';
            break;
        case 12:
            cout << "December" << '\n';
            break;
        default:
            cout << "Not a valid month" << '\n';
            break;
    }



    return 0;
}