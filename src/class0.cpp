#include <iostream>

class Box {
public:
    Box(double h, double l, double w) {
        std::cout << "Box is being created." << std::endl;
        this->height = h;
        this->length = l;
        this->width  = w;
    }
    ~Box(void) { std::cout << "Box is being deleted." << std::endl; }
    double getVolume(void) { return this->height * this->length * this->width; }
    
private:
    double height;
    double length;
    double width;
};

int main(int argc, char *argv[]) {
    Box box0(2.1, 2.5, 3.0);
    std::cout << "box0's volume is " << box0.getVolume() << std::endl;
    return 0;
}
