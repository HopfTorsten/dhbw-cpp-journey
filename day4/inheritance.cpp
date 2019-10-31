#include <iostream>

class Auto
{
public:
    void gibGas()
    {
        printf("Wrumm Wrumm\n");
    }
};
class Sportwagen : public Auto
{
public:
    void gibGas()
    {
        printf("Sportlich Wrumm Wrumm\n");
    }
};

void soundTest(Auto *testeEs)
{
    testeEs->gibGas();
}

int main()
{
    Auto fiesta;
    Sportwagen panamera;

    soundTest(&fiesta);
    soundTest(&panamera);

    return 0x0;
}