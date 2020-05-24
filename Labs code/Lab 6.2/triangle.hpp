#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "point.hpp"
#include "shape.hpp"

class triangle : public shape {
    public: 
        triangle(const point &a_in, const point &b_in, const point &c_in);
        double perimeter() const;
        void translate(const point &vector_in); 
        void display() const;
        void Draw();

    private:
        point a; 
        point b; 
        point c;
};

#endif