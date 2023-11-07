#include "a51.h"

namespace A51 {
    int majority(int x, int y, int z) {
        if (x + y + z > 1) {
            return 1;
        } else {
            return 0;
        }
    }

    std::vector<int> a51(int n, std::vector<int> x, std::vector<int> y,
                         std::vector<int> z) {
        if (x.size() != 19 || y.size() != 22 || z.size() != 23) {
            throw;
        }

        std::vector<int> result(n, 0);

        for (int i = 1; i < n; i++) {
            int m = majority(x[8], y[10], z[10]);

            if (m == x[8]) {
                int a = x[13] ^ x[16] ^ x[17] ^ x[18];
                for (int i = 18; i > 0; i--) {
                    x[i] = x[i - 1];
                }

                x[0] = a;
            }

            if (m == y[10]) {
                int b = y[20] ^ y[21];
                for (int i = 21; i > 0; i--) {
                    y[i] = y[i - 1];
                }

                y[0] = b;
            }

            if (m == z[10]) {
                int c = z[7] ^ z[20] ^ z[21] ^ z[22];
                for (int i = 22; i > 0; i--) {
                    z[i] = z[i - 1];
                }

                z[0] = c;
            }

            result[i] = x[18] ^ y[21] ^ z[22];
        }

        return result;
    }
} // namespace A51