// Advent of Code (2020) Day 15
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <fmt/core.h>

static constexpr int wantedTurn = 30000000;

int main(void)
{
    std::unordered_map<int, int> lastTurn;
    std::unordered_map<int, int> olderTurn;
    int tmp;
    int turn = 1;
    int spoken;

    std::ifstream file("input.txt");
    while (file >> tmp)
    {
        lastTurn[tmp] = turn;
        olderTurn[tmp] = turn;
        spoken = tmp;
        turn++;

        char comma;
        file >> comma;
    }
    // spoken是说的数字
    while (turn <= wantedTurn)
    {
        if (turn % 1000000 == 0)
        {
            std::cout << "Up to turn: " << turn << std::endl;
        }
        // spoken记录上次最后说的数字
        if (lastTurn.count(spoken) == 0)
            spoken = 0;
        else
            spoken = lastTurn[spoken] - olderTurn[spoken];

        // 如果没有说过，这次即为第一次说，记录到lastTurn
        if (lastTurn.count(spoken) == 0)
        {
            // 建立一个新的
            lastTurn[spoken] = turn;
        }
        // 将这次说的记录到olderTurn中
        olderTurn[spoken] = lastTurn[spoken];
        // 更新lastTurn
        lastTurn[spoken] = turn;
        turn++;
    }
    fmt::print("{}\n", spoken);
    return 0;
}