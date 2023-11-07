#include "modular_exponentiation.h"

namespace ModularExponentiation {
    uint64_t modular_exponentiation(uint64_t base, uint64_t exponent,
                                    uint64_t modulus) {
        if (exponent == 0) {
            return 1;
        }

        if (exponent == 1) {
            return base % modulus;
        }

        uint64_t result = modular_exponentiation(base, exponent / 2, modulus);

        if (exponent % 2 == 0) {
            return (result * result) % modulus;
        }

        return (((result * result) % modulus) * base) % modulus;
    }
} // namespace ModularExponentiation