#include <iostream>

class Animal {
public:
    Animal(void)
    {
        std::cout << "Animal is created." << std::endl;
    }
    ~Animal(void)
    {
        std::cout << "Animal is deleted." << std::endl;
    }
    virtual void speak(void)
    {
        std::cout << "This animal is speaking." << std::endl;
    }
};

class Dog : public Animal {
public:
    void speak(void) override 
    {
        std::cout << "This dog is barking." << std::endl;
    }
};
class Cat : public Animal {
public:
    void speak(void) override 
    {
        std::cout << "This cat is meowing." << std::endl;
    }
};



int main (int argc, char *argv[]) {
    auto dog_ptr = new Dog;
    auto cat_ptr = new Cat;
    dog_ptr->speak();
    cat_ptr->speak();
    delete dog_ptr;
    delete cat_ptr;
    return 0;
}
