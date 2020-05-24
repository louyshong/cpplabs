#ifndef SAMURAI_HPP
#define SAMURAI_HPP

#include "warrior.hpp"
#include <string>

class Samurai : public Warrior {
    public: 
        Samurai(std::string name, int strength);
        void attack(Warrior *enemy) const;
        ~Samurai();
};

#endif