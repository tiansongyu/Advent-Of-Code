#include <fstream>
#include <iostream>
#include <limits>
#include <vector>
#include <fmt/core.h>
struct data
{
    long long number;
    int index;
};
int main(void)
{
    std::vector<data> buses;
    int timestamp;

    std::ifstream file("input.txt");
    file >> timestamp;

    std::string line;
    file >> line;
    size_t i = 0;
    int tmp_number_index = 0;
    while (i < line.length())
    {
        data tmp_data;
        if (line[i] == 'x')
        {
            i += 2;
            tmp_number_index++;

            continue;
        }
        size_t amt = 0;
        int  bus = std::stoi(line.substr(i), &amt);
        tmp_data.number = bus;
        tmp_data.index = tmp_number_index;
        buses.push_back(tmp_data);

        i += amt + 1;

        tmp_number_index++;
    }

    long long current_chect;
    int find_index;

    long long step = buses[0].number;
    size_t stamp = 0;
    for (int i = 1; i < buses.size(); i++)
    {
        bool departs = false;
        // 找到前两辆车的最小公倍数
        while(!departs)
        {
            stamp  += step;
            departs = ((stamp + buses[i].index) % buses[i].number) == 0;
        }

        step *= buses[i].number;
    }

    fmt::print("{}\n", stamp);
    return 0;
}