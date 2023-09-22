#include <iostream>

using namespace std;
int main()
{
    int a;
    std::cin >> a;
    std::cout << (abs(a + 1) - abs(a)) * ((abs(a) + 1) * (abs(a) / 2) + (abs(a) / 2 + 1) * (abs(a) % 2)) + (0.5 - (float(abs(a + 1) - abs(a)) / 2));
    return 0;
}