#include <iostream>
class Profile
{
  public:
    virtual std::string &getName() = 0;
    virtual char getGender() = 0;
    virtual int getAge() = 0;
};

class OldMan : public Profile
{
    std::string name = "Klaus";
    public:
        virtual std::string &getName() override { return this->name; };
        virtual char getGender() override { return 'M'; };
        virtual int getAge() override { return 65; };
};

int main()
{
    OldMan oldMan;
    printf("Having a young old man here: %s, %c, %d\n",
        oldMan.getName().c_str(), //
        oldMan.getGender(), //
        oldMan.getAge()); //
    return 0x00;
}