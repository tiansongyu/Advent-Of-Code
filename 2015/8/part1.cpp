#include <fmt/core.h>
#include <cmath>
#include <set>
#include <fstream>
#include <strstream>
#include <istream>
#include <vector>
#include <fstream>
#include <iostream>
#include <limits>
#include <vector>
#include <fmt/core.h>

int calnumber(std::string str, std::string search)
{
    int index = 0;
    int number = 0;
    while (index < str.size())
    {
        index = str.find(search, index);
        if (index == std::string::npos)
        {
            break;
        }
        else
        {
            number++;
            index++;
        }
    }
    // fmt::print("{} {} {} \n", str, search, number);
    return number;
}

int main()
{
    std::ifstream f("./input.txt");
    if (!f.is_open())
        return false;
    int all_sum = 0;
    int finl_all_sum = 0;
    int true_sum = 0;
    bool light[1000][1000] = {false};
    std::string tmp_one = "\\\"";
    std::string tmp_two = "\\x";
    std::string tmp_three = "\\\\";

    while (!f.eof())
    {
        char line[128];
        f.getline(line, 128);
        std::strstream s;
        std::string str;
        s << line;
        s >> str;
        
        int strnumberbad = str.size();
        finl_all_sum = str.size();
        int tmp_one_number = 0, tmp_two_number = 0, tmp_three_number = 0;
        tmp_one_number = calnumber(str, tmp_one);
        tmp_two_number = calnumber(str, tmp_two);
        tmp_three_number = calnumber(str, tmp_three);
        fmt::print("{} {} {} {}\n", str, tmp_one_number, tmp_two_number, tmp_three_number);

        all_sum += (tmp_two_number * 3 + tmp_one_number + tmp_three_number + 2);
        fmt::print("all_sum: {} \n", (tmp_two_number * 3 + tmp_one_number + tmp_three_number + 2));
    }
    fmt::print("{} \n", all_sum);
    return 0;
}