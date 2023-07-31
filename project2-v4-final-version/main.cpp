#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

int rollDice();

void initializePlayers(int &numP, std::string *&names);
void playGame(int numP, std::string *names);
void cleanupPlayers(std::string *&names);
void createPIN(int *pin, int size);
bool validatePIN(int *pin, int *enterP, int size);

int main()
{

    std::srand(static_cast<unsigned>(std::time(0)));

    int numP;
    std::string *names = nullptr;
    char hello;
    char bankNum;
    const int pinSize = 4;
    int userPIN[pinSize];

    std::cout << "WELCOME TO MY PROGRAM" << std::endl
              << std::endl;

    std::cout << "The only thing you need for this program is a valid pin number." << std::endl;

    std::cout << "But first we are gonna need to go to the store and buy the game. Make sure you have your credit card handy becuase you are gonna need it." << std::endl
              << std::endl
              << "Oh shoot I forgot my pin number let me go in my app and make a new one." << std::endl;
    do
    {
        std::cout << "Loading...BANK OF AMERICA APP \nPress '1' to reset your PIN NUMBER" << std::endl;
        std::cin >> bankNum;

    } while (bankNum != '1');

    std::cout << "Create your " << pinSize << "-digit PIN number.\n";

    createPIN(userPIN, pinSize);

    std::cout << "Your PIN is created successfully.\n\n"
              << "You are now able use your credit card and purchase what ever you would like!!!\n\n"
              << "The first thing I will purchase is a Dice Game for me an my Buddies to play. OFF TO WALMART\n"
              << std::endl;

    std::cout << "Nice you found the game and its only $20.99" << std::endl
              << "Lets go to the register!!!" << std::endl;

    do
    {
        std::cout << "Hello Im karen your cashier here at Walmart. Are you having a good day?(y/n)" << std::endl;
        std::cin >> hello;
        if (hello == 'y' || hello == 'Y')
        {
            std::cout << "That is awesome that you are a having a good day. Im also having a good day!!!" << std::endl
                      << std::endl;
        }
        else if (hello == 'n' || hello == 'N')
        {
            std::cout << "Im sorry that you are not having a good day. I hope your new game can cheer you up." << std::endl
                      << std::endl;
        }

    } while (!(hello == 'y' || hello == 'Y' || hello == 'n' || hello == 'N'));

    std::cout << "Please Insert your credit card so you can pay for your new Dice Game. Insert your Credit card now and wait till it says enter Pin Number\n"
              << std::endl;

    bool pinValid = false;

    do
    {
        std::cout << "Please enter your " << pinSize << "-digit PIN" << std::endl;
        int enterP[pinSize];
        for (int i = 0; i < pinSize; ++i)
        {
            std::cout << "Enter digit " << i + 1 << ": ";
            std::cin >> *(enterP + 1);
        }

        if (validatePIN(userPIN, enterP, pinSize))
        {
            std::cout << "Pin is Correct!!!" << std::endl
                      << "Enjoy your game with your friends!\n"
                      << std::endl;
            pinValid = true;
        }
        else
        {
            std::cout << "Invalid PIN! Please try again." << std::endl;
        }
    } while (!pinValid);

    std::cout << "Awesome we got the new dice game lets go home a play it" << std::endl
              << std::endl;

    std::cout << "WELCOME TO THE DICE GAME!!!\n"
              << std::endl;
    std::cout << "THIS IS A NEW AND IMPROVED DICE GAME FROM THE ONE BEFORE. MORE AVAILABILITY TO PLAY WITH MORE PEOPLE. " << std::endl
              << "MORE PEOPLE = MORE FUN :)" << std::endl
              << std::endl;

    std::cout
        << "You will be playing a game of Dice with 2 or more players you will be able to decide how many people play. " << std::endl
        << "You will each get a turn so its fair and after the first round you can decide whether you still want to play by choosing y/n. " << std::endl
        << "By choosing 'y' you will play another round and by choosing 'n' the game will end and tell you the winners of the game." << std::endl
        << std::endl;

    initializePlayers(numP, names);
    playGame(numP, names);
    cleanupPlayers(names);

    return 0;
}

int rollDice()
{
    return rand() % 6 + 1;
}
void initializePlayers(int &numP, std::string *&names)
{
    do
    {
        std::cout << "Enter the number of players (2 or more): ";
        std::cin >> numP;
        if (numP < 2)
        {
            std::cout << "Please enter a valid number of players so you can enjoy the game and have some fun!!!" << std::endl;
        }

    } while (numP < 2);

    names = new std::string[numP];

    for (int i = 0; i < numP; i++)
    {
        std::cout << "ENTER OPPONENT NUMBER " << i + 1 << ": ";
        std::cin >> *(names + i);
    }
}
void playGame(int numP, std::string *names)
{
    int *scores = new int[numP]();

    char playAgain;

    do
    {
        for (int i = 0; i < numP; i++)
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

    for (int i = 1; i < numP; i++)
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
void createPIN(int *pin, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << "Enter digit " << i + 1 << ": ";
        std::cin >> *(pin + 1);
    }
}

bool validatePIN(int *pin, int *enterP, int size)
{
    if (size != 4)
    {
        return false;
    }

    for (int i = 0; i < size; ++i)
    {
        if (*(pin + 1) != *(enterP + 1))
        {
            return false;
        }
    }

    return true;
}
