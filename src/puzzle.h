/*puzzle header by sebastian
Roe.S996299@stu.sanjac.edu*/

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>

class Puzzle
{
public:
    Puzzle(int difficulty = 0);
    bool solve() const;
private:
    static std::vector<std::vector<std::string>> puzzles;
    static std::vector<std::vector<std::string>> answers;
    std::string prompt;
    std::string ans;
    int maxAttempts;
};

std::vector<std::vector<std::string>> Puzzle::puzzles = {{"ohlle", "envenig", "epzzul", "rwdo", "fitrs", "Off the beaten ___", "Animal on California state flag", "Sweetest part of a cake", "Found in an oyster"},

{"crlsbmea", "almteoa", "adevretnu", "runivese", "mdmeui", "5280 feet is one", "part of body above the waist", "One of ____ days...", "inventory clearing event"},

{"proceumt", "mhhrty", "hlymaitc", "lttuadei", "rimesedliivtiu", "City with pyramids in the skyline (capital first letter)", "flightless bird of three letters", "US state with most coastline (capital first letter)", "2009 blockbuster with blue aliens"}};


std::vector<std::vector<std::string>> Puzzle::answers = {{"hello", "evening", "puzzle", "word", "first", "path", "bear", "icing", "pearl"},

{"scramble", "oatmeal", "adventure", "universe", "medium", "mile", "torso", "these", "sale"},

{"computer", "rhythm", "mythical", "altitude", "verisimilitude", "Cairo", "emu", "Alaska", "avatar"}};

Puzzle::Puzzle(int difficulty)
{
    srand(static_cast<unsigned int>(time(0)));
    int which_puzzle = rand() % puzzles[difficulty].size();
    prompt = puzzles[difficulty][which_puzzle];
    ans = answers[difficulty][which_puzzle];
    puzzles[difficulty].erase(puzzles[difficulty].begin()+which_puzzle);
    answers[difficulty].erase(answers[difficulty].begin()+which_puzzle);
    switch (difficulty)
    {
    case 0:
        maxAttempts = 6;
        break;
    case 1:
        maxAttempts = 4;
        break;
    case 2:
        maxAttempts = 2;
        break;
    }
}

bool Puzzle::solve() const
{
    std::string response;
    int tried = 0;
    std::cout << "Solve the following puzzle (enter in all lowercase unless told otherwise): " << prompt << std::endl;
    std::cin >> response;
    while (response != ans)
    {
        tried++;
        if (tried == maxAttempts)
            return false;
        std::cout << "Incorrect answer. Try Again.\n";
        std::cin >> response;
    }
    return true;
}


