#include <fmt/core.h>
#include <cmath>
#include <set>
#include <fstream>
#include <strstream>
#include <istream>
#include <vector>

#include <unordered_map>

std::vector<std::string> vector_address;

void find(std::string str, long long index)
{

    if (index == 36)
    {
        vector_address.push_back(str);
        return;
    }
    if (str[index] == 'X')
    {
        std::string str_one = str;
        str_one[index] = '1';
        find(str_one, index + 1);

        std::string str_two = str;
        str_two[index] = '0';
        find(str_two, index + 1);
    }
    else
    {
        find(str, index + 1);
    }
}

long long strtobin(std::string str)
{
    long long b = 0;
    long long tmp_3 = 1;
    for (int i = 0; i < 36; i++)
    {
        long long tmp_b = tmp_3 << (35 - i);
        if (str[i] == '1')
            b |= tmp_b;
    }
    return b;
}

int main()
{
    std::ifstream f("./input.txt");
    if (!f.is_open())
        return false;

    std::unordered_map<long long, long long> vec;

    std::string mask;
    long long index;
    long long value;
    while (!f.eof())
    {
        char line[128];
        std::string junk;
        f.getline(line, 128);
        std::strstream s;
        std::string str;
        s << line;
        s >> str;
        if (str[1] == 'a')
        {
            s >> junk;
            s >> mask;
        }
        else if (str[1] == 'e')
        {

            //fmt::print("{}\n", str);
            index = std::stoull(str.substr(4));
            //fmt::print("{}\n", index);
            s >> junk;
            s >> value;
            std::string tmp_mask(36, 0);
            for (int i = 0; i < 36; i++)
            {
                //fmt::print("{}\n", index);
                long long tmp_index = index;
                tmp_index >>= (35 - i);
                tmp_index &= 0x1;
                if (mask[i] == '0')
                {
                    tmp_mask[i] = std::to_string(tmp_index)[0];
                }
                else if (mask[i] == 'X')
                {
                    tmp_mask[i] = 'X';
                }
                else if (mask[i] == '1')
                {
                    long long tmp = 1;
                    tmp_mask[i] = std::to_string(tmp)[0];
                }
            }
            //fmt::print("{}\n", tmp_mask);
            find(tmp_mask, 0);

            for (const auto &x : vector_address)
            {
                long long tmp_index = strtobin(x);
                // fmt::print("{} {} {} \n", x, tmp_index,value);
                vec.insert_or_assign(tmp_index, value);
            }
            vector_address.clear();
        }
    }

    long long sum = 0;
    for (const auto &x : vec)
    {
        sum += x.second;
        // fmt::print("{} {} \n", x.first,x.second);
    }
    fmt::print("{}\n", sum);

    //fmt::print("{}\n", strtobin(std::string("100000000000000000000000000000011011")));
    return 0;
}
// 1010 0000 0000 0000 0000 0000 0000 00X1 101X