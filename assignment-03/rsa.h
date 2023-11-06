#include <cinttypes>

#ifndef RSA_
#define RSA_

namespace RSA {
    typedef struct {
        uint64_t n;
        uint64_t e;
    } PublicKey;

    typedef struct {
        uint64_t n;
        uint64_t d;
    } PrivateKey;

    PrivateKey generate_private_key(uint64_t e, uint64_t p, uint64_t q);
    PublicKey generate_public_key(uint64_t e, uint64_t p, uint64_t q);
    uint64_t encrypt(uint64_t message, PublicKey public_key);
    uint64_t decrypt(uint64_t message, PrivateKey private_key);
    uint64_t calculate_base(uint64_t p, uint64_t q, uint64_t d);
} // namespace RSA

#endif