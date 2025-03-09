#include <iostream>
#include <cmath>


int main(){
    using std::cout;

    double a, b, c;

    cout << "Enter side a: ";
    std::cin >> a;
    cout << "Enter side b: ";
    std::cin >> b;
    cout << "Enter side c: ";
    std::cin >> c;

    // a = pow(a, 2);
    // b = pow(b, 2);
    // c = sqrt(a + b);
    c = sqrt(pow(a, 2) + pow(b, 2)); // this is the same as the above 3 lines

    cout << "The hypotenuse is: " << c << '\n';

    return 0;
}