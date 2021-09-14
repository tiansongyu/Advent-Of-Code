#include <fmt/core.h>
#include <cmath>
#include <set>
#include <fstream>
#include <strstream>
#include <istream>
#include <vector>
#include <algorithm>
size_t get_area(int x, int y, int z)
{
    std::vector<int> vec;
    vec.push_back(x);
    vec.push_back(y);
    vec.push_back(z);
    sort(vec.begin(), vec.end());
    return vec[0] * 2 + vec[1] * 2 + x * y * z;
}

int main()
{
    std::ifstream f("./input.txt");
    if (!f.is_open())
        return false;

    int up = 0;
    int down = 0;
    size_t area = 0;
    while (!f.eof())
    {
        char line[128];
        f.getline(line, 128);
        int distance[3];
        std::strstream s;
        std::string str;
        s << line;
        s >> str;
        size_t pos1, pos2;
        distance[0] = std::stoi(str.substr(0), &pos1);
        distance[1] = std::stoi(str.substr(pos1 + 1), &pos2);
        distance[2] = std::stoi(str.substr(pos1 + pos2 + 1 + 1));

        area += get_area(distance[0], distance[1], distance[2]);
    }
    fmt::print("{}\n", area);

    return 0;
}