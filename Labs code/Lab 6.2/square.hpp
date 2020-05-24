#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "shape.hpp"
#include "point.hpp"

class square : public shape {
    public: 
        void Draw();
        square(const point &a, const point &b, const point &c, const point &d);

    private:
        point a; 
        point b; 
        point c;
        point d;
};

#endif