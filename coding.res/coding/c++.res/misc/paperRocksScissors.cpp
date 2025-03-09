#include <iostream>
#include <ctime>


char getUserChoice();
char getComputerChoice();
void showChoices(char choice);
void chooseWinner(char player, char computer);


using std::cout;

int main(){

    char player;
    char computer;

    player = getUserChoice();

    cout << "\nYou chose: ";
    showChoices(player);

    computer = getComputerChoice();
    cout << "Computer chose: ";
    showChoices(computer);

    chooseWinner(player, computer);


    return 0;
}



char getUserChoice(){
    char player;
    cout << " Rock Paper Scissors Game!\n";
    do{
        cout << "\nchoose one of the following\n";
        cout << " *************************************************\n\n\n";
        cout << "'r' for rock\n\n";
        cout << "'p' for paper\n\n";
        cout << "'s' for scissors\n\n";
        std::cin >> player;

        cout << '\n' << player;
    }while(player != 'r' && player != 'p' && player != 's');
    return player;
}

char getComputerChoice(){

    srand(time(0));
    int num = rand() % 3 + 1; // number between 1 and 3

    switch (num)
    {
        case 1: return 'r';
        case 2: return 'p';
        case 3: return 's';
    }
    return 0;
}
void showChoices(char choice){

    switch (choice)
    {
        case 'r':
            cout << "\nRock\n";
            break;
        case 'p':
            cout << "\nPaper\n";
            break;
        case 's':
            cout << "\nScissors\n";
            break;
    }
}
void chooseWinner(char player, char computer){

    switch (player)
    {
        case 'r':
            if(computer == 'r'){
                cout << "It's a tie!\n";
            }else if(computer == 'p'){
                cout << "Computer wins!\n";
            }else{
                cout << "You win!\n";
            }
            break;
        case 'p':
            if(computer == 'r'){
                cout << "You win!\n";
            }else if(computer == 'p'){
                cout << "It's a tie!\n";
            }else{
                cout << "Computer wins!\n";
            }
            break;
        case 's':
            if(computer == 'r'){
                cout << "Computer wins!\n";
            }else if(computer == 'p'){
                cout << "You win!\n";
            }else{
                cout << "It's a tie!\n";
            }
            break;
    }

}