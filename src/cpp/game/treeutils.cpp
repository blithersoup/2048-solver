#include "moves.hpp"
#include "moveutils.hpp"
#include "minimax.hpp"
#include <iostream>

int main() {
    int x[16] { 2, 2, 0, 0, 0, 4, 0, 16, 0, 0, 0, 0, 2, 2, 0, 0 };
    int *z = minimax_result(x);
    
    for (int u = 0; u < 16; u++) {
        std::cout << z[u] << " ";
    }
}