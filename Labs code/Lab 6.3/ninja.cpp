#include "ninja.hpp"
#include <string>
#include <iostream>

using namespace std;

Ninja::~Ninja() {}

Ninja::Ninja(string name, int strength) {
    this->name = name;
    this->strength = strength;
    this->lifepoints = 100;
}

void Ninja::attack(Warrior *enemy) const {
    cout << "Ninja " << this->name << " attacks" << endl << endl;
    enemy->be_attacked(this->strength);
}