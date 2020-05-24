#include "triangle.hpp"
#include <iostream>
#include <cmath>

using namespace std;

triangle::triangle(const point &a_in, const point &b_in, const point &c_in) {
    a = a_in;
    b = b_in;
    c = c_in;
}

double triangle::perimeter() const {
    double ab = a.get_distance_point(b.get_x(), b.get_y());
    double bc = b.get_distance_point(c.get_x(), c.get_y());
    double ac = a.get_distance_point(c.get_x(), c.get_y());

    return ab + bc + ac;
}

void triangle::translate(const point &vector_in) {
    a.set_x(a.get_x() + vector_in.get_x());
    a.set_y(a.get_y() + vector_in.get_y());
    b.set_x(b.get_x() + vector_in.get_x());
    b.set_y(b.get_y() + vector_in.get_y());
    c.set_x(c.get_x() + vector_in.get_x());
    c.set_y(c.get_y() + vector_in.get_y());
}

void triangle::display() const {
    cout << "(" << a.get_x() << ", " << a.get_y() << ")";
    cout << "(" << b.get_x() << ", " << b.get_y() << ")";
    cout << "(" << c.get_x() << ", " << c.get_y() << ")";
    cout << endl;
}

void triangle::Draw() {
    cout << "<line x1=\"" << a.get_x() << "\" x2=\"" << b.get_x() << "\" y1=\"" << a.get_y() <<"\" y2=\"" << b.get_y() << "\"/>" << endl;
    cout << "<line x1=\"" << b.get_x() << "\" x2=\"" << c.get_x() << "\" y1=\"" << b.get_y() <<"\" y2=\"" << c.get_y() << "\"/>" << endl;
    cout << "<line x1=\"" << c.get_x() << "\" x2=\"" << a.get_x() << "\" y1=\"" << c.get_y() <<"\" y2=\"" << a.get_y() << "\"/>" << endl;
}