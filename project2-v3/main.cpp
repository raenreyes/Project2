#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

int rollDice();

void initializePlayers(int &numPlayers, std::string *&names);
void playGame(int numPlayers, std::string *names);
void cleanupPlayers(std::string *&names);

int main()
{
    std::srand(static_cast<unsigned>(std::time(0)));

    int numPlayers;
    std::string *names = nullptr;

    std::cout << "WELCOME TO THE DICE GAME!!!" << std::endl
              << std::endl;
    std::cout << "THIS IS A NEW AND IMPROVED DICE GAME FROM THE ONE BEFORE. MORE AVAILABILITY TO PLAY WITH MORE PEOPLE. " << std::endl
              << "MORE PEOPLE = MORE FUN :)" << std::endl
              << std::endl;

    std::cout
        << "You will be playing a game of Dice with 2 or more players you will be able to decide how many people play. " << std::endl
        << "You will each get a turn so its fair and after the first round you can decide whether you still want to play by choosing y/n. " << std::endl
        << "By choosing 'y' you will play another round and by choosing 'n' the game will end and tell you the winners of the game." << std::endl
        << std::endl;

    initializePlayers(numPlayers, names);
    playGame(numPlayers, names);
    cleanupPlayers(names);

    return 0;
}

int rollDice()
{
    return rand() % 6 + 1;
}
void initializePlayers(int &numPlayers, std::string *&names)
{
    do
    {
        std::cout << "Enter the number of players (2 or more): ";
        std::cin >> numPlayers;
        if (numPlayers < 2)
        {
            std::cout << "Please enter a valid number of players so you can enjoy the game and have some fun!!!" << std::endl;
        }

    } while (numPlayers < 2);

    names = new std::string[numPlayers];

    for (int i = 0; i < numPlayers; i++)
    {
        std::cout << "ENTER OPPONENT NUMBER " << i + 1 << ": ";
        std::cin >> *(names + i);
    }
}
void playGame(int numPlayers, std::string *names)
{
    int *scores = new int[numPlayers]();

    char playAgain;

    do
    {
        for (int i = 0; i < numPlayers; i++)
        {
            int result = rollDice();
            *(scores + i) += result;

            std::cout << *(names + i) << " rolled a " << result << "." << std::endl;

            if (result == 1)
            {
                std::cout << "-------\n"
                          << "|     |\n"
                          << "|  0  |\n"
                          << "|     |\n"
                          << "-------\n"
                          << "That is a 1" << std::endl;
            }
            else if (result == 2)
            {
                std::cout << "-------\n"
                          << "|  0  |\n"
                          << "|     |\n"
                          << "|  0  |\n"
                          << "-------\n"
                          << "That is a 2" << std::endl;
            }
            else if (result == 3)
            {
                std::cout << "-------\n"
                          << "|  0  |\n"
                          << "|  0  |\n"
                          << "|  0  |\n"
                          << "-------\n"
                          << "That is a three" << std::endl;
            }
            else if (result == 4)
            {
                std::cout << "-------\n"
                          << "|0   0|\n"
                          << "|     |\n"
                          << "|0   0|\n"
                          << "-------\n"
                          << "That is a four" << std::endl;
            }
            else if (result == 5)
            {
                std::cout << "-------\n"
                          << "|0   0|\n"
                          << "|  0  |\n"
                          << "|0   0|\n"
                          << "-------\n"
                          << "That is a five" << std::endl;
            }
            else if (result == 6)
            {
                std::cout << "-------\n"
                          << "|0   0|\n"
                          << "|0   0|\n"
                          << "|0   0|\n"
                          << "-------\n"
                          << "That is a six" << std::endl;
            }

            std::cout << *(names + i) << "'s total score: " << *(scores + i) << std::endl;
        }

        std::cout << "Roll again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    int maxScore = scores[0];
    int winner = 0;

    for (int i = 1; i < numPlayers; i++)
    {
        if (*(scores + i) > maxScore)
        {
            maxScore = *(scores + i);
            winner = i;
        }
    }

    std::cout << "The winner is: " << names[winner] << " with a score of " << maxScore << std::endl;

    delete[] scores;
}
void cleanupPlayers(std::string *&names)
{
    delete[] names;
}