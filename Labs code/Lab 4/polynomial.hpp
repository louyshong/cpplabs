#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <iostream>

class polynomial {
    public: 
        polynomial();
        polynomial(const polynomial &ref);
        polynomial(const int &degree);
        ~polynomial();
        polynomial& operator=(const polynomial &ref);
        double& at(const int &i);
        double evaluate(const double &d) const;
        int get_degree() const;
        double operator[](const int &index) const;
        double& operator[](const int &index);

    private: 
        double* coefficients;
        int degree;

    friend std::ostream& operator<<(std::ostream& os, const polynomial& pol);
};

#endif