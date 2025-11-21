#include <cstdint>
#include <ctime>
#include <iostream>
//#include "hash.hpp"

std::string pw_hash(std::string in, std::string salt) {

    int pw_salt_len = in.size() * 2;
    char pw_salt[pw_salt_len];
    int salt_idx = 0;

    for (int i = 0; i < in.size(); i++) {
        pw_salt[(i*2)] = in[i];
        pw_salt[(i*2)+1] = salt[salt_idx];
        salt_idx++;

        if (salt_idx == salt.size()) { salt_idx = 0; }

    }

   uint32_t stuff = 0xDEADBEEF;

    for (int i = 0; i < pw_salt_len; i++) {
        stuff ^= (pw_salt[i] >> 7);
        stuff ^= 0xadef8593;
        stuff *= 0x34fe9b09;
        stuff ^= (pw_salt[i] << 13);
        stuff = (stuff << 8) | (stuff >> 24);
        stuff ^= pw_salt[i];

    }

    char hash[9];
    snprintf(hash, 9, "%08x", stuff);
    std::string actualHash = hash;
    return actualHash;

}

std::string gen_salt(int len) {

    std::string chars = "ABCDEFGIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::string buf = "";
    std::srand(std::time(nullptr));

    for (int i = 0; i < len; i++) {
        buf += chars[(rand() % 62)];

    }

    return buf;

}

int main() {

    std::string salt;
    std::string hash;
    std::string password;
    std::string user_id;

    for (int i = 0; i < 6; i++) {

        std::cout << "id: ";
        std::cin >> user_id;

        std::cout << "passwd: ";
        std::cin >> password;

        salt = gen_salt(8);
        hash = pw_hash(user_id + password, salt);

        std::cout << std::endl << std::endl << "Hash: " << hash << std::endl;
        std::cout << "Salt: " << salt << std::endl << std::endl;

    }

}
