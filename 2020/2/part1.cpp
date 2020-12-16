#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
struct Line
{
	size_t min;
	size_t max;
	char code;
	std::string password;
};

int main2()
{
	std::ifstream file("input.txt");
	std::string line;
	size_t number = 0;
	char tmp;
	while (std::getline(file, line))
	{
		Line entry;
		std::stringstream ss(line);
		ss >> entry.min >> tmp >> entry.max;
		ss >> entry.code >> tmp;
		ss >> entry.password;
		size_t tmp_number = 0;
		for (auto x : entry.password)
		{
			if (x == entry.code)
			{
				tmp_number++;
			}
		}
		if (tmp_number >= entry.min && tmp_number <= entry.max)
		{
			number++;
		}

	}
	std::cout << number;
	return 0;
}