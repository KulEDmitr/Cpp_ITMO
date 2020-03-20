#include "menu.h"

void menu::write_message(const std::string &message) {
    out << message << std::endl;
}

menu::menu() : finish(false), out(std::cout), in(std::cin) {
    write_message("Hello, You use a simple strings analyser. "
                  "It can help You with taking tokens from string with some delimiters");
}

void menu::help() {
    write_message("If you want to see that message again - enter '0'\n"
                  "If You want to add new string for analysing - enter '1'\n"
                  "If you want to add one delimiter for the string - enter '2'\n"
                  "If you want to delete ONE delimiter for the string - enter '3'\n"
                  "If you want to delete ALL delimiters for the string - enter '4'\n"
                  "If you want to check current string and delimiters state - enter '5'\n"
                  "If you want to take next token of the string - enter '6'\n"
                  "If you want to finish work with current string or "
                  "want to create new analyser - enter '13' to return to start page\n"
    );
}

bool menu::take_command(std::string &result) {
    help();
    int command;
    in >> command;
    switch (command) {
        case CREATE:
            list.push_back(create_new_analyser());
            break;
        case ADD_ONE:
            add_delimiter(get_tool());
            out << std::endl;
            break;
        case DELETE_ONE:
            delete_delimiter(get_tool());
            out << std::endl;
            break;
        case DELETE_ALL:
            delete_all_delimiters(get_tool());
            out << std::endl;
            break;
        case CHECK_STATE:
            check_current_state(get_tool());
            out << std::endl;
            break;
        case GET_NEXT_TOKEN:
            get_next_token(get_tool(), result);
            out << std::endl;
            renew_list();
            break;
        case FINISH:
            finish = true;
            break;
        case HELP:
            help();
            break;
        default:
            write_message("\nYou entered an invalid command, please, "
                          "read the information carefully\n");
            help();
            break;
    }
    return finish;
}

void menu::add_delimiter(string_analyser &tool) {
    char symbol;
    write_message("please, enter, which delimiter do you want to add "
                  "(it must be character)");
    in >> symbol;
    tool.add_delimiter(symbol);
}

void menu::delete_delimiter(string_analyser &tool) {
    char symbol;
    write_message("please, enter, which delimiter do you want to delete from list "
                  "(it must be character)");
    in >> symbol;
    tool.delete_delimiter(symbol);
}

void menu::delete_all_delimiters(string_analyser &tool) {
    write_message("Are You sure? This action delete all list of delimiters (YES / NO)");
    std::string sure;
    in >> sure;
    if (sure == "YES") {
        tool.delete_all_delimiters();
    }
}

void menu::check_current_state(string_analyser &tool) {
    write_message("for that analyser you have string and delimiters:");
    out << "String:   " << tool.get_current_state() << std::endl << "Delimiters for that string:   ";
    for (char symbol : tool.get_delimiters()) {
        out << symbol << " ";
    }
}

void menu::get_next_token(string_analyser &tool, std::string &result) {
    bool res = tool.get_next_token(result);
    write_message((res) ?
                  "split finish successfully: '" + result + "'" :
                  "string is end only with delimiters");

}

string_analyser menu::create_new_analyser() {
    write_message("If you don't want to create standart analyser with phrase "
                  "'aba ca ba a baca bad a ba', enter name of string bellow, "
                  "in the other case enter '0'");
    std::string data;
    getline(in, data);
    getline(in, data);
    if (data == "0") data = "aba ca ba a baca bad a ba";
    return string_analyser(data);
}

void menu::renew_list() {
    for (auto it = list.begin(); it < list.end(); ++it) {
        if (it.base()->get_current_state().empty()) {
            list.erase(it);
        }
    }
}

string_analyser &menu::get_tool() {
    write_message("enter analyser's number at list:");
    get_list_info();
    int number;
    in >> number;
    return list[number];
}

void menu::get_list_info() {
    int i = 0;
    for (auto it = list.begin(); it < list.end(); ++it) {
        std::cout << "\nnumber: " << i++ << std::endl;
        check_current_state(*it.base());
        std::cout << std::endl;
    }
}
