#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

static size_t result[26];

int Analysis(std::vector<std::string>& tmp)
{
	for (auto x : tmp)
	{
		for (char y : x)
		{
			result[y - 'a']++;
			std::cout << y << std::endl;
		}
	}
	int count = 0;
	for (int i = 0; i < 26; i++)
	{
		if (i == ('s' - 'a'))
		{
			std::cout << "s di" << std::endl;
			std::cout << result[i] << std::endl;
		}

		if (result[i] == tmp.size())
		{
			std::cout << (char)(i + (int)'a') << std::endl;
			count++;
			std::cout << tmp.size() << std::endl;
		}
	}
	return count;
}

int main()
{

	std::ifstream file("input.txt");
	std::string line;
	std::vector<std::string> tmp_data;
	int count = 0;
	memset(result, 0, 26);
	while (std::getline(file, line))
	{
		if (!line.empty())
		{
			tmp_data.push_back(line);
		}
		else
		{
			count += Analysis(tmp_data);
			memset(result, 0, 26);
			tmp_data.clear();
		}

	}
	std::cout << "result is : " << count << std::endl;
	return 0;
}
