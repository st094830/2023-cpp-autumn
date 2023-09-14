#include <iostream>

using namespace std;
int main()
{
    int a, b;
    std::cin >> a;
    std::cin >> b;
    std::cout << float(a + b) / 2 + float(abs(a - b)) / 2;
    return 0;
}
