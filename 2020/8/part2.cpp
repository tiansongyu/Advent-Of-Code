#include <fmt/core.h>
#include <cmath>
#include <vector>
#include <fstream>
#include <strstream>
#include <istream>
struct data
{
    int index_current;

    std::string op;
    int number;
    int flag = 0;
};
int main()
{
    static int index = 0;
    std::ifstream f("./input.txt");
    if (!f.is_open())
        return false;
    std::vector<data> t;
    while (!f.eof())
    {
        char line[128];
        f.getline(line, 128);
        std::strstream s;
        std::string junk;
        data tmp;
        s << line;
        s >> tmp.op >> tmp.number;
        tmp.index_current = index;
        t.push_back(tmp);
        index++;
    }
    bool find_flag = false;
    int fd = 0;
    int changeflag = 0;
    int final_number;
    for (auto &x : t)
    {
        int dy_index = 0;
        final_number = 0;
        if (x.op == "jmp")
        {
            x.op = "nop";
            fd=1;
            changeflag = x.index_current;
        }
        else if (x.op == "nop")
        {
            x.op = "jmp";
            fd = 2;
            changeflag = x.index_current;
        }
        else
            continue;
        while (t[dy_index].flag == 0)
        {
            t[dy_index].flag++;
            //fmt::print("{} {} {}\n", t[dy_index].op, t[dy_index].number, dy_index);
            if (t[dy_index].op == "jmp")
            {
                dy_index += t[dy_index].number;
            }
            else if (t[dy_index].op == "acc")
            {
                final_number += t[dy_index].number;
                dy_index++;
            }
            else if (t[dy_index].op == "nop")
            {
                dy_index++;
            }

            if (dy_index == 610)
            {
                find_flag = true;
                break;
            }
        }
        for(auto& y:t)
            y.flag = 0;
        if (find_flag)
            break;
        if(fd==1)
        {
            t[changeflag].op = "jmp";
        }
        else if(fd==2)
        {
            t[changeflag].op = "nop";
        }
    }
    if (find_flag)
        fmt::print("{}\n", final_number);
    else
        fmt::print("not find\n");
    fmt::print("{} {}\n", index, final_number);
    /*         switch (line[0])
        {
        case 'j':
            std::strstream s;
            std::string junk;
            data tmp;
            s << line;
            s >> tmp.op >> tmp.number;
            tmp.index_current = index;
            t.emplace_back(tmp);
            break;
        case 'a':
            break;
        case 'n':
            break;
        default:
            break;
        }
        index++;

        if (line[0] == 'j')
        {
            std::strstream s;
            s << line;
            vec3d tmp;
            s >> junk >> tmp.x >> tmp.y >> tmp.z;
            v.emplace_back(tmp);
        }
        else if (line[0] == 'a')
        {
            triangle tmp;
            int one, two, three;
            strstream s;
            s << line;
            s >> junk >> one >> two >> three;
            tmp.p[0] = v[static_cast<int>(one - 1)];
            tmp.p[1] = v[static_cast<int>(two - 1)];
            tmp.p[2] = v[static_cast<int>(three - 1)];
            this->tris.emplace_back(tmp);
        }
        else if(line[0] == 'nop')
        {
 */
    return 0;
}