#include <iostream>

int main(int argc, char* argv[])
{
    long long int a = 0;
    std::cin >> a;
    int b = (a / 10) * (a / 10 + 1) * 10 + 2;
    std::cout << b << "5" << std::endl;

    return EXIT_SUCCESS;
}