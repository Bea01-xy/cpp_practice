#include <iostream>

void show_func(int argc, char*argv[])
{
    std::cout << "argc = " << argc << std::endl;
    /*show the args*/
    for (size_t i = 0; i < argc; i++) {
        std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
    }
}
void ref_change_value(int &a)
{
    a = 1;
}
template<typename T>
void swap(T& a, T& b)
{
    a^=b; //a=69^420
    b^=a; //b=69^420^420=69
    a^=b; //a=69^420^69 =420
}
int main (int argc, char *argv[]) {
    show_func(argc, argv);    
    char name[20];
    int a = 69;
    int b = 420;
    swap(a,b);
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    //ref_change_value(a);
    //std::cout << "a = " << a << std::endl;
    
    std::cout << "state your name: ";
    std::cin >> name;
    std::cout << "so your name is " << name << std::endl;
    return 0;
}
