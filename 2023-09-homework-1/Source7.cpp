#include <iostream>

using namespace std;
int main()
{
    int a;
    std::cin >> a;
    std::cout << "The next number for the number " << a << " is " << a + 1 << ".\n";
    std::cout << "The previous number for the number " << a << " is " << a - 1 << ".";
    return 0;
}