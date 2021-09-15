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
    map current_old;
    map current;

    size_t area = 0;

    char line[12800];
    f.getline(line, 12800);
    std::strstream s;
    std::string str;
    s << line;
    s >> str;
    pos.emplace_back(current);
    for (int x = 0; x < str.size(); x++)
    {
        bool old = (x % 2) == 0;
        switch (str[x])
        {
        case '^':
            old ? current_old.y-- : current.y--;
            break;
        case 'v':
            old ? current_old.y++ : current.y++;
            break;
        case '<':
            old ? current_old.x-- : current.x--;
            break;
        case '>':
            old ? current_old.x++ : current.x++;
            break;
        }
        bool flag_old = false;
        bool flag = false;

        for (auto &y : pos)
        {
            if (y.x == current_old.x && y.y == current_old.y)
            {
                flag_old = true;
            }
            if (y.x == current.x && y.y == current.y)
            {
                flag = true;
            }
        }
        if (!flag_old)
            pos.emplace_back(current_old);
        if (!flag)
            pos.emplace_back(current);
    }
    fmt::print("{}\n", pos.size());

    return 0;
}