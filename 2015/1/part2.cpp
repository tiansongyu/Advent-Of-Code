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

    int up = 0;
    int down = 0;
    int pos = 0;
    char line[12800];
    f.getline(line, 12800);
    std::strstream s;
    std::string str;
    s << line;
    s >> str;
    for (auto &x : str)
    {
        pos++;
        if (x == '(')
            up++;
        else if (x == ')')
            down++;
        if (up - down == -1)
        {
            fmt::print("{}\n", pos);
            break;
        }
    }

    return 0;
}