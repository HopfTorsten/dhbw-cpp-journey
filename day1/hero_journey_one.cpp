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

/**
 * Program to run
 */
int main(){
    printf("hello world");
}

