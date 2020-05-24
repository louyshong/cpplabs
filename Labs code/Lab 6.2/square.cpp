#include "square.hpp"

using namespace std;

void square::Draw() {
    cout << "<line x1=\"" << a.get_x() << "\" x2=\"" << b.get_x() << "\" y1=\"" << a.get_y() <<"\" y2=\"" << b.get_y() << "\"/>" << endl;
    cout << "<line x1=\"" << b.get_x() << "\" x2=\"" << c.get_x() << "\" y1=\"" << b.get_y() <<"\" y2=\"" << c.get_y() << "\"/>" << endl;
    cout << "<line x1=\"" << c.get_x() << "\" x2=\"" << d.get_x() << "\" y1=\"" << c.get_y() <<"\" y2=\"" << d.get_y() << "\"/>" << endl;
    cout << "<line x1=\"" << d.get_x() << "\" x2=\"" << a.get_x() << "\" y1=\"" << d.get_y() <<"\" y2=\"" << a.get_y() << "\"/>" << endl;
}

square::square(const point &a_in, const point &b_in, const point &c_in, const point &d_in) : a(a_in), b(b_in), c(c_in), d(d_in) {}