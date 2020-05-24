#include <iostream>
#include "triangle.hpp"
#include "point.hpp"
#include "square.hpp"

using namespace std;

int main() {

    point p1; 
    point p2(0, 40);
    point p3(30, 40);
    point p4(30, 0);

    triangle t1(p1, p2, p3); 
    square s1(p1, p2, p3, p4);

    double width = 100, height = 100;
    cout << "<svg width=\"" << width << "\" height=\"" << height << "\" xmlns=\"http://www.w3.org/2000/svg\">" << endl;
    cout << "<style type=\"text/css\">line{stroke:black;stroke-width:1;stroke-opacity:0.5;stroke-linecap:round;}</style>" << endl;

    // t1.Draw();
    s1.Draw();
    
    cout << "</svg>" << endl;
}
