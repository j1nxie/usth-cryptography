#include "../rsa.h"
#include <cassert>
#include <fmt/core.h>

int main() {
    uint64_t e = RSA::calculate_base(3, 11, 7);

    RSA::PublicKey public_key = RSA::generate_public_key(e, 3, 11);
    RSA::PrivateKey private_key = RSA::generate_private_key(e, 3, 11);

    fmt::print("Public key: n = {}, e = {}\n", public_key.n, public_key.e);
    fmt::print("Private key: n = {}, d = {}\n", private_key.n, private_key.d);

    uint64_t cipher = RSA::encrypt(5, public_key);
    fmt::print("Cipher text: {}\n", cipher);

    assert(e == 3);
    assert(cipher == 26);
}
