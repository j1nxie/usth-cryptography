#include "../a51.h"
#include <cassert>
#include <vector>

int main() {
    std::vector<int> x = {1, 1, 1, 1, 1, 0, 1, 0, 1, 0,
                          1, 0, 1, 0, 1, 0, 1, 0, 1};
    std::vector<int> y = {1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0,
                          0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1};
    std::vector<int> z = {1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0,
                          0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0};
    int n = 10;

    std::vector<int> result = A51::a51(n, x, y, z);
    std::vector<int> comparison = {0, 1, 0, 0, 0, 0, 0, 0, 0, 1};

    assert(result == comparison);
}