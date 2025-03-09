#include <iostream>

using std::cout;

int getDigit(const int number);
int sumOddDigits(const std::string cardNumber);
int sumEvenDigits(const std::string cardnumber);




int main(){
 
    std::string cardNumber;

    int result= 0;
    cout << "Enter a credit card number";

    std::cin >> cardNumber;
    result = sumEvenDigits(cardNumber) + sumOddDigits(cardNumber);

    if(result % 10 == 0){
        cout << "Valid card number";
    }else{
        cout << "In-Valid card number";

    }

    return 0;
}


int getDigit(const int number){
    // 18
    // 9 * 2
    // 18/10 = 1 % 10 = 1
    // 8 + 1 = 9 return 9

    return number % 10 + (number / 10 % 10);

}

int sumOddDigits(const std::string cardNumber){

    int sum = 0 ;

    for(int i = cardNumber.size() - 1; i >=0; i-=2){
        sum += (cardNumber[i] - '0');
    }
    return sum;
}

int sumEvenDigits(const std::string cardNumber){

    int sum = 0 ;

    for(int i = cardNumber.size() - 2; i >=0; i-=2){
        sum += getDigit((cardNumber[i] - '0') * 2);
    }
    return sum;
}

