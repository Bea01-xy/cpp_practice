#include <iostream>
using namespace std;

int main (int argc, char *argv[]) {
    cout << "__LINE__: " << __LINE__ << endl;   
    cout << "__FILE__: " << __FILE__ << endl;   
    cout << "__DATE__: " << __DATE__ << endl;   
    cout << "__TIME__: " << __TIME__ << endl;   
    return 0;
}

//output:
//__LINE__: 5
//__FILE__: src/macro.cpp
//__DATE__: Feb 16 2026
//__TIME__: 21:42:37
