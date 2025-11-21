#include <string>

#ifndef _HASH_HPP_
#define _HASH_HPP_

std::string pw_hash(std::string in, std::string salt);
std::string gen_salt(int len);

#endif
