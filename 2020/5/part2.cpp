#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

struct Bound
{
	int min;
	int max;
	Bound(int one, int two)
	{
		min = one;
		max = two;
	}
};

int Analysis(std::string line)
{
	Bound fb(0, 127);
	Bound lr(0, 7);
	std::stringstream ss(line);
	char tmp;
	while (ss >> tmp)
	{
		switch (tmp)
		{
		case 'F':
			fb.max = (fb.min + fb.max - 1) / 2;
			break;
		case 'B':
			fb.min = (fb.min + fb.max + 1) / 2;
			break;
		case 'R':
			lr.min = (lr.min + lr.max + 1) / 2;
			break;
		case 'L':
			lr.max = (lr.min + lr.max - 1) / 2;
			break;
		default:
			break;
		}
	}
	return fb.min * 8 + lr.min;
}

int main()
{

	bool seats[1000];
	for (int i = 0; i < 1000; i++)
	{
		seats[i] = false;
	}


	std::ifstream file("input.txt");
	std::string line;
	size_t number = 7;
	std::vector<std::vector<bool>> map;
	size_t count = 0;
	int max = -1;
	while (std::getline(file, line))
	{
		seats[Analysis(line)] = true;
	}
	bool exist = false;

	for (int i = 1; i < 999; i++)
	{
		if (seats[i])
			continue;
		if (seats[i - 1] && seats[i + 1])
		{
			std::cout << "seats is : " << i << std::endl;
		}
	}


	return 0;
}
