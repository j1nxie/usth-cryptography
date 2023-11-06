#include "../rsa.h"
#include <cassert>
#include <fmt/core.h>

int main() {
    RSA::PublicKey public_key = RSA::generate_public_key(3, 5, 11);
    RSA::PrivateKey private_key = RSA::generate_private_key(3, 5, 11);

    fmt::print("Public key: n = {}, e = {}\n", public_key.n, public_key.e);
    fmt::print("Private key: n = {}, d = {}\n", private_key.n, private_key.d);

    fmt::print("Cipher text: {}\n", RSA::encrypt(9, public_key));
}