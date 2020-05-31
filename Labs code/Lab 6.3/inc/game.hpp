#ifndef GAME_HPP
#define GAME_HPP

#include "warrior.hpp"
#include <vector>

class Game {
    public: 
        void run();
        void add_good_warrior(Warrior *w); 
        void add_bad_warrior(Warrior *w);

    private:
        std::vector<Warrior*> good_warriors;
        std::vector<Warrior*> bad_warriors;
};

#endif