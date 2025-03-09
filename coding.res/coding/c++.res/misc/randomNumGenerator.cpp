#include <iostream>
#include <ctime>

int main(){
    using std::cout;

    // pseudo random number generator, NOT TRUELY RANDOM NUMBER

    srand(time(NULL)); // initialize the random num generator, this is using the calender for randomization seed

    int num = (rand() % 6) + 1; // modules (%) gives the remainder of any division, the + 1 is to make the number between 1 and 6 and not 0 to 5
    cout << num << '\n';

    return 0;
}