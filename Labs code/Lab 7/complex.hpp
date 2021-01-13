#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

template<class T = double> 
class Complex{ 
    public: 
        Complex(T i_real = 0, T i_img = 0): real(i_real), img(i_img) {}

        template<class T2> 
        friend std::ostream& operator<<(std::ostream& os, Complex<T2> c);

    private: 
        T real; 
        T img; 
};

template<class T> 
std::ostream& operator<<(std::ostream& os, Complex<T> c) {
    os << "(" << c.real << ", " << c.img << ")" << std::endl;
    return os; 
}

#endif