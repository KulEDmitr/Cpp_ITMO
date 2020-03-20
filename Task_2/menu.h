#pragma once

#include <iostream>
#include <vector>
#include "string_analyzer.h"

//var 9
class menu {
    std::vector<string_analyser> list;
    std::ostream &out;
    std::istream &in;
    bool finish;

    enum commands {
        HELP = 0,
        CREATE = 1,
        ADD_ONE = 2,
        DELETE_ONE = 3,
        DELETE_ALL = 4,
        CHECK_STATE = 5,
        GET_NEXT_TOKEN = 6,
        FINISH = 13
    };
    void write_message(const std::string &);

public:
    menu();

    void help();
    bool take_command(std::string &);

    string_analyser create_new_analyser();
    void add_delimiter(string_analyser &);
    void delete_delimiter(string_analyser &);
    void delete_all_delimiters(string_analyser &);
    void check_current_state(string_analyser &);
    void get_next_token(string_analyser &, std::string &);
    void renew_list();
    string_analyser& get_tool();
    void get_list_info();
};
