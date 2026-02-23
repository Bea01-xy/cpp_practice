#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    auto now = time(nullptr);
    cout << "ctime = " << ctime(&now) << endl;    
    cout << "time = " << now << endl;    

    auto tm_t = localtime(&now);
    cout << "tm_t->tm_year = " << tm_t->tm_year << endl;
    return 0;
}
