#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "point.hpp"

class triangle {
    public: 
        triangle(const point &a_in, const point &b_in, const point &c_in);
        double perimeter() const;
        void translate(const point &vector_in); 
        void display() const;

    private:
        point a; 
        point b; 
        point c;
};

#endif