#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include <string>

class Warrior {
    public:
        virtual void attack(Warrior *enemy) const = 0;
        void be_attacked(int damage);
        bool is_alive(); 
        int strength;
        int lifepoints;
        virtual ~Warrior();
        std::string get_name() const;

    protected: 
        std::string name;
};

#endif