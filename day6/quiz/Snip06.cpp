#include <iostream>
class fucking_big_class
{
  private:
    char buf[1024];
    char buf_2[2048];
    int64_t big_number_of_numbers[4096];

  public:
    char *getBuf2() { return buf_2; };
};

void do_something_smart(fucking_big_class big_class_p)
{
    printf("Yeah yeah very Big! %s", big_class_p.getBuf2());
}

int main()
{
    fucking_big_class biggi;
    do_something_smart(biggi);
    return 0x00;
}