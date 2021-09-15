#include <fmt/core.h>
#include <cmath>
#include <set>
#include <fstream>
#include <strstream>
#include <istream>
#include <vector>

struct map
{
    int x = 0;
    int y = 0;
};

int main()
{
    std::ifstream f("./input.txt");
    if (!f.is_open())
        return false;
    std::vector<map> pos;
    int up = 0;
    int down = 0;
    map current;
    size_t area = 0;

    char line[12800];
    f.getline(line, 12800);
    std::strstream s;
    std::string str;
    s << line;
    s >> str;
    pos.emplace_back(current);
    for (auto &x : str)
    {
        switch (x)
        {
        case '^':
            current.y--;
            break;
        case 'v':
            current.y++;
            break;
        case '<':
            current.x--;
            break;
        case '>':
            current.x++;
            break;
        }
        bool flag = false;
        for (auto &y : pos)
        {
            if(y.x==current.x&&y.y==current.y)
            {
                flag = true;
                break;
            }
        }
        if(!flag)
            pos.emplace_back(current);
    }
    fmt::print("{}\n", pos.size());

    return 0;
}