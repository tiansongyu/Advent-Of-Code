#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

inline void test(std::string& tmp,size_t & count)
{
	if (tmp.find("byr") != tmp.npos)
		count--;
	if (tmp.find("iyr") != tmp.npos)
		count--;
	if (tmp.find("eyr") != tmp.npos)
		count--;
	if (tmp.find("hgt") != tmp.npos)
		count--;
	if (tmp.find("hcl") != tmp.npos)
		count--;
	if (tmp.find("ecl") != tmp.npos)
		count--;
	if (tmp.find("pid") != tmp.npos)
		count--;
}

int main()
{
	std::ifstream file("input.txt");
	std::string line;
	size_t number = 7;
	std::vector<std::vector<bool>> map;
	size_t count = 0;
	
	while (std::getline(file, line))
	{
		if (line.empty())
		{
			if (number == 0)
				count++;
			number = 7;
		}
		else
		{
			test(line, number);
		}

	}
	std::cout << count << std::endl;

	return 0;
}