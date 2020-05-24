#include "warrior.hpp"
#include <string>

using namespace std;

Warrior::~Warrior() {}

string Warrior::get_name() const {
    return this->name;
}

void Warrior::be_attacked(int damage) {
    this->lifepoints = this->lifepoints - damage;
}
        
bool Warrior::is_alive() {
    if (this->lifepoints < 1) {
        return false;
    } else {
        return true;
    }
}