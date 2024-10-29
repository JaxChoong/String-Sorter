#include <vector>
#include <random>
#include <iostream>

int main()
{
    std::vector<char> alphabets;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 51);

    while (alphabets.size() < 6)
    {
        char c = 'A' + dis(gen);
        if (c > 'Z' && c < 'a')
        {
            c+= 26;
        }
        alphabets.push_back(c);
    }   
    std::cout << "Random alphabets: ";
    for (auto c : alphabets)
    {
        std::cout << c << " ";
    }
    return 0;
} 