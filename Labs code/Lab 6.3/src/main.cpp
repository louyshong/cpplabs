#include "game.hpp"
#include "warrior.hpp"
#include "ninja.hpp"
#include "samurai.hpp"

int main() {
    Warrior *gw1 = new Ninja("Naruto", 35);
    Warrior *gw2 = new Ninja("Sasuke", 35);
    Warrior *gw3 = new Ninja("Sakura", 20);
    Warrior *gw4 = new Ninja("Kakashi", 30);
    Warrior *gw5 = new Ninja("Konohamaru", 5);

    Samurai *bw1 = new Samurai("Madara", 50);
    Samurai *bw2 = new Samurai("Orochimaru", 25);
    Samurai *bw3 = new Samurai("Zabuza", 25);
    Samurai *bw4 = new Samurai("Kakuzu", 30);

    Game game;

    game.add_good_warrior(gw1);
    game.add_good_warrior(gw2);
    game.add_good_warrior(gw3);
    game.add_good_warrior(gw4);
    game.add_good_warrior(gw5);

    game.add_bad_warrior(bw1);
    game.add_bad_warrior(bw2);
    game.add_bad_warrior(bw3);
    game.add_bad_warrior(bw4);

    game.run();
}