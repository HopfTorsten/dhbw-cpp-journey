#include <random>
#include <iostream>

int main()
{
    //Will be used to obtain a seed for the random number engine
    std::random_device rd;
    //Standard mersenne_twister_engine seeded with rd()
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);
    // role the dice 10 times
    for (int n = 0; n < 10; ++n)
        //Use dis to transform the random unsigned int generated
        //by gen into an int in [1, 6]
        std::cout << dis(gen) << ' ';
    std::cout << '\n';
}