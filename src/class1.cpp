#include <iostream>

class Line {
public:
    Line(int len = 0);
    Line(const Line &obj);
    ~Line();

    void getlength() { std::cout << "Its length is " << *len_ptr << std::endl; }

    Line operator+(const Line &line) {
        Line new_line;
        *new_line.len_ptr = *this->len_ptr + *line.len_ptr;
        return new_line;
    }

    Line& operator=(Line &&line) {
        if (this == &line) {
            return *this;
        }
        delete len_ptr;
        len_ptr = line.len_ptr;
        line.len_ptr = nullptr;
        (*len_ptr) ++;
        // Just to show that the length of line4 is different from line3 after move.
        return *this;
    }

private:
    int *len_ptr;
};

Line::Line(int len) {
    std::cout << "Line is being created, its length is " << len << std::endl;
    len_ptr = new int;
    *len_ptr = len;
}

Line::Line(const Line &obj) {
    std::cout << "Line is being created through a different way." << std::endl;
    len_ptr = new int;
    *len_ptr = *obj.len_ptr;
}

Line::~Line() {
    std::cout << "Line is being deleted." << std::endl;
    delete len_ptr;
}

int main(int argc, char *argv[]) {
    Line line1(10);
    Line line2(line1);
    Line line3 = line1 + line2;
    Line line4(0);
    line4 = std::move(line3);
    //line3.getlength(); This causes core dump because line3's len_ptr is nullptr after move.
    line4.getlength();
    return 0;
}
