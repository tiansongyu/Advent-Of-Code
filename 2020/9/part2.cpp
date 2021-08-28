#include <fmt/core.h>
#include <cmath>
#include <vector>
#include <fstream>
#include <strstream>
#include <istream>

int main()
{
    std::ifstream f("./input.txt");
    if (!f.is_open())
        return false;
    std::vector<long long> t;
    while (!f.eof())
    {
        char line[128];
        f.getline(line, 128);
        std::strstream s;
        long long number;
        s << line;
        s >> number;
        t.push_back(number);
    }
    static int index = 25;
    bool flag = true;
    while (index < 1000)
    {
        int start = index - 25;
        bool tmp_flag = false;
        for (int i = start; i < index - 1; i++)
        {
            for (int j = start + 1; j < index; j++)
            {
                if (i == j)
                    continue;
                if (t[i] + t[j] == t[index])
                    tmp_flag = true;
            }
        }
        if (!tmp_flag)
            break;
        index++;
    }
    long long return_number = 0;
    int min_index = 0;
    int max_index = 0;
    for (int i = 0; i < index; i++)
    {
        long long sum = 0;
        int tmp_index = i;
        while(sum < t[index])
        {
            sum += t[tmp_index];
            if(sum == t[index])
            {
                return_number = t[i] + t[tmp_index];
                min_index = i;
                max_index = tmp_index;
                goto end;
            }
            tmp_index++;
        }
    }
end:
    long long min = t[min_index],max= t[max_index];
    for (int i = min_index; i <= max_index; i++)
    {
        if(t[i]<min)
            min = t[i];
        if(t[i]>max)
            max = t[i];
    }

        fmt::print("{}\n", min+max);
        fmt::print("{}\n", return_number);
        return 0;
}