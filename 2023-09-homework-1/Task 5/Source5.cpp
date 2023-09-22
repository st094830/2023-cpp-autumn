#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    int v, t, n;
    std::ifstream fin("INPUT.TXT");
    std::ofstream fout("OUTPUT.TXT");
    fin >> v;
    fin >> t;

    n = (109 + v * t) % 109 + 1;

    fout << n;
    fin.close();
    fout.close();
    return 0;
}