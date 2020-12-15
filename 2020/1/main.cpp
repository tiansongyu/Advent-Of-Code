#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	std::ifstream file("input.txt");
	std::vector<int> lines;
	int tmp;
	while (file >> tmp)
	{
		lines.push_back(tmp);
	}
	for (int i = 0; i < lines.size(); i++)
	{
		for (int j = 1; j < lines.size(); j++)
		{

			if (lines[i] + lines[j] == 2020)
			{
				std::cout << "success find! " << lines[i]<<"  "<<lines[j] << std::endl;
				std::cout << "and the result is " << lines[i] * lines[j] << std::endl;
			}
		}
	}

	for (int i = 0; i < lines.size(); i++)
	{
		for (int j = 1; j < lines.size(); j++)
		{
			for (int z = 2; z < lines.size(); z++)

				if (lines[i] + lines[j] + lines[z] == 2020)
				{
					std::cout << "success find! " << lines[i] << "  " << lines[j] << " " << lines[z] << std::endl;
					std::cout << "and the result is " << lines[i] * lines[j] * lines[z] << std::endl;
				}
		}

	}


	return 0;
}