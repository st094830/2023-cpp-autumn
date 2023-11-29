#include <iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    std::cin >> a;
    int b = (abs(a + 1) - abs(a)) * ((abs(a) + 1) * (abs(a) / 2) + (abs(a) / 2 + 1) * (abs(a) % 2)) + (0.5 - (float(abs(a + 1) - abs(a)) / 2));
    std::cout << b << std::endl;

    return EXIT_SUCCESS;
}