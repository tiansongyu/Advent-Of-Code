#include <fmt/core.h>
#include <cmath>
#include <set>
#include <fstream>
#include <strstream>
#include <istream>

int main()
{
    std::ifstream f("./input.txt");
    if (!f.is_open())
        return false;
    std::set<int> t;
    while (!f.eof())
    {
        char line[128];
        f.getline(line, 128);
        std::strstream s;
        int number;
        s << line;
        s >> number;
        t.insert(number);
    }
    int diff_one = 0;
    int diff_three = 0;
    int last_number = 0;
    for (auto &x : t)
    {
        int diff = x - last_number;
        if (diff == 1)
            diff_one++;
        else if (diff == 3)
        {
            diff_three++;
        }
        last_number = x;
        fmt::print("{}\n", x);
    }
    fmt::print("{} {} \n", diff_one, diff_three);
    /*     static int index = 25;
    bool flag = true;
    while (index < 1000)
    {
        int start = index - 25;
        bool tmp_flag = false;
        for (int i = start; i < index - 1; i++)
        {
            for (int j = start + 1; j < index;j++)
            {
                if(i==j)
                    continue;
                if(t[i]+t[j]==t[index])
                    tmp_flag = true;
            }
        }
        if(!tmp_flag)
            break;
        index++;
    } */
    //fmt::print("{}\n", t[index]);
    return 0;
}