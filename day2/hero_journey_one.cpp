#include <iostream>
#include <vector>

// We put this stuff here, so that the main method can see them,
// if they are not declared before they are used -> Compile error
// We come here again if we get to headers

/*
* Displays all heroes in the vector and makes it possible 
* to select one. 
* The return value is the position of the element in the vector.
*/
int ShowHeroSelect(std::vector<std::string> &heroes);

/**
 * Displays the initial menu, which gives you the possibility to
 * a) Create a new Hero
 * b) Start a new game by selecting a hero
 * c) close the application
 */
int ShowStartMenuSelect();

/**
 * Creates a new Hero, which is nothing more but a string cointaining 
 * it's name , and add it to the inserted vector of strings
 * 
 */
void CreateAndAddHero(std::vector<std::string> &heroes);

/**
 * Displays a message containing the hero's name,
 * which tells about the encouraging adventures in the DLC
 * 
 */
void ShowStartDialog(std::string &hero);

void StartGame(std::vector<std::string> &heroes);

/**
 * Program to run
 */
int main()
{
    printf("Welcome to the one and only Cpp Hero Journey");

    std::vector<std::string> heroes;
    while (int mainMenuSelection = ShowStartMenuSelect())
    {
        switch (mainMenuSelection)
        {
        case 1:
            CreateAndAddHero(heroes);
            break;
        case 2:
            StartGame(heroes);
            return 0;
        default:
            std::cout << "No valid option was selected" << std::endl
                      << std::endl;
        }
    }
}

void ShowStartDialog(std::string &hero)
{
    std::cout << "And so did " << hero << " start his way into an adventure with many dangers" << std::endl;
}

void CreateAndAddHero(std::vector<std::string> &heroes)
{
    char buf[255];
    std::cin >> buf;

    std::string name = buf;
    heroes.push_back(name);
}

int ShowHeroSelect(std::vector<std::string> &heroes)
{
    int menuCount = 1;
    std::cout << "Select the hero you want to choose:" << std::endl;
    for (std::string &hero : heroes)
    {
        std::cout << "\t" << menuCount << ": " << hero << std::endl;
        ++menuCount;
    }
    int selection = 0;
    while (selection < 1 || selection > menuCount)
    {
        std::cout << "You choose Hero No: ";
        std::cin >> selection;
    }
    return selection - 1; //-1 because of 0 based index in the list‚
}

/**
 * Displays the initial menu, which gives you the possibility to
 * a) Create a new Hero
 * b) Start a new game by selecting a hero
 * c) close the application
 */
int ShowStartMenuSelect()
{

    std::cout << "Select what you want to do:"
              << std::endl
              << "1:\t Create a hero" << std::endl
              << "2:\t Start an adventure with an already created hero" << std::endl
              << "0: \t Exit the program" << std::endl;

    // defining the variable to put the user input into
    int selection;
    // '>>' operator reads from a stream, in this case the standard input stream
    // type conversation is done by cpp, isn't that great?
    std::cin >> selection;
    return selection;
}

void StartGame(std::vector<std::string> &heroes)
{
    int selectedHeroIndex = ShowHeroSelect(heroes);
    std::string selectedHero = heroes[selectedHeroIndex];
    ShowStartDialog(selectedHero);
}
