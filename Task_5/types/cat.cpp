#include "cat.h"

bool cat::operator==(const cat &other) const {
    return this->name == other.name;
}

bool cat::operator!=(const cat &other) const {
    return !(this->name == other.name);
}

bool cat::operator<(const cat &other) const {
    return this->name < other.name;
}

std::ostream &operator<<(std::ostream &s, cat const &cur) {
    s << cur.name;
    return s;
}

std::istream &operator>>(std::istream &s, cat &cur) {
    std::string name;
    s >> name;
    cur = cat(name);
    return s;
}
