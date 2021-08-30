#include <fmt/core.h>
#include <cmath>
#include <set>
#include <fstream>
#include <strstream>
#include <istream>
#include <vector>

std::vector<std::string> vec_tmp;
std::vector<std::string> vec;

bool *flag = nullptr;

bool charge_empty(int i, int j)
{
    if (vec[i - 1][j] == '#' || 
        vec[i + 1][j] == '#' || 
        vec[i][j - 1] == '#' || 
        vec[i][j + 1] == '#' || 
        vec[i - 1][j - 1] == '#' || 
        vec[i + 1][j + 1] == '#' || 
        vec[i - 1][j + 1] == '#' || 
        vec[i + 1][j - 1] == '#')
        return false;
    else
        return true;
}
bool charge_use(int i, int j)
{
    int tmp_sum = 0;

    if (vec[i - 1][j] == '#')
        tmp_sum++;
    if (vec[i + 1][j] == '#')
        tmp_sum++;
    if (vec[i][j - 1] == '#')
        tmp_sum++;
    if (vec[i][j + 1] == '#')
        tmp_sum++;
    if (vec[i - 1][j + 1] == '#')
        tmp_sum++;
    if (vec[i + 1][j + 1] == '#')
        tmp_sum++;
    if (vec[i - 1][j - 1] == '#')
        tmp_sum++;
    if (vec[i + 1][j - 1] == '#')
        tmp_sum++;
    if (tmp_sum > 3)
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

    int size = (vec.size() ) * (vec[0].size());
    flag = new bool[size];

    while (true)
    {
        memset(flag, false, size);
        bool change_flag = false;
        // 进行判断是否需要更改状态;
        for (int i = 1; i < vec.size() -1; i++)
        {
            for (int j = 1; j < vec[i].size() -1; j++)
            {
                if (vec[i][j] == 'L')
                    flag[i * vec[0].size() + j] = charge_empty(i, j) ;
                else if (vec[i][j] == '#')
                {
                    flag[i * vec[0].size() + j] = charge_use(i, j);
                }
            }
        }
        // 进行状态的改变
        for (int i = 1; i < vec.size()  -1 ; i++)
        {
            for (int j = 1; j < vec[i].size() -1   ; j++)
            {
                if (flag[i * vec[0].size() + j])
                {
                    if (vec[i][j] == 'L')
                    {
                        vec[i][j] = '#';
                        change_flag = true;
                    }
                    else if (vec[i][j] == '#')
                    {
                        vec[i][j] = 'L';
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