#include <iostream>
#include <array>

int main()
{

    // Good new way to create an array of five strings
    std::array<std::string, 5> guests = {"Paul", "Ralf", "Olaf", "Toni", "Karl"};

    // classical for loop
    for (int i = 0; i < guests.size(); ++i)
    {
        // std::cout is a stream which directly leads to the standard out stream of the terminal
        // '<<' is the overloaded operator to wirte something in the stream
        std::cout << "Hello Mr. " << guests[i] << std::endl
                  << "\t Your seat is number " << i << std::endl;
    }

    for(char a='A';a<='Z';++a){
        printf("%c\n",a);
    }

    return 0;
}
