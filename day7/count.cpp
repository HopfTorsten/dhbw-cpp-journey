#include <thread>
#include <iostream>
#include <vector>
int main()
{
    int max = 100000;
    int counter = 0;

    auto fun = [&counter, max]() {while(++counter<max); };
    std::vector<std::thread *> threads;
    for (int i = 0; i < 10; ++i)
    {
        std::thread *t = new std::thread(fun);
        threads.push_back(t);
    }
    for (auto &t : threads)
    {
        t->join();
        delete t;
    }

    std::cout << counter << std::endl;
}