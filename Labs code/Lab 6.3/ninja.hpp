#ifndef NINJA_HPP
#define NINJA_HPP

#include "warrior.hpp"
#include <string>

class Ninja : public Warrior {
    public: 
        Ninja(std::string name, int strength);
        void attack(Warrior *enemy) const;
        ~Ninja();
};

#endif