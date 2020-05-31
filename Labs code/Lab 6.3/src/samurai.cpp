#include "samurai.hpp"
#include <string>
#include <iostream>

using namespace std;

Samurai::~Samurai() {}

Samurai::Samurai(string name, int strength) {
    this->name = name;
    this->strength = strength;
    this->lifepoints = 100;
}

void Samurai::attack(Warrior *enemy) const {
    cout << "Samurai " << this->name << " attacks" << endl << endl;
    enemy->be_attacked(this->strength);
}