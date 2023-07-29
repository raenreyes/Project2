#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Dice
{

public:
    int finalScore = 0;
    int currentScore = 0;
    int roll();
    int printRoll();
    int checkRoll()
    {
        return finalScore;
    }
};

int main(int argc, char **argv)
{

    Dice playerDice;
    Dice computerDice;
    char option;
    string playerName;
    string computerName;

    std::cout << "DICE GAME. YOU WILL ROLL 5 TIMES." << std::endl;
    std::cout << "Before you play I will need your player_name you will like to use." << std::endl;
    std::cin >> playerName;
    std::cout << "Now that I have your name you have to name your enemy which will be the computer." << std::endl;
    std::cin >> computerName;

    do
    {
        for (int i = 0; i < 5; i++)
        {
            if (i > 0)
            {
                if (playerDice.checkRoll() > computerDice.checkRoll())
                {
                    std::cout << "Boom you just won that round. Good Job!!!" << std::endl;
                }
                else if (playerDice.checkRoll() < computerDice.checkRoll())
                {

                    std::cout << "Ahh you lost to the computer. Its okay keep trying and win the next one." << std::endl;
                }
                std::cout << "Score:\n"
                          << playerName << ": " << playerDice.checkRoll() << ", " << computerName << ": " << computerDice.checkRoll() << std::endl;
            }
            char key;
            std::cout << "Press any key then hit enter to continue" << std::endl;
            std::cin >> key;
            std::cout << endl;

            std::cout << "Your time to roll" << std::endl;
            playerDice.roll();
            std::cout << "Now the computers time to roll" << std::endl;
            std::cout << "Press any key then enter to keep it going." << std::endl;
            std::cin >> key;
            computerDice.roll();
        }
        if (playerDice.checkRoll() > computerDice.checkRoll())
        {
            std::cout << "LET'S GO YOU WON THAT ROUND!!!" << std::endl;
        }
        if (playerDice.checkRoll() < computerDice.checkRoll())
        {
            std::cout << "Dang man you lost that round" << std::endl;
        }
        std::cout << "Final Score:\n"
                  << playerName << ": " << playerDice.checkRoll() << ", " << computerName << ": " << computerDice.checkRoll() << std::endl;
        if (playerDice.checkRoll() > computerDice.checkRoll())
        {
            std::cout << playerName << " YOU JUST WON THE DICE CHAMPIONSHIP!!! YOU ARE NOW THE CHAMPION!!!" << std::endl;
        }
        if (playerDice.checkRoll() < computerDice.checkRoll())
        {
            std::cout << "Man that sucks you just lost to " << computerName << " get them next time." << std::endl;
        }

        std::cout << "Would you like to play again? (y/n)" << std::endl;
        std::cin >> option;

    } while (option == 'y' || option == 'Y');

    return 0;
}

int Dice::roll()
{
    int zero;
    zero = time(0);
    srand(zero);
    for (int i = 0; i < 2; i++)
    {
        currentScore = rand() % 6 + 1;
        finalScore = finalScore + currentScore;
        printRoll();
    }
    return 0;
}
int Dice::printRoll()
{
    if (currentScore == 1)
    {
        std::cout << "-------\n"
                  << "|     |\n"
                  << "|  0  |\n"
                  << "|     |\n"
                  << "-------\n"
                  << "That is a 1" << std::endl;
    }
    else if (currentScore == 2)
    {
        std::cout << "-------\n"
                  << "|  0  |\n"
                  << "|     |\n"
                  << "|  0  |\n"
                  << "-------\n"
                  << "That is a 2" << std::endl;
    }
    else if (currentScore == 3)
    {
        std::cout << "-------\n"
                  << "|  0  |\n"
                  << "|  0  |\n"
                  << "|  0  |\n"
                  << "-------\n"
                  << "That is a three" << std::endl;
    }
    else if (currentScore == 4)
    {
        std::cout << "-------\n"
                  << "|0   0|\n"
                  << "|     |\n"
                  << "|0   0|\n"
                  << "-------\n"
                  << "That is a four" << std::endl;
    }
    else if (currentScore == 5)
    {
        std::cout << "-------\n"
                  << "|0   0|\n"
                  << "|  0  |\n"
                  << "|0   0|\n"
                  << "-------\n"
                  << "That is a five" << std::endl;
    }
    else if (currentScore == 6)
    {
        std::cout << "-------\n"
                  << "|0   0|\n"
                  << "|0   0|\n"
                  << "|0   0|\n"
                  << "-------\n"
                  << "That is a six" << std::endl;
    }
    return 0;
}
