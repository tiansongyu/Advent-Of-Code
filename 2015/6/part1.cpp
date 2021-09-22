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

std::vector<int> translation(std::string str, int number)
{
    std::vector<int> pos;

    size_t amt = 0, two = 0, three = 0, four = 0;

    pos.emplace_back(std::stoi(str.substr(number), &amt));
    pos.emplace_back(std::stoi(str.substr(number + 1 + amt), &two));
    pos.emplace_back(std::stoi(str.substr(number + 1 + amt + 9 + two), &three));
    pos.emplace_back(std::stoi(str.substr(number + 1 + amt + 9 + two + 1 + three), &four));
    fmt::print("{} {} {} {} {} \n", pos[0], pos[1], pos[2], pos[3],str);
    return pos;
}
int main()
{
    std::ifstream f("./input.txt");
    if (!f.is_open())
        return false;
    int all_sum = 0;
    bool light[1000][1000] = {false};
    while (!f.eof())
    {
        char line[128];
        f.getline(line, 128);
        std::strstream s;
        std::string str;
        s << line;
        str = line;
        char flag;
        std::vector<int> pos;
        if (str[5] == 'e')
        {
            flag = 'e';
            pos = translation(str, 7);
        }
        if (str[6] == 'f')
        {
            flag = 'f';
            pos = translation(str, 9);
        }
        if (str[6] == 'n')
        {
            flag = 'n';
            pos = translation(str, 8);
        }

        for (int j = pos[1]; j < pos[3]+1; j++)
            for (int i = pos[0]; i < pos[2]+1; i++)
            {
                if (flag == 'e')
                    light[i][j] = !light[i][j];
                 if (flag == 'f')
                    light[i][j] = false;
                 if (flag == 'n')
                    light[i][j] = true;
            }
    }
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            if (light[i][j])
                all_sum++;
    fmt::print("{}\n", all_sum);
    return 0;
}