#include <string>
#include "../user/user.hpp"

#ifndef SHOP_UTILS_HPP
#define SHOP_UTILS_HPP

int num_input(std::string prompt, int lower, int upper);
int get_db_user_len();
void load_db_from_file(Pelanggan *db);

#endif
