#include <string>
#include "../user/user.hpp"

#ifndef _SHOP_UTILS_HPP_
#define _SHOP_UTILS_HPP_

int num_input(std::string prompt, int lower, int upper);
int get_db_user_len();
void load_db_from_file(Pelanggan *db);

#endif
