#include "../rsa.h"
#include <cassert>

int main() {
    RSA::PrivateKey private_key = RSA::generate_private_key(17, 61, 53);
    RSA::PublicKey public_key = RSA::generate_public_key(17, 61, 53);

    uint64_t message = 65;
    uint64_t cipher = RSA::encrypt(message, public_key);
    uint64_t decipher = RSA::decrypt(cipher, private_key);

    assert(cipher == 2790);
    assert(decipher == message);
}