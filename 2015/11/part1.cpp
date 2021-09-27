#include <iostream>
#include <string>
#include <regex>
#include <iterator>
#include <fmt/core.h>

std::string str = "hepxcrrq";

void tranlate(int number)
{

    if (number < 0)
        return;
    if (str[number] == 'z')
    {
        tranlate(number - 1);
        str[number] = 'a';
        return;
    }
    str[number] = str[number] + 1;
}

int main()
{
    bool find_flag = false;
    while (!find_flag)
    {
        tranlate(str.size() - 1);

        bool one = false, two = true, three = false;
        int number = 0;
        std::vector<char> save;
        for (int index = 0; index < str.size(); index++)
        {
            if (str[index] == 'i' || str[index] == 'o' || str[index] == 'l')
            {
                two = false;
                break;
            }
            if (str[index] == (str[index + 1] - 1) && str[index + 1] == (str[index + 2] - 1))
                one = true;
            if (str[index] == str[index + 1])
            {
                number++;
                index++;
                save.push_back(str[index]);
            }
        }
        for (int i = 1; i < save.size(); i++)
        {
            if(save[0]!=save[i])
                three = true;
        }
        if (number >= 2 && one && two && three)
        {
            fmt::print("{}\n", str);
            find_flag = true;
        }
    }
    return 0;
}
