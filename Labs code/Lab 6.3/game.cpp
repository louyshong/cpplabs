#include "game.hpp"
#include <iostream> 
#include <cstdlib>

using namespace std;

void Game::add_good_warrior(Warrior *w) {
    this->good_warriors.push_back(w);
}

void Game::add_bad_warrior(Warrior *w) {
    this->bad_warriors.push_back(w);
}

void Game::run() {

    int round = 1;

    cout << "Battle Start !!" << endl << endl;
    
    while(bad_warriors.size() != 0 && good_warriors.size() != 0) {
        cout << "###### Round " << round << " ######" << endl;
        
        int gw = rand() % good_warriors.size();
        int bw = rand() % bad_warriors.size();

        good_warriors[gw]->attack(bad_warriors[bw]); 

        if (bad_warriors[bw]->is_alive() == true) {
            bad_warriors[bw]->attack(good_warriors[gw]); 

            if (good_warriors[gw]->is_alive() == false) {
                cout << good_warriors[gw]->get_name() << " is dead !!" << endl; 
                delete good_warriors[gw];
                good_warriors.erase(good_warriors.begin() + gw);
            }

        } else {
            cout << bad_warriors[bw]->get_name() << " is dead !!" << endl;
            delete bad_warriors[bw];
            bad_warriors.erase(bad_warriors.begin() + bw);

            if (bad_warriors.size() != 0) {
                int bw2 = rand() % bad_warriors.size();
                bad_warriors[bw2]->attack(good_warriors[gw]);

                if (good_warriors[gw]->is_alive() == false) {
                    cout << good_warriors[gw]->get_name() << " is dead !!" << endl; 
                    delete good_warriors[gw];
                    good_warriors.erase(good_warriors.begin() + gw);
                }
            }
        }

        round = round + 1;
    }

    cout << "Battle End !!" << endl << endl;
    
    if (bad_warriors.size() != 0) {
        cout << "Samurais won !!" << endl;
    } else {
        cout << "Ninjas won !!" << endl;
    }
}