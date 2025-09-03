#include <iostream>

using std::cout;
int main(){
    std::string questions[] = { 
        "1. What year was C++ created?: ",
        "2. Who invented C++?: ",
        "3. What is the predecessor of C++?: ",        
        "4. Is the earth flat?: "
    };


    std::string options[][4]={
        {"A. 1969", "B. 1975", "C. 1985", "D. 1989"},
        {"A. Guido van Rossum", "B. Bjarne Stroustrup", "C. John Carmack", "D. Mark Zuckerber"},
        {"A. C", "B. C+", "C. C--", "D. B++"},
        {"A. Yes", "B. No", "C. Sometimes", "D. Whats earth?"},
    };

    char answerKey[] = {'C', 'B', 'A', 'B'};
    
    int size = sizeof(questions)/ sizeof(questions[0]);

    char guess;

    int score;


    for(int i = 0; i < size; i++){
        cout << "****************************************\n";
        cout << questions[i] << "\n";
        cout << "****************************************\n";

        for (int j = 0; j < sizeof(options[i])/ sizeof(options[i][0]); j++)
        {   
            cout << options[i][j] << "\n";
        }


        std::cin >> guess;
        guess = toupper(guess);
        if(guess == answerKey[i]){
            cout << "CORRECT\n";
            score++;
        }else{
            cout << "WRONG\n";
            cout << "Answer is " << answerKey[i] << "\n ";
        }
        
    }
    cout << "****************************************\n";
    cout << "\n\n                          Results:                         \n";
    cout << "Correct Guess: " << (score/(double)size) *100<<"%";
    cout << "\n****************************************\n";

    return 0;
}