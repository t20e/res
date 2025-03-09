#include <iostream>

int main(){
    using std::cout;

    // for(int i = 1; i <=3; i++){ // i+2 is the incrementer i-=2 is the decrementer
    //     cout << "I:" << i << '\n';
    //     // break; // will break out of the loop
    //     // continue; // will skip the rest of the code in the loop and go to the next iteration
    //     // cout << "this will not print" << '\n';


    //     for(int j = 1; j <= 5; j++){
    //         cout << j << '\n';
    //     }
    // }

    int rows;
    int columns;
    char symbol;
    
    cout << "Enter the number of rows: ";
    std::cin >> rows;
    cout << "Enter the number of columns: ";
    std::cin >> columns;
    cout << "Enter a symbol: ";
    std::cin >> symbol;

    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            cout << symbol;
        }
        cout << '\n';
    }



    return 0;
}