#include <fstream>
#include <iostream>
#include <limits>
#include <vector>
#include <fmt/core.h>
int main(void)
{
    std::vector<int> buses;
    int timestamp;

    std::ifstream file("input.txt");
    file >> timestamp;

    std::string line;
    file >> line;
    size_t i = 0;
    while (i < line.length())
    {
        if (line[i] == 'x')
        {
            i += 2;
            continue;
        }
        size_t amt = 0;
        int bus = std::stoi(line.substr(i), &amt);
        buses.push_back(bus);
        i += amt + 1;
    }
    bool find = false;
    int step = 0;
    int number_bus = 0;
    while (true)
    {
        for (int i = 0; i < buses.size();i++)
        {
            if((timestamp + step)% buses[i] ==0)
            {
                find = true;
                number_bus = buses[i];
                break;
            }
        }
        if(find)
            break;
        step++;
    }

    for(const auto &x:buses)
    {
        fmt::print("{}\n", x);
    }
    fmt::print("{} {} {} \n", number_bus, step, number_bus * step);
    return 0;
}