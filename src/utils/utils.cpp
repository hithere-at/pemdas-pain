#include <fstream>
#include "utils.hpp"

int num_input(std::string prompt, int lower, int upper) {

    int input;

    while (true) {

        std::cout << prompt;
        std::cin >> input;

        if (input < lower || input > upper || std::cin.fail()) {
            std:cerr << "Input tidak valid. Mohon mengulangi" << endl << endl;
            continue;

        }

        break;

    }

    return input;

}

int get_db_user_len() {

    fstream db_file("db.csv", std::ios::in);
    std::string line_buf;
    int count = 0;

    if (db_file.is_open()) {

        while (getline(db_file, line_buf)) {
            count++;

        }

    return count;

}

void load_db_from_file(Pelanggan *db) {

    fstream db_file("db.csv", std::ios::in);
    std::string line_buf;
    std::string user_len = 0;

    if (db_file.is_open()) {

        while (getline(db_file, line_buf)) {
            std::string::size_type found_idx = 0;
            std::string::size_type line_buf_len  = line_buf.size();
            std::string prop[6];
            int count = 0;

            while (found_idx <= line_buf_len) {
                std::string::size_type old_pos = found_idx;
                found_idx = line_buf.find(",", old_pos);

                if (found_idx != std::string::npos) {

                    if (count == 0) {
                        std::string field = line_buf.substr(0, found_idx);

                    } else {
                        std::string field = line_buf.substr(old_pos+1, found_idx);

                    }

                } else {
                    std::string field = line_buf.substr(old_pos, line_buf_len);
                    found_idx = line_buf_len;

                }

                found_idx += 1;
                prop[count] = field;
                count += 1;

            }

            db[user_len] = Pelanggan(prop[0], prop[1], prop[2], prop[3], prop[4], std::stoi(prop[5]));
            user_len++;

        }

    }

    db_file.close()

}

