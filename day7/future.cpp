#include <thread>
#include <future>
#include <deque>
#include <iostream>
#include <ctime>
int sum_it_up(int count, int steps)
{
    auto c = 0;
    for (int i = 0; i < count; i += steps)
    {
        if (rand() % 2)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(2));
        }

        ++c;
    }
    return c;
}

int main()
{
    srand(time(0));
    std::deque<std::future<int>> deque;
    for (int i = 0; i < 100; ++i)
    {
        deque.push_back(std::async(std::launch::async, []() { return sum_it_up(10000, 1); }));
    }

    for (std::future<int> &f : deque)
    {
        auto x = f.get();
        std::cout << "Nach hochzählen: " << x << std::endl;
    }

    return 0;
}