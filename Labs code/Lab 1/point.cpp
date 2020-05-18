#include "point.hpp"
#include <iostream>
#include <cmath>

using namespace std;

// point::point() {
//     x = 0;
//     y = 0;
// }

point::point(const double &x_in, const double &y_in) {
    x = x_in;
    y = y_in;
}

void point::display() const {
    cout << "(" << x << ", " << y << ")" << endl;
}

void point::set_x(const double &x_in) {
    x = x_in;
}

void point::set_y(const double &y_in) {
    y = y_in;
}

double point::get_x() const {
    return x; 
}

double point::get_y() const {
    return y;
}

void point::translate(const point& p_in) {
    x = x + p_in.x;
    y = y + p_in.y;
}

double point::get_distance_org() const {

    double distance = sqrt((pow (x, 2)) + (pow (y, 2)));

    return distance;
}

double point::get_distance_point(const double &x_ref, const double &y_ref) const {

    double distance = sqrt((pow(x - x_ref, 2)) + (pow(y - y_ref, 2)));

    return distance;
}

ostream& operator<<(ostream &os, const point &p) {
    os << p.x << ", " << p.y << endl;
    return os;
}

//destructor 
point::~point() {
    cout << "Destroying point " << *this;
}