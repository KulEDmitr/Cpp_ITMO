#pragma once

#include <string>

class cat {
    std::string name;
    bool small;

public:
    explicit cat(std::string name = "Mursik", bool small = true) : name(std::move(name)), small(small) {};
    cat(const cat &other) = default;
    ~cat() = default;
    cat &operator=(const cat &) = default;

    bool isSmall() const{
        return small;
    }

    friend std::ostream &operator<<(std::ostream &, cat const &);
    friend std::istream &operator>>(std::istream &, cat &);

};
