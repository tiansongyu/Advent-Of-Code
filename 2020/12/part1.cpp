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
} pos;

static int current_direction = 1;

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

    for (auto &x : vec)
    {
        switch (*(x.op.c_str()))
        {
        case 'N':
            pos.y += x.number;
            break;
        case 'S':
            pos.y -= x.number;
            break;

        case 'E':
            pos.x += x.number;
            break;

        case 'W':
            pos.x -= x.number;
            break;

        case 'L':
            for (int i = 0; i < x.number / 90; i++)
            {
                if (current_direction == 4)
                    current_direction = 1;
                else
                    current_direction += 1;
            }
            break;

        case 'R':
            for (int i = 0; i < x.number / 90; i++)
            {
                if (current_direction == 1)
                    current_direction = 4;
                else
                {
                    current_direction -= 1;
                }
            }
            break;

        case 'F':
            switch (current_direction)
            {
            case 1:
                pos.x += x.number;
                break;
            case 2:
                pos.y += x.number;
                break;
            case 3:
                pos.x -= x.number;
                break;
            case 4:
                pos.y -= x.number;
                break;
            default:
                break;
            }
            break;
        }
        //fmt::print("{} {}\n", pos.x, pos.y);
    }

    for (auto &x : vec)

    {
        fmt::print("{} {}\n", x.op, x.number);
    }

    fmt::print("{} \n", pos.fin());

    return 0;
}