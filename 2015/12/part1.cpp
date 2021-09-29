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
    while (!f.eof())
    {
        char line[999999];
        std::string junk;
        f.getline(line, 999999);
        std::strstream s;
        std::string str;
        s << line;
        s >> str;

        std::vector<int> number_vec;
        for (int i = 0; i < str.size();)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                size_t amt = 0;
                int bus = std::stoi(str.substr(i), &amt);
                number_vec.emplace_back(bus);
                i += amt;
                //fmt::print("{}\n", str[i]);
            }
            else if (str[i] == '-')
            {
                size_t amt = 0;
                int bus = std::stoi(str.substr(i + 1), &amt);
                number_vec.emplace_back(bus * -1);
                i += amt + 1;
            }
            else
            {
                i++;
                //fmt::print("{}\n", str[i]);
            }
        }
        int sum = 0;
        for (auto &x : number_vec)
            sum += x;
        fmt::print("{}\n", sum);
        //fmt::print("{}\n", str);

        return 0;
    }
}
