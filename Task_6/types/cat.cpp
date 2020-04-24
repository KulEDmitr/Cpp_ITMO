#include "cat.h"

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
