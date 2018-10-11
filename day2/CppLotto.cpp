#include "CppRandom.hpp"
#include <iostream>


/**
 * Build an App which allows you the play Lotto "6 out of 49"
 * 
 * 1.   Generate an Array or Vector with the Numbers from 1 to 49
 * 
 * 2.   Let the user enter his 6 selected numbers and don't forget to
 *      check for range and duplications
 * 
 * 3.   Draw 6 numbers out of the 49 randomly and display them to the 
 *      user
 * 
 * 4.   Compare them to see how many correct numbers where selected
 *      -> You can use std::sort if you need to sort something:
 *          std::sort(intArray, intArray + SIZE);
 * Will you be able to win something?
 *      
 * 
 */


int main()
{

    for (int i = 0; i < 100; ++i)
    {
        std::cout << i << ":" << GetRandomNumberBetween(1, 6) << ::std::endl;
    }
    return 0;
}