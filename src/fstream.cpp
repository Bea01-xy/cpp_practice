#include <fstream>
#include <iostream>

int main() {
    std::ofstream outFile("test.txt", std::ios::app);
    if (outFile.is_open()) {
        // outFile << "Hello World!" << std::endl;
        outFile.close();
        std::cout << "done writing the file." << std::endl;
    } else {
        std::cerr << "failed to open the file." << std::endl;
    }

    std::ifstream inFile("test.txt");
    if (inFile.is_open()) {
        int num;
        inFile >> num;
        std::cout << "num = " << num << std::endl;
        inFile >> num;
        std::cout << "num = " << num << std::endl;
        // std::string line;
        // while(std::getline(inFile, line))
        //{
        // std::cout << "content read: " << line << std::endl;
        //}
        // inFile.close();
        // std::cout << "done reading the file." << std::endl;
    } else {
        std::cerr << "failed to open the file." << std::endl;
    }

  return 0;
}
