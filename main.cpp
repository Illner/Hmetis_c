#include <vector>
#include <cstddef>
#include <iostream>

extern "C" void HMETIS_PartRecursive(int, int, int*, int*, int*, int*, int, int, int*, int*, int*);

int main(int argc, char *argv[])
{
    int k = 2;
    int c = 12;
    int n = 11;
    int ub = 5;

    int cut;
    std::vector<int> options(9, 0);
    std::vector<int> partvec(c, 0);
    std::vector<int> xpins = {0, 5, 7, 11, 13, 15, 19, 21, 25, 27, 29, 31};
    std::vector<int> pins = {2, 3, 5, 6, 9,
                             0, 1,
                             0, 1, 2, 3,
                             1, 3,
                             4, 5,
                             4, 5, 6, 7,
                             6, 7,
                             8, 9, 10, 11,
                             8, 11,
                             8, 10,
                             2, 5};

    HMETIS_PartRecursive(c, n, NULL, xpins.data(), pins.data(), NULL, k, ub, options.data(), partvec.data(), &cut);

    std::cout << "cut: " << cut << std::endl;

    std::cout << "partvec: ";
    for (int i : partvec)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
