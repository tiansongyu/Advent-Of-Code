#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

static bool result[26];

int Analysis1(std::vector<std::string> tmp)
{
	for (auto x : tmp)
	{
		for (auto y : x)
		{
			result[y - 'a'] = true;
		}
	}
	int count = 0;
	for (int i = 0; i < 26; i++)
	{
		if (result[i])
			count++;
	}
	return count;
}

int main2()
{

	std::ifstream file("input.txt");
	std::string line;
	std::vector<std::string> tmp_data;
	int count = 0;
	memset(result, false, 26);
	while(std::getline(file, line))
	{
		if(!line.empty())
		{
			tmp_data.push_back(line);
		}
		else
		{
			count +=Analysis1(tmp_data);
			memset(result, false, 26);
			tmp_data.clear();
		}

	}
	std::cout << "result is : " << count << std::endl;
	return 0;
}
