#include <fmt/core.h>
#include <cmath>
#include <set>
#include <fstream>
#include <strstream>
#include <istream>
#include <vector>

void fix(std::string &str, int index)
{
    int left_number = 0, right_number = 0;
    int left_no = 0,
        right_no = 0;
    bool left_success = false, right_success = false;
    int left_index = index;
    int right_index = index;

    int flag_left_index = 0;
    int flag_right_index = str.size() - 1;
    while (left_index >= 0)
    {
        left_index--;

        if (str[left_index] == ']')
        {
            left_no++;
        }

        if (str[left_index] == '[')
        {
            if (left_no == 0)
            {
                
                break;
            }
            else
            {
                left_no--;
            }
        }

        if (str[left_index] == '}')
        {
            left_number++;
        }
        if (str[left_index] == '{')
        {
            if (left_number == 0)
            {
                left_success = true;
                flag_left_index = left_index;
                fmt::print("{}\n", str[left_index + 2]);
                break;
            }
            else
            {
                left_number--;
            }
        }
    }
    while (right_index <= str.size())
    {
        right_index++;

        if (str[right_index] == '[')
        {
            right_no++;
        }

        if (str[right_index] == ']')
        {
            if (right_no == 0)
            {
                break;
            }
            else
            {
                right_no--;
            }
        }
        

        if (str[right_index] == '{')
        {
            right_number++;
        }
        if (str[right_index] == '}')
        {
            if (right_number == 0)
            {
                right_success = true;
                flag_right_index = right_index;
                fmt::print("{}\n", str[right_index - 2]);
                break;
            }
            else
            {
                right_number--;
            }
        }
    }

    if (left_success && right_success)
    {
        for (int i = flag_left_index; i <= flag_right_index; i++)
        {
            str[i] = 't';
        }
    }
}
int main()
{
    std::ifstream f("./input.txt");
    if (!f.is_open())
        return false;
    while (!f.eof())
    {
        char line[999999];
        std::string junk;
        f.getline(line, 999999);
        std::strstream s;
        std::string str;
        s << line;
        s >> str;

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == 'r' && str[i + 1] == 'e' && str[i + 2] == 'd')
                fix(str, i);
        }

        std::vector<int> number_vec;
        for (int i = 0; i < str.size();)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                size_t amt = 0;
                int bus = std::stoi(str.substr(i), &amt);
                number_vec.emplace_back(bus);
                i += amt;
                //fmt::print("{}\n", str[i]);
            }
            else if (str[i] == '-')
            {
                size_t amt = 0;
                int bus = std::stoi(str.substr(i + 1), &amt);
                number_vec.emplace_back(bus * -1);
                i += amt + 1;
            }
            else
            {
                i++;
                //fmt::print("{}\n", str[i]);
            }
        }
        int sum = 0;
        for (auto &x : number_vec)
            sum += x;
        fmt::print("{}\n", sum);
        //fmt::print("{}\n", str);

        return 0;
    }
}
