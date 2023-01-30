#include <iostream>

#include <cstdlib>
#include <ctime>

#include "randomizer.h"

int Randomizer::getRandomUnsignedInt(const unsigned int max_value)
{
	std::srand(std::time(nullptr)); // use current time as seed for random generator

	const int rand = std::rand();
	const int random_value = rand % max_value;

	return random_value;
}