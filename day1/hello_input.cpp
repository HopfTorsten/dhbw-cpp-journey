#include <iostream>
#include <vector>

// We put this stuff here, so that the main method can see them,
// if they are not declared before they are used -> Compile error
// We come here again if we get to headers
int ShowMenuSelect();
void PrintGuests(std::vector<std::string> &guests);
void AddGuest(std::vector<std::string> &guests);
void CheckIfGuestHasArrived(std::vector<std::string> &guests);

int main()
{
    std::vector<std::string> guests;
    // the result the variable creation is the variable selection
    // in C(++) an bool is nothing but an int: 0 = false, everything else true.
    while (int selection = ShowMenuSelect())
    {
        switch (selection)
        {
        case 1:
            PrintGuests(guests);
            break;
        case 2:
            AddGuest(guests);
            break;
        case 3:
            CheckIfGuestHasArrived(guests);
            break;
        default:
            std::cout << "No valid Option was selected." << std::endl;
        }
    }

    return 0;
}

int ShowMenuSelect()
{

    std::cout << "Select what you want to do:"
              << std::endl
              << "1:\t Show available guests" << std::endl
              << "2:\t Add guest to the list" << std::endl
              << "3:\t Ask if a guest has already arrived" << std::endl
              << "0: \t Exit the program" << std::endl;

    // defining the variable to put the user input into
    int selection;
    // '>>' operator reads from a stream, in this case the standard input stream
    // type conversation is done by cpp, isn't that great?
    std::cin >> selection;
    return selection;
}

// Without the '&' we would make a call by value, but what does that mean?
void PrintGuests(std::vector<std::string> &guests)
{
    std::cout << "The following guests are already available:" << std::endl;
    // classical foreach-loop
    // see the '&' ? This means reference, reference is a pointer whose target cannot be changed
    for (std::string &guest : guests)
    {
        std::cout << guest << std::endl;
    }
}

void AddGuest(std::vector<std::string> &guests)
{
    std::cout << "Type in the name of the guest that you want to have added." << std::endl;

    std::string newGuest;
    std::cin >> newGuest;

    guests.push_back(newGuest);

    std::cout << newGuest << " added to the list." << std::endl;
}

void CheckIfGuestHasArrived(std::vector<std::string> &guests)
{

    std::cout << "Type in the name of the guest you're looking for" << std::endl;
    std::string name;
    std::cin >> name;

    for (std::string &guest : guests)
    {
        if (guest.compare(name) == 0)
        {
            std::cout << "The guest " << name << " has already arrived" << std::endl;
            return;
        }
    }
    std::cout << "The guest " << name << " has not yet arrived or you made a typo" << std::endl;
}