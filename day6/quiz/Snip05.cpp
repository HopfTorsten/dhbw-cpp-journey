#include <iostream>
class Profile
{
  public:
    virtual std::string &getName() = 0;
    virtual char getGender() = 0;
    virtual int getAge() = 0;
    virtual ~Profile(){};
};

class OldMan : public Profile
{
    std::string name = "Klaus";
    public:
        virtual std::string &getName() override { return this->name; };
        virtual char getGender() override { return 'M'; };
        virtual int getAge() override { return 65; };
        ~OldMan(){};
};

int main()
{
    Profile *profile = new OldMan();


    printf("Having a young old man here: %s, %c, %d\n",
        profile->getName().c_str(), //
        profile->getGender(), //
        profile->getAge()); //
    delete profile;
    return 0x00;
}