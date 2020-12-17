#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>



static inline bool test_tree(std::vector<std::vector<bool>>& map, size_t x, size_t y)
{
	x = x % map[0].size();
	return map[y][x];
}

int main2()
{
	std::ifstream file("input.txt");
	std::string line;
	size_t number = 0;
	std::vector<std::vector<bool>> map;

	while (std::getline(file, line))
	{
		std::vector<bool> tmp;
		for (char& x : line)
		{
			tmp.push_back(x == '#');
		}
		map.push_back(tmp);
	}

	size_t count = 0;
	size_t x = 0;

	for (size_t y = 0; y < map.size(); y++)
	{
		if (test_tree(map, x, y))
		{
			count++;
		}
		x += 3;
	}
	std::cout << count << std::endl;
	return 0;
}