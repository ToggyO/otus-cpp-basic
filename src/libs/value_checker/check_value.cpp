#include <iostream>

int checkValue(int target_value)
{
	int current_value = 0;
	int attempts_count = 0;
	bool not_win = true;

	std::cout << "Enter your guess:" << std::endl;

	do {
		attempts_count++;
		std::cin >> current_value;

		if (current_value < target_value) {
			std::cout << "less than " << current_value << std::endl;
		}
		else if (current_value > target_value) {
			std::cout << "greater than " << current_value << std::endl;
		}
		else {
			std::cout << "you win! " << "attempts = " << attempts_count << std::endl;
			not_win = false;
		}

	} while(not_win);

	return attempts_count;
}