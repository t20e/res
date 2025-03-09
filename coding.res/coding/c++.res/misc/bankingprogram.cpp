#include <iostream>
#include <iomanip>


using std::cout;

void showBalance(double balance);
double deposit();
double withdraw(double balance);


int main(){
    double balance = 120;
    int choice = 0;

  do{
        cout << "\n\n\n*******************************************************\n";
        cout << "Welcome to the banking program\n";
        cout << "*******************************************************\n\n\n";
        cout << "Enter your choice: \n\n";
        cout << "***********************\n\n\n";
        cout << "1 Show Balance\n";
        cout << "2 Deposit Money \n";
        cout << "3 Withdraw Money \n";
        cout << "4 Exit \n";

        std::cin >> choice;

        std::cin.clear(); // will reset any error flags when std fails to interpet the input
        fflush(stdin); // clear the input buffer, it stops infinite loopste

        switch (choice)
        {
        case 1:
            showBalance(balance);
            break;
        case 2:
            balance += deposit();
            showBalance(balance);
            break;
        case 3:
            balance -= withdraw(balance);
            showBalance(balance);
            break;
        case 4:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }
    }while (choice != 4);
    {
        /* code */
    }
    


    return 0;
}





void showBalance(double balance){
    cout << "----- Your balance is: $" << std::setprecision(2) << std::fixed << balance << '\n';
}

double deposit(){
    double amount = 0;
    cout << "Enter the amount you want to deposit: ";
    std::cin >> amount;
    if(amount > 0){
        return amount;
    }
    cout << "\n\nInvalid Deposit amount\n";
    return 0;
}


double withdraw(double balance){
    double amount = 0;
    cout << "Enter the amount you want to withdraw: ";
    std::cin >> amount;
    if(amount < 0)
    {
        cout << "\n\nInvalid withdraw amount\n";
        return 0;    
    }else if ( amount > balance)
    {
        cout << "\n\n\n InSuffiCient Funds\n";
        return 0;
    }
    return amount;
}

