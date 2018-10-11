#ifndef CPP_RANDOM_DHBW
#define CPP_RANDOM_DHBW

#include <random>
#include <iostream>
//Will be used to obtain a seed for the random number engine
std::random_device rd;
    //Standard mersenne_twister_engine seeded with rd()
std::mt19937 gen(rd());

int GetRandomNumberBetween(int lower, int upper){
    std::uniform_int_distribution<> dis(lower, upper);
    return dis(gen);
}


#endif