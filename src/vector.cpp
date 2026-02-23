#include <iostream>
#include <vector>

int main()
{
    std::vector<int> my_vector = {1, 2, 3, 4, 5};
    for(auto it = my_vector.begin(); it != my_vector.end(); ++it)
    {
        std::cout << *it << "  ";
    }
    
    my_vector.erase(my_vector.begin() + 2);
    my_vector.push_back(2);
    for(auto element : my_vector)
    {
        std::cout << element << "  ";
    }

    std::cout << "\nmy_vector.size() = " << my_vector.size() << std::endl;
    return 0;
}
