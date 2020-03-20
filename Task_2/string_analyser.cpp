#include "string_analyzer.h"

string_analyser::string_analyser(std::string &data) : data(data) {}

void string_analyser::add_delimiter(char symbol) { delimiters.insert(symbol); }

void string_analyser::delete_all_delimiters() { delimiters.clear(); }

void string_analyser::delete_delimiter(char symbol) { delimiters.erase(symbol); }

void string_analyser::skip() {
    int i = 0;
    for (; i < data.length(); ++i)
        if (!delimiters.count(data[i]))
            break;
    data = data.erase(0, i);
}

bool string_analyser::get_next_token(std::string &token) {
    bool success = false;
    skip();
    if (data.length()) {
        int i = 0;
        for (; i < data.length(); ++i)
            if (delimiters.count(data[i]))
                break;
        token = std::string(data.substr(0, i));
        data = data.erase(0, i);
        success = true;
    }
    return success;
}

std::string const &string_analyser::get_current_state() const { return data; }

std::set<char> const &string_analyser::get_delimiters() const { return delimiters; }
