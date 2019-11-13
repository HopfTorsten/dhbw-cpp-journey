#include <thread>
#include <chrono>
#include <iostream>
void do_something(int p)
{
    for (int i = 0; i < p; ++i)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Hello from Thread!" << std::endl;
    }
}

int main()
{
    std::cout << "Hallo Starte Thread" << std::endl;
    std::thread sread(do_something, 5);
    std::cout << "Thread gestartet caiptain!" << std::endl;
    sread.join();
    std::cout << "It's all done!" << std::endl;
}