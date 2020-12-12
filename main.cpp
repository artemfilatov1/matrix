#include <iostream>
#include "mtr.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Matrix<int> M(7, 2);
    M.fillMatrixRnd(0, 10);
    M.show();
    M.clear();
    cout << endl;
    M.show();
    return 0;
}
