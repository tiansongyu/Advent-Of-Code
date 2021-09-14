#include <fmt/core.h>
#include <cmath>
#include <set>
#include <fstream>
#include <strstream>
#include <istream>
#include <vector>

size_t get_area(int x,int y,int z)
{
    int l, w, h;
    l = x * y;
    w = x * z;
    h = z * y;
    int min = 0;
    min = l < w ? l : w;
    min = min < h ? min : h;
    return 2 * x * y + 2 * x * z + 2 * y * z + min;
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
        size_t pos1,pos2;
        distance[0] = std::stoi(str.substr(0), &pos1);
        distance[1] = std::stoi(str.substr(pos1 + 1), &pos2);
        distance[2] = std::stoi(str.substr(pos1+pos2 +1 +1));

        area += get_area(distance[0], distance[1], distance[2]);
    }
    fmt::print("{}\n", area );

    return 0;
}