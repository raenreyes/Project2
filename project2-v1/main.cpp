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
        std::cin >> names[i];
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
            scores[i] += result;

            std::cout << names[i] << " rolled a " << result << "." << std::endl;

            std::cout << names[i] << "'s total score: " << scores[i] << std::endl;
        }

        std::cout << "Roll again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    int maxScore = scores[0];
    int winner = 0;

    for (int i = 1; i < numPlayers; i++)
    {
        if (scores[i] > maxScore)
        {
            maxScore = scores[i];
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