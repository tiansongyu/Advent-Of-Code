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
    int all_sum = 0;
    while (!f.eof())
    {
        char line[128];
        f.getline(line, 128);
        std::strstream s;
        std::string str;
        s << line;
        s >> str;
        bool find_flag = false;
        bool same_flag = false;
        for (int i = 0; i < str.size() - 3; i++)
        {
            for (int j = i + 2; j < str.size();j++)
            {
                if(str[i]==str[j]&&str[i+1]==str[j+1])
                    find_flag = true;
            }
        }
        for (int i = 0; i < str.size()-2;i++)
        {
            if(str[i]==str[i+2])
                same_flag = true;
        }
        if(same_flag && find_flag )
        {
            all_sum++;
            fmt::print("{}\n", str);
        }
    }
    fmt::print("{}\n", all_sum);
    return 0;
}