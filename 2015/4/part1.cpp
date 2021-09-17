#include<iostream>
#include "md5.h"
#include <string>
int main()
{
	int i = 0;
	while (true)
	{
		std::string str = "yzbqklnj";
		str = str + std::to_string(i);
		str = md5::md5_hash_hex(str);
		bool flag = true;
		for (int j = 0; j < 5; j++)
		{
			if (str[j] != '0')
				flag = false;
		}
		if (flag)
		{
			std::cout << str << std::endl;
			std::cout << i << std::endl;
			break;
		}
		i++;
	}
	return 0;
}