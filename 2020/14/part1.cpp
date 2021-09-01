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

    std::vector<long long> vec(99999,0);

    std::string mask;
    long long index;
    long long value;
    while (!f.eof())
    {
        char line[128];
        std::string junk;
        f.getline(line, 128);
        std::strstream s;
        std::string str;
        s << line;
        s >> str;
        long long first_mask;
        long long second_mask;
        if (str[1] == 'a')
        {
            s >> junk;
            s >> mask;
        }
        else if (str[1] == 'e')
        {
            fmt::print("{}\n", str);
            index = std::stoi(str.substr(4));
            s >> junk;
            s >> value;

            for (int i = 0; i < 36; i++)
            {
                long long tmp_number = 1;
                if (mask[i] == 'X')
                    continue;
                for (int j = 0; j < (35 - i); j++)
                {
                    tmp_number <<= 1;
                }
                if (mask[i] == '1')
                {

                    value |= tmp_number;
                }
                else if(mask[i]=='0')
                {
                    value &= ~tmp_number;
                }
            }
            vec[index] = value;
        }
    }

    long long sum = 0;
    for(const auto&x:vec)
    {
        sum += x;
    }
    fmt::print("{} \n", sum);
    return 0;
}