#include <iostream>
#include <functional>

class robot
{
public:
    robot(void)
    {
        std::cout << "here i create a robot object." << std::endl;
    }
    void greet(const std::string& name)
    {
        std::cout << "hello, " << name << std::endl;
    }
};

void minus(int a, int b)
{
    std::cout << a << " - " << b << " = " << (a-b) << std::endl;
}

int main (int argc, char *argv[]) {
    using namespace std::placeholders;

    auto reversed_minus = std::bind(minus, _2, _1);

    std::cout << "here's the minus function:" << std::endl;
    minus(1,2);
    std::cout << "here's the reversed_minus function:" << std::endl;
    reversed_minus(1,2);

    auto reversed_minus_lambda = [](int a, int b){minus(b,a);};
    std::cout << "here's the reversed_minus_lambda function:" << std::endl;
    reversed_minus_lambda(1,2);

    robot robot;
    auto greet = std::bind(&robot::greet, &robot, _1);
    greet("Danny");
    return 0;
}
