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

int main()
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
		if (entry.password[entry.min - 1] == entry.code )
		{
			tmp_number++;
		}
		if (entry.password[entry.max - 1] == entry.code)
		{
			tmp_number++;
		}
		if (tmp_number == 1)
		{
			number++;
		}

	}
	std::cout << number;
	return 0;
}