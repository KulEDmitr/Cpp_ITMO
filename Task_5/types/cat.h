#pragma once

#include <string>
#include "../templates/queue.h"

class cat {
    std::string name;

public:
    explicit cat(std::string name = "Mursik") : name(std::move(name)) {};
    cat(const cat& other) = default;
    ~cat() = default;

    cat &operator=(const cat &) = default;

    bool operator==(const cat &) const;
    bool operator!=(const cat &) const;
    bool operator<(const cat &) const;

    friend std::ostream &operator<<(std::ostream &, cat const &);
    friend std::istream &operator>>(std::istream &, cat &);

};
