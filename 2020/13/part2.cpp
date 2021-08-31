#include <fmt/core.h>
#include <cmath>
#include <set>
#include <fstream>
#include <strstream>
#include <istream>
#include <vector>

struct message
{
    std::string op;
    int number;
};
struct position
{
    int x = 0;
    int y = 0;
    int fin()
    {
        return abs(x) + abs(y);
    }
} ship, guide;
std::vector<message> vec;

int main()
{
    std::ifstream f("./input.txt");
    if (!f.is_open())
        return false;

    while (!f.eof())
    {
        char line[128];
        f.getline(line, 128);
        std::strstream s;
        std::string str;
        message tmp_message;
        s << line;
        s >> str;
        char tmp_op = str[0];
        tmp_message.op = tmp_op;
        str.erase(str.begin());
        tmp_message.number = atoi(str.c_str());

        vec.push_back(tmp_message);
    }
    guide.x = 10;
    guide.y = 1;
    for (auto &x : vec)
    {
        switch (*(x.op.c_str()))
        {
        case 'N':
            guide.y += x.number;
            break;
        case 'S':
            guide.y -= x.number;
            break;

        case 'E':
            guide.x += x.number;
            break;

        case 'W':
            guide.x -= x.number;
            break;

        case 'L':
        {
            for (int i = 0; i < x.number / 90; i++)
            {
                int tmp_x = guide.x;
                int tmp_y = guide.y;

                guide.x = -tmp_y;
                guide.y = tmp_x;
            }
            break;
        }

        case 'R':
        {
            for (int i = 0; i < x.number / 90;i++)
            {
                int tmp_x = guide.x;
                int tmp_y = guide.y;

                guide.x = tmp_y;
                guide.y = -tmp_x;
            }
            break;
        }
        case 'F':
            ship.x += guide.x * x.number;
            ship.y += guide.y * x.number;
            break;
        }
        //fmt::print("op: {} number {} ship: {} {}  guid: {} {} \n", x.op, x.number, ship.x, ship.y, guide.x, guide.y);
    }

    for (auto &x : vec)
    {
        //fmt::print("{} {}\n", x.op, x.number);
    }

    fmt::print("{} \n", ship.fin());

    return 0;
}

/* #include <fmt/core.h>
#include <cmath>
#include <set>
#include <fstream>
#include <strstream>
#include <istream>
#include <vector>

struct message
{
    std::string op;
    int number;
};
struct position
{
    int x = 0;
    int y = 0;
    int fin()
    {
        return abs(x) + abs(y);
    }
} ship, guide;
std::vector<message> vec;

int main()
{
    std::ifstream f("./input.txt");
    if (!f.is_open())
        return false;

    while (!f.eof())
    {
        char line[128];
        f.getline(line, 128);
        std::strstream s;
        std::string str;
        message tmp_message;
        s << line;
        s >> str;
        char tmp_op = str[0];
        tmp_message.op = tmp_op;
        str.erase(str.begin());
        tmp_message.number = atoi(str.c_str());

        vec.push_back(tmp_message);
    }
    guide.x = 10;
    guide.y = 1;
    for (auto &x : vec)
    {
        switch (*(x.op.c_str()))
        {
        case 'N':
            guide.y += x.number;
            break;
        case 'S':
            guide.y -= x.number;
            break;

        case 'E':
            guide.x += x.number;
            break;

        case 'W':
            guide.x -= x.number;
            break;

        case 'L':
        {
            int _x = guide.x;
            int _y = guide.y;
            guide.x = cos(x.number) * _x - sin(x.number) * _y;
            guide.y = sin(x.number) * _x + cos(x.number) * _y;
            break;
        }

        case 'R':
        {
            int _x = guide.x;
            int _y = guide.y;
            guide.x = cos((-x.number)) * _x - sin((float)(-x.number)) * _y;
            guide.y = sin((-x.number)) * _x + cos((float)(-x.number)) * _y;
            break;
        }
        case 'F':
            ship.x += guide.x * x.number;
            ship.y += guide.y * x.number;
            break;
        }
        fmt::print("op: {} number {} ship: {} {}  guid: {} {} \n", x.op, x.number, ship.x, ship.y, guide.x, guide.y);
    }

    for (auto &x : vec)
    {
        //fmt::print("{} {}\n", x.op, x.number);
    }

    fmt::print("{} \n", ship.fin());

    return 0;
} */