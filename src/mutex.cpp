#include <iostream>
#include <mutex>
#include <thread>

int counter;
std::mutex mutex;

void increase(void)
{
    for (size_t i = 0; i < 100000; i++) {
        std::lock_guard<std::mutex> lock(mutex);
        counter++;
    }
}

int main (int argc, char *argv[]) {
    std::thread t1(increase);
    std::thread t2(increase);

    t1.join();
    t2.join();

    std::cout << "The final counter is " << counter << std::endl;
    return 0;
}
