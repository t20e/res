#include <iostream>
#include <ctime>


void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);



using std::cout;



int main(){

    char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player = 'X';
    char computer = 'O';


    bool running = true;
    drawBoard(spaces);// when we pass an array into a function it decays into a pointer so we dont have to create a pointer for this array


    while(running){
        playerMove(spaces, player);
        drawBoard(spaces);

        if(checkWinner(spaces, player, computer)){
                running = false;
                break;
        }else if(checkTie(spaces)){
            running= false;
            break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);


        if(checkWinner(spaces, player, computer)){
            running = false;
            break;
        }else if(checkTie(spaces)){
            running= false;
            break;
        }

    }


    return 0;
}




void drawBoard(char *spaces){

    cout << "\n\n";

    cout << "      |      |      \n";
    cout << "  "<< spaces[0] << "   |  "<< spaces[1] << "   |  "<< spaces[2] << "   \n";
    
    cout << "______|______|______\n";
    cout << "      |      |      \n";
    cout << "  "<< spaces[3] << "   |  "<< spaces[4] << "   |  "<< spaces[5] << "   \n";
    cout << "______|______|______\n";
    cout << "      |      |      \n";
    cout << "  "<< spaces[6] << "   |  "<< spaces[7] << "   |  "<< spaces[8] << "   \n";
    cout << "      |      |      \n";
    cout << "\n\n";



}

void playerMove(char *spaces, char player){
    int number; // nums between 1 and 9;

    do{
        cout << "Enter a spot to place a marker (1-9)";
        std::cin >> number;
        number--;

        if (spaces[number] == ' '){
            spaces[number] = player;
            break;
        }

    }while(!number > 0 || !number < 8);


}
void computerMove(char *spaces, char computer){

    int number;
    srand(time(0));

    while(true){
        number= rand() % 9;
        if(spaces[number] == ' '){
            spaces[number] = computer;
            break;
        }
    }

}
bool checkWinner(char *spaces, char player, char computer){
    // --- horizontal check
    if(spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]){
        spaces[0] == player ? cout << "You win\n" : cout << "You Lost!\n";
    }
    else if(spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]){
        spaces[3] == player ? cout << "You win\n" : cout << "You Lost!\n";
    }
    else if(spaces[6] != ' ' && spaces[6] == spaces[7] &&  spaces[7] == spaces[8]){
        spaces[6] == player ? cout << "You win\n" : cout << "You Lost!\n";
    }

    // ---- columns check
    if(spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]){
        spaces[0] == player ? cout << "You win\n" : cout << "You Lost!\n";
    }
    if(spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]){
        spaces[1] == player ? cout << "You win\n" : cout << "You Lost!\n";
    }
    if(spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]){
        spaces[2] == player ? cout << "You win\n" : cout << "You Lost!\n";
    }


    // ---- diagonal check

    if(spaces[0] != ' ' && spaces[0] == spaces[4]&& spaces[4] == spaces[8]){
        spaces[0] == player ? cout << "You win\n" : cout << "You Lost!\n";
    }
    if(spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]){
        spaces[2] == player ? cout << "You win\n" : cout << "You Lost!\n";
    }


    // if no win conditions
    else{
        return false;
    }


    return true;
}
bool checkTie(char *spaces){

    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;// not a tie
        }
    }
    cout << "Its a tie\n";
    return true; // game is a tie
}

