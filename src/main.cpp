#include <array>
#include <iostream>

#include "statistics/statistics.hpp"
#include "statistics/max.hpp"
#include "statistics/mean.hpp"
#include "statistics/min.hpp"
#include "statistics/percentile.hpp"
#include "statistics/standard_deviation.hpp"

int main()
{
	const size_t statistics_count = 6;
	std::array<IStatistics*, statistics_count> statistics 
	{
		new Min{},
        new Max{},
        new Mean{},
        new StandardDeviation{},
        new Percentile(90),
        new Percentile(95),
	};

	double val = 0;
	while (std::cin >> val) {
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->update(val);
		}
	}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;
}