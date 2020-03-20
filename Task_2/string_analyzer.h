#pragma once

#include <string>
#include <set>

class string_analyser {
    std::string data;
    std::set<char> delimiters;

    void skip();

public:
    string_analyser() = default;
    explicit string_analyser(std::string&);

    std::set<char> const& get_delimiters() const;
    std::string const& get_current_state() const;

    void add_delimiter(char);
    void delete_all_delimiters();
    void delete_delimiter(char);
    bool get_next_token(std::string&);
};
