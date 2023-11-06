#include "../rsa.h"
#include <cassert>
#include <iostream>

int main() {
    RSA::PrivateKey private_key = RSA::generate_private_key(17, 61, 53);
    RSA::PublicKey public_key = RSA::generate_public_key(17, 61, 53);

    assert(private_key.n == 3233);
    assert(private_key.d == 413);
    assert(public_key.e == 17);
}