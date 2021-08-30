#include <fmt/core.h>
#include <cmath>
#include <set>
#include <fstream>
#include <strstream>
#include <istream>
#include <vector>

std::vector<std::string> vec_tmp;
std::vector<std::string> vec;

bool charge_empty(int i, int j)
{
    bool flag = true;
    bool up = true, down = true, left = true, right = true,
         up_left = true, dwon_left = true, up_right = true, down_right = true;

    for (int x = 1; x < 100; x++)
    {
        // up
        if (i - x > 0)
        {
            if (vec[i - x][j] == 'L')
                up = false;
            if (up)
                if (vec[i - x][j] == '#')
                    flag = false;
        }
        // down
        if (i + x < vec.size())
        {
            if (vec[i + x][j] == 'L')
                down = false;
            if (down)
                if (vec[i + x][j] == '#')
                    flag = false;
        }
        // left
        if (j - x > 0)
        {
            if (vec[i][j - x] == 'L')
                left = false;
            if (left)
                if (vec[i][j - x] == '#')
                    flag = false;
        }
        // right
        if (j + x < vec[0].size())
        {
            if (vec[i][j + x] == 'L')
                right = false;
            if (right)
                if (vec[i][j + x] == '#')
                    flag = false;
        }

        // up left
        if (i - x > 0 && j - x > 0)
        {
            if (vec[i - x][j - x] == 'L')
                up_left = false;
            if (up_left)
                if (vec[i - x][j - x] == '#')
                    flag = false;
        }
        // down left
        if (i + x < vec.size() && j - x > 0)
        {
            if (vec[i + x][j - x] == 'L')
                dwon_left = false;
            if (dwon_left)
                if (vec[i + x][j - x] == '#')
                    flag = false;
        }

        // up right
        if (i - x > 0 && j + x < vec[0].size())
        {
            if (vec[i - x][j + x] == 'L')
                up_right = false;
            if (up_right)
                if (vec[i - x][j + x] == '#')
                    flag = false;
        }
        // down right
        if (i + x < vec.size() && j + x < vec[0].size())
        {
            if (vec[i + x][j + x] == 'L')
                down_right = false;
            if (down_right)
                if (vec[i + x][j + x] == '#')
                    flag = false;
        }

        if (flag == false)
            break;
    }

    return flag;
}
bool charge_use(int i, int j)
{
    int tmp_sum = 0;
    bool flag = true;
    bool up = true, down = true, left = true, right = true,
         up_left = true, dwon_left = true, up_right = true, down_right = true;

    for (int x = 1; x < 100; x++)
    {
        // up
        if (i - x > 0)
        {
            if (vec[i - x][j] == 'L')
                up = false;
            if (up)
                if (vec[i - x][j] == '#')
                {
                    tmp_sum++;
                    //fmt::print("up {}\n", tmp_sum);
                    up = false;
                }
        }
        // down
        if (i + x < vec.size())
        {
            if (vec[i + x][j] == 'L')
                down = false;
            if (down)
                if (vec[i + x][j] == '#')
                {
                    tmp_sum++;
                    //fmt::print("down {}\n", tmp_sum);

                    down = false;
                }
        }
        // left
        if (j - x > 0)
        {
            if (vec[i][j - x] == 'L')
                left = false;
            if (left)
                if (vec[i][j - x] == '#')
                {
                    tmp_sum++;
                    //fmt::print("left {}\n", tmp_sum);

                    left = false;
                }
        }
        // right
        if (j + x < vec[0].size())
        {
            if (vec[i][j + x] == 'L')
                right = false;
            if (right)
                if (vec[i][j + x] == '#')
                {
                    tmp_sum++;
                    //fmt::print("right {}\n", tmp_sum);

                    right = false;
                }
        }

        // up left
        if (i - x > 0 && j - x > 0)
        {
            if (vec[i - x][j - x] == 'L')
                up_left = false;
            if (up_left)
                if (vec[i - x][j - x] == '#')
                {
                    tmp_sum++;
                    //fmt::print("up_left {}\n", tmp_sum);

                    up_left = false;
                }
        }
        // down left
        if (i + x < vec.size() && j - x > 0)
        {
            if (vec[i + x][j - x] == 'L')
                dwon_left = false;
            if (dwon_left)
                if (vec[i + x][j - x] == '#')
                {
                    tmp_sum++;
                    //fmt::print("dwon_left {}\n", tmp_sum);
                    dwon_left = false;
                }
        }

        // up right
        if (i - x > 0 && j + x < vec[0].size())
        {
            //fmt::print("???\n");
            if (vec[i - x][j + x] == 'L')
                up_right = false;
            if (up_right)
                if (vec[i - x][j + x] == '#')
                {
                    tmp_sum++;
                    //fmt::print("up_left {}\n", tmp_sum);

                    up_right = false;
                }
        }
        // down right
        if (i + x < vec.size() && j + x < vec[0].size())
        {
            if (vec[i + x][j + x] == 'L')
                down_right = false;
            if (down_right)
                if (vec[i + x][j + x] == '#')
                {
                    tmp_sum++;
                    //fmt::print("dwon_left {}\n", tmp_sum);

                    down_right = false;
                }
        }
    }
   // fmt::print("i: {}  j: {}\n\n", i, j);

    if (tmp_sum > 4)
        return true;
    else
        return false;
}
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
        s << line;
        s >> str;
        vec_tmp.push_back(str);
    }
    std::string tmp_emtpy(vec_tmp[0].size() + 2, '.');
    vec.push_back(tmp_emtpy);
    for (int i = 0; i < vec_tmp.size(); i++)
    {
        std::string str_tmp;
        str_tmp.push_back('.');
        str_tmp = str_tmp + vec_tmp[i];
        str_tmp = str_tmp + '.';
        vec.push_back(str_tmp);
    }
    vec.push_back(tmp_emtpy);

    const size_t one = vec[0].size();
    const size_t two = vec.size();
    bool flag[two][one] = {false};

    while (true)
    {
        bool change_flag = false;
        // 进行判断是否需要更改状态;
        for (int i = 0; i < vec.size(); i++)
        {
            for (int j = 0; j < vec[i].size(); j++)
            {
                if (vec[i][j] == 'L')
                    flag[i][j] = charge_empty(i, j);
                else if (vec[i][j] == '#')
                    flag[i][j] = charge_use(i, j);
            }
        }
        // 进行状态的改变
        for (int i = 0; i < vec.size(); i++)
        {
            for (int j = 0; j < vec[i].size(); j++)
            {
                if (flag[i][j])
                {
                    if (vec[i][j] == 'L')
                    {
                        vec[i][j] = '#';
                        change_flag = true;
                        //fmt::print("L = > #  x:{} y:{}\n", j, i);
                    }
                    else if (vec[i][j] == '#')
                    {
                        vec[i][j] = 'L';
                        //fmt::print("# = > L  x:{} y:{}\n", j, i);

                        change_flag = true;
                    }
                }
            }
        }

        if (change_flag == false)
            break;
    }
    int sum = 0;
    for (auto &x : vec)
    {
        fmt::print("{}\n", x);
    }
    for (auto &x : vec)
    {
        for (auto &y : x)
        {
            if (y == '#')
                sum++;
        }
    }
    fmt::print("{}\n", sum);
    return 0;
}