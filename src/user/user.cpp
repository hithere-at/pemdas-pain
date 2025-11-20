#include <iostream>
#include "../utils/utils.hpp"

class User {

    protected:
        std::string user_id;
        std::string password;
        int balance;

    public:
        std::string nama;
        std::string ttl;
        std::string status;

        User () { this->balance = -1; } // -1 menandakan pelanggan baru

        User (std::string nama, std::string ttd, std::string status) {
            this->nama = nama;
            this->ttl = ttd;
            this->status = status;
            this->balance = 0;

        }

        User (std::string nama, std::string ttd, std::string status, std::string user_id, std::string password, int balance) {
            this->nama = nama;
            this->ttl = ttl;
            this->status = status;
            this->user_id = user_id;
            this->password = password;
            this->balance = balance;

        }

};
