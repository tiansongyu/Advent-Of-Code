#include <iostream>
#include <string>
#include <regex>
#include <iterator>
#include <fmt/core.h>
int main()
{
    std::string str = "1321131112";
    std::string new_str;

    for (int index = 0; index < 50;index++)
    {
        int last_number = 0;
        int number ;
        char current_ch;
        for (int i = 0; i < str.size() ; i++)
        {
            if (str[i] != str[i + 1])
            {
                current_ch = str[i];
                number = i + 1 - last_number;
                last_number = i+1;
                new_str += std::to_string(number) + current_ch;
            }
        }
        str = new_str;
        new_str.clear();
    }
    //fmt::print("{} \n", str);
    fmt::print("{} \n", str.size());

    return 0;
}
