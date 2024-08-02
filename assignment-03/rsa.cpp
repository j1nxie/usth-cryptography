#include "rsa.h"
#include "../assignment-02/modular_exponentiation.h"
#include <cmath>

namespace RSA {
    bool is_prime(uint64_t n) {
        if (n == 2 || n == 3) {
            return true;
        }

        if (n <= 1 || n % 2 == 0 || n % 3 == 0) {
            return false;
        }

        for (uint64_t i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }

        return true;
    }

    uint64_t gcd(uint64_t a, uint64_t b, uint64_t &x, uint64_t &y) {
        x = 1;
        y = 0;

        if (b == 0) {
            return a;
        }

        uint64_t new_x = 0;
        uint64_t new_y = 1;
        uint64_t new_r = b;
        uint64_t r = a;
        uint64_t quotient, tmp;

        while (new_r) {
            quotient = r / new_r;

            tmp = r;
            r = new_r;
            new_r = tmp - quotient * new_r;

            tmp = x;
            x = new_x;
            new_x = tmp - quotient * new_x;

            tmp = y;
            y = new_y;
            new_y = tmp - quotient * new_y;
        }

        return r;
    }

    uint64_t modular_inverse(uint64_t a, uint64_t n) {
        uint64_t x, y;
        uint64_t r = gcd(a, n, x, y);
        if (r > 1) {
            return -1;
        }

        return x > 1e19 ? x + n : x;
    }

    uint64_t lcm(uint64_t a, uint64_t b) {
        uint64_t x, y;

        if (a == 0 && b == 0) {
            return 0;
        }

        return (a * b / gcd(a, b, x, y));
    }

    PrivateKey generate_private_key(uint64_t e, uint64_t p, uint64_t q) {
        uint64_t lambda = lcm(p - 1, q - 1);
        uint64_t d = modular_inverse(e, lambda);

        return PrivateKey{p * q, d};
    }

    PublicKey generate_public_key(uint64_t e, uint64_t p, uint64_t q) {
        return PublicKey{p * q, e};
    }

    uint64_t encrypt(uint64_t message, PublicKey public_key) {
        return ModularExponentiation::modular_exponentiation(
            message, public_key.e, public_key.n);
    }

    uint64_t decrypt(uint64_t message, PrivateKey private_key) {
        return ModularExponentiation::modular_exponentiation(
            message, private_key.d, private_key.n);
    }

    uint64_t calculate_base(uint64_t p, uint64_t q, uint64_t d) {
        return modular_inverse(d, lcm(p - 1, q - 1));
    }
} // namespace RSA
