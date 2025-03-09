#include<iostream>

using std::cout;

int main(){

    // std::string cars[3][4]; // 3 rows 4 columns

    // 3 columns unspecified rows amount
    std::string cars[][3] = {
        {
            "mustang", "Escape", "f-150"
        }, 
        {
            "Corvette", "Equinox", "Silverado"
        },
        {
            "Challenger", "Durago", "Ram"
        }
    };

    cout << cars[0][2];

    // 
    cout <<"\n\n\n";
    int rows = sizeof(cars)/sizeof(cars[0]);
    int cols = sizeof(cars[0])/sizeof(cars[0][0]);

    for(int i = 0; i < rows; i++){
        cout << "\n\nAddress of nest array: #" << i << " Adress: " << cars[i]; // will give the memory address for each of the row nest arrays         ex :{"mustang", "Escape", "f-150"        }
        cout << "\ncars in this array: ";
        for(int j = 0; j < rows; j++){
            cout << " " << cars[i][j];
        }

    }



    return 0;
}