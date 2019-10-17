#include <random>

int main()
{
    // Initialise random engine with seed
    // seed is the current seconds sind 1970
    srand((unsigned)time(NULL));

    // dice
    int max = 6;
    int min = 1;

    for(int i=0;i<10;++i){
        printf("%i. result: %i\n",i,
        rand() % (max - min +1) + min
        /*Getting a random number*/
        );
    }

    return 0;
}