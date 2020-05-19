#include "labeled_point.hpp"
#include <cmath>

using namespace std; 

labeled_point::labeled_point() {
    this->x = 0;
    this->y = 0;
    this->label = "Default";
}

labeled_point::labeled_point(const string& label) {
    this->label = label;
}

labeled_point::labeled_point(const double &x, const double &y ,const string &label) {
    this->x = x;
    this->y = y;
    this->label = label;
}

double labeled_point::get_x() const {
    return this->x;
}

double labeled_point::get_y() const {
    return this->y;
}

string labeled_point::get_label() const {
    return this->label;
}

void labeled_point::set_x(const double &x) {
    this->x = x;
}

void labeled_point::set_y(const double &y) {
    this->y = y;
}

void labeled_point::set_label(const string &label) {
    this->label = label;
}

double labeled_point::distance_to(const point &ref) const {
    double distance = sqrt((pow(this->x - ref.get_x(), 2)) + (pow(this->y - ref.get_y(), 2)));

    return distance;
}

double labeled_point::distance_to(const labeled_point &ref) const {
    double distance = sqrt((pow(this->x - ref.x, 2)) + (pow(this->y - ref.y, 2)));

    return distance;
}

bool operator<(const labeled_point &p1, const labeled_point &p2) {
    double distance1 = sqrt((pow (p1.x, 2)) + (pow (p1.y, 2)));
    double distance2 = sqrt((pow (p2.x, 2)) + (pow (p2.y, 2)));

    if (distance1 < distance2) {
        return true;
    } else {
        return false;
    }
}

bool operator==(const labeled_point &p1, const labeled_point &p2) {
    if (p1.x == p2.x && p1.y == p2.y) {
        return true;
    } else {
        return false;
    }
}

std::ostream& operator<<(std::ostream& os, const labeled_point& p) {
    os << p.label << ": (" << p.x << ", " << p.y << ")" << endl;
    return os;
}