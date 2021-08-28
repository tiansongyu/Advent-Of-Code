#include <fmt/core.h>
#include <cmath>
#include <vector>
#include <fstream>
#include <strstream>
#include <istream>

int main()
{
    std::ifstream f("./input.txt");
    if (!f.is_open())
        return false;
    std::vector<long long> t;
    while (!f.eof())
    {
        char line[128];
        f.getline(line, 128);
        std::strstream s;
        long long number ;
        s << line;
        s >> number;
        t.push_back(number);
    }
    static int index = 25;
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
    }
    fmt::print("{}\n", t[index]);
    return 0;
}