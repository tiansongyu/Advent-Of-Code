#include <fmt/core.h>
#include <cmath>
#include <set>
#include <fstream>
#include <strstream>
#include <istream>
#include <vector>
#include <unordered_map>

static std::unordered_map<size_t, size_t> sumFrom;

std::set<int> t;
std::vector<int> vec;
long long al(int step, int last_value)
{
    long long sum = 0;
    if (step == vec.size())
        return sum;
    for (int i = step; i < vec.size(); i++)
    {
        if (vec[i] > 160 || vec[i] - last_value > 3)
            break;
        else if (vec[i] == 160)
        {
            sum++;
            break;
        }

        if (sumFrom.count(vec[i]) == 1)
        {
            sum += sumFrom[vec[i]];
        }
        else
        {
            long long tmp = al(i + 1, vec[i]);
            sumFrom[vec[i]] = tmp;
            sum += tmp;
        }
    }
    return sum;
    /*     
        fmt::print("{} {}\n", vec[step], vec[last_step]);
    */
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
        int number;
        s << line;
        s >> number;
        t.insert(number);
    }
    for (auto &x : t)
    {
        vec.push_back(x);
    }

    for (auto &x : vec)
    {
        fmt::print("vec: {}\n", x);
    }
    fmt::print("sum: {}\n", al(0, 0));
    return 0;
}