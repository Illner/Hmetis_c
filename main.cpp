#include <vector>
#include <iostream>

extern "C" void HMETIS_PartRecursive(int, int, int*, int*, int*, int*, int, int, int*, int*, int*);

int main(int argc, char *argv[])
{
    int k = 2;
    int c = 12;
    int n = 11;
    int ub = 5;

    std::vector<int> xpinsTmp = {0, 5, 7, 11, 13, 15, 19, 21, 25, 27, 29, 31};
    int* xpins = new int[n + 1];
    for (int i = 0; i < xpinsTmp.size(); ++i)
        xpins[i] = xpinsTmp[i];

    std::vector<int> pinsTmp = {2, 3, 5, 6, 9,
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
    int* pins = new int[pinsTmp.size()];
    for (int i = 0; i < pinsTmp.size(); ++i)
        pins[i] = pinsTmp[i];

    int cut;
    int* partvec = new int[c];

    int* options = new int[9];
    for (int i = 0; i < 9; ++i)
        options[i] = 0;

    int* cwghts = new int[c];
    for (int i = 0; i < c; ++i) cwghts[i] = 1;

    HMETIS_PartRecursive(c, n, NULL, xpins, pins, NULL, k, ub, options, partvec, &cut);

    std::cout << "cut: " << cut << std::endl;

    std::cout << "partvec: ";
    for (int i = 0; i < c; ++i)
        std::cout << partvec[i] << " ";
    std::cout << std::endl;

    delete [] xpins;
    delete [] pins;
    delete [] partvec;
    delete [] cwghts;
    delete [] options;

    return 0;
}
