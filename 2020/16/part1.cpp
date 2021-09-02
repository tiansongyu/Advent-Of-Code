#include <fmt/core.h>
#include <cmath>
#include <set>
#include <fstream>
#include <strstream>
#include <istream>
#include <vector>
#include <unordered_map>

std::unordered_map<int, int> map;
std::vector<int> vec;
int state = 1;

int main()
{
    std::ifstream f("./input.txt");
    while (!f.eof())
    {
        char line[128];
        std::string junk;
        f.getline(line, 128);
        std::strstream s;
        std::string str;
        s << line;
        switch (state)
        {
        case 1:
            while (true)
            {
                s >> str;
                if (str.empty())
                {
                    state = 2;
                    break;
                }
                int index = 0;
                int last_start = 0;
                while (true)
                {
                    s >> str;
                    size_t amt_frist = 0, amt_second = 0;
                    if (str[0] >= '0' && str[0] <= '9')
                    {

                        int start_number = 0;
                        int end_number = 0;
                        start_number = std::stoi(str.substr(0), &amt_frist);
                        if (last_start == start_number)
                            break;
                            last_start = start_number;
                        end_number = std::stoi(str.substr(0 + amt_frist + 1), &amt_second);
                        for (int i = start_number; i <= end_number; i++)
                        {
                            map.insert_or_assign(i, 1);
                            fmt::print("i : {}\n", i);
                        }

                        index += (amt_frist+amt_second+1);
                        continue;
                    }
                    index++;
                }
                if (s.eof())
                    break;
            }
            break;
        case 2:
            f.getline(line, 128);
            f.getline(line, 128);
            f.getline(line, 128);

            state = 3;
            break;
        case 3:
            s >> str;
            int i = 0;

            while (true)
            {
                size_t amt = 0;
                int bus = std::stoi(str.substr(i), &amt);
                vec.push_back(bus);
                i += amt + 1;
                if (i >= str.size() - 1)
                    break;
            }
            break;
        }
    }
    int sum = 0;
    for (const auto &x : vec)
    {
        if (map.count(x) == 0)
        {
            sum += x;
            //fmt::print("{}\n", x);
        }
    }
    fmt::print("{}\n", sum);

    return 0;
}