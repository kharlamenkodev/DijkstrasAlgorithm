#include <iostream>

using namespace std;

struct node {
    //! Name of node
    string name;
    //! Cost of node
    uint8_t cost;

    node()
    {
        name = "";
        cost = 0;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}