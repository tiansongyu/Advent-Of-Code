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
size_t slope(std::vector<std::vector<bool>>& map, size_t xslope, size_t yslope)
{
	size_t count = 0;
	size_t x = 0;
	for (size_t y = 0; y < map.size(); y+= yslope)
	{
		if (test_tree(map, x, y))
		{
			count++;
		}
		x += xslope;
	}
	return count;
}
int main()
{
	std::ifstream file("input.txt");
	std::string line;
	size_t number = 0;
	std::vector<std::vector<bool>> map;
	size_t result = 1;
	while (std::getline(file, line))
	{
		std::vector<bool> tmp;
		for (char& x : line)
		{
			tmp.push_back(x == '#');
		}
		map.push_back(tmp);
	}
	result *= slope(map, 1, 1);
	result *= slope(map, 3, 1);
	result *= slope(map, 5, 1);
	result *= slope(map, 7, 1);
	result *= slope(map, 1, 2);
	std::cout << result << std::endl;
	return 0;
}