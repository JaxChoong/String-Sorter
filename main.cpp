#include <vector>
#include <random>
#include <iostream>
#include <fstream>


std::vector<char> ascendingSort(std::vector<char> alphabets)
{
    bool sorted = false;
    while (sorted == false)
    {
        bool moved = false;
        for(int i = 0; i < alphabets.size() - 1; i++)
        {
            if (alphabets[i] > alphabets[i + 1])
            {
                char temp = alphabets[i];
                alphabets[i] = alphabets[i + 1];
                alphabets[i + 1] = temp;
                moved = true;
            }
        }
        if (moved == false)
        {
            sorted = true;
        }
    }
    return alphabets;
}

std::vector<char> descendingSort(std::vector<char> alphabets)
{
    bool sorted = false;
    while (sorted == false)
    {
        bool moved = false;
        for(int i = 0; i < alphabets.size() - 1; i++)
        {
            if (alphabets[i] < alphabets[i + 1])
            {
                char temp = alphabets[i];
                alphabets[i] = alphabets[i + 1];
                alphabets[i + 1] = temp;
                moved = true;
            }
        }
        if (moved == false)
        {
            sorted = true;
        }
    }
    return alphabets;
}

std::vector<char> sortAlphabets(std::vector<char> alphabets, char sortWay)
{
    if (sortWay == '<')
    {
        return ascendingSort(alphabets);
    }
    else
    {
        return descendingSort(alphabets);
    }
 
}

void writeFile(std::vector<char> alphabets)
{
    std::ofstream file;
    file.open("sorted_alphabets.txt");
    for (auto c : alphabets)
    {
        file << c << " ";
    }
    file.close();
}

int main()
{
    char sortWay;
    // get user input for sorting
    while (sortWay != '<' || sortWay != '>')
    {
        std::cout << "Enter '<' to sort in ascending order or '>' to sort in descending order: ";
        std::cin >> sortWay;
        if (sortWay == '<' || sortWay == '>')
        {
            break;
        }
        else
        {
            std::cout << "Invalid input. Please enter '<' or '>'.\n";
        }
    }
    std::vector<char> alphabets;
    std::random_device rd;
    std::mt19937 gen(rd());
    // Random number between 0 and 51
    // since there are 52 alphabets
    std::uniform_int_distribution<> dis(0, 51);

    while (alphabets.size() < 6)
    {
        // generate random character
        char c = 'A' + dis(gen);
        // if character is between 'Z' and 'a' then add 26 to it
        // to get the missing characters in the gap
        if (c > 'Z' && c < 'a')
        {
            c+= 26;
        }
        alphabets.push_back(c);
    }   
    alphabets = sortAlphabets(alphabets, sortWay);
    writeFile(alphabets);
    return 0;
} 