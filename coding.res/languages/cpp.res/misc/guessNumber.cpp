#include <iostream>
#include <ctime>

int main()
{
	using std::cout;

	int num;
	int guess;
	int tries = 0;

	srand(time(NULL));
	num = (rand() % 100) + 1;

	cout << "Guess My Number Game\n\n";
	do
	{
		cout << "Enter a guess between 1 and 100: ";
		std::cin >> guess;
		tries++;

		if (guess > num)
		{
			cout << "Too high!\n\n";
		}
		else if (guess < num)
		{
			cout << "Too low!\n\n";
		}
		else
		{
			cout << "\nCorrect! You got it in " << tries << " guesses!\n";
		}

	} while (guess != num);

	return 0;
}