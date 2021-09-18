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
    int all_sum = 0;
    while (!f.eof())
    {
        char line[128];
        f.getline(line, 128);
        std::strstream s;
        std::string str;
        s << line;
        s >> str;

        bool flag_same = false;
        bool flag = true;

        for (int i = 1; i < str.size();i++)
        {
            if(str[i-1]==str[i])
                flag_same = true;
            if((str[i-1] =='a'&&str[i]=='b')||
                (str[i-1] =='c'&&str[i]=='d')||
                (str[i-1] =='p'&&str[i]=='q')||
                (str[i-1] =='x'&&str[i]=='y'))
                flag = false;
        }
        int sum = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' )
                sum++;
        }
        if(flag_same&&flag&& sum>=3)
            all_sum++;
    }
    fmt::print("{}\n", all_sum);
    return 0;
}