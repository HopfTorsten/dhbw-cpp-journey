#include <csignal>
#include <iostream>

void handle_fault(int sig)
{
    printf("Du Geburt deiner Mutter!");
    std::exit(5);
}

int main()
{

    std::signal(SIGSEGV, handle_fault);

    int *ptr = 0;
    *ptr;

    return 0;
}