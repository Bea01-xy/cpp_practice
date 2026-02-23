#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>
#include <chrono>

using namespace std::chrono_literals;

class PrintHelloPer500ms
{
public:
    void operator()(std::string name)
    {
        for (size_t i = 0; i < 5; i++) {
            std::cout << "Hello, " << name << std::endl;
            std::this_thread::sleep_for(500ms);
        }
    }
};

class PrintHelloPer300ms
{
public:
    void operator()(std::string name)
    {
        for (size_t i = 0; i < 5; i++) {
            std::cout << "Hello, " << name << std::endl;
            std::this_thread::sleep_for(300ms);
        }
    }
};

void PrintHelloPerSecond(std::string name)
{
    for (size_t i = 0; i < 3; i++) {
        std::cout << "Hello, " << name << std::endl;
        std::this_thread::sleep_for(1s);
    }
}

int main (int argc, char *argv[]) {
    std::thread t1(PrintHelloPer500ms(), "Bea");
    std::thread t2(PrintHelloPer300ms(), "Lamino");
    std::thread t3(PrintHelloPerSecond, "Suisei");
    std::cout << "This is from main function." << std::endl;
    t1.join();
    t2.join();
    t3.join();
    return 0;
}
