#include <fmt/core.h>
#include <cmath>
#include <set>
#include <fstream>
#include <strstream>
#include <istream>
#include <vector>

int main()
{
    std::ifstream f("./input.txt");
    if (!f.is_open())
        return false;

    std::vector<int> vec;

    std::string mask;

    char line[128];
    std::string junk;
    f.getline(line, 128);
    std::strstream s;
    std::string str_line;
    s << line;
    s >> str_line;

    size_t i = 0;

    while (i < str_line.length())
    {
        if (line[i] == ',')
        {
            i += 1;
            continue;
        }
        size_t amt = 0;
        int bus = std::stoi(str_line.substr(i), &amt);
        vec.push_back(bus);
        i += amt + 1;
    }
    int first_size = vec.size();
    int index = vec.size();
    fmt::print("size: {}\n", index);
    while (index < 2020)
    {
        int target = vec[index - 1];

        bool find_flag = false;
        int first_flag = 0;
        int sencond_flag = 0;
        for (int i = vec.size() - 2; i >= 0; i--)
        {
            if(vec[i] == target)
            {
                sencond_flag = vec.size() - 1;
                first_flag = i;
                find_flag = true;
                break;
            }
        }
        if (!find_flag)
        {
            vec.push_back(0);
            fmt::print("0 target: {}  {} {}  {} \n", target, sencond_flag, first_flag, index);
        }
        else 
        {
            vec.push_back(sencond_flag - first_flag);
            fmt::print("2 target: {}  {} {}  {} \n", target, sencond_flag, first_flag, index);
        }
        index++;
    }

    for (const auto &x : vec)
    {
        fmt::print("{},", x);
    }
    return 0;
}