#include <iostream>
#include <ctime>

int main(){
    using std::cout;


    srand(time(0)); // this will use the current time to generate random number

    int randNum = rand() % 5 + 1; // this will generate a random number between 1 and 5

    switch (randNum)
    {
    case 1:
        cout << "You found a potion!\n";
        break;
    case 2:
        cout << "You found a sword!\n";
        break;
    case 3:
        cout << "You found a shield!\n";
        break;    
    default:
        break;
    }

    return 0;
}