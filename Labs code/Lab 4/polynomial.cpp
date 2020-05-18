#include "polynomial.hpp"
#include <iostream>
#include <cmath>

using namespace std;

//default constructor
polynomial::polynomial() {
    this->coefficients = new double;
    this->coefficients[0] = 0;
    this->degree = 0;
}

//copy constructor
polynomial::polynomial(const polynomial &ref) {
    this->coefficients = ref.coefficients;
    this->degree = ref.degree;
}

//parametrised constructor
polynomial::polynomial(const int &degree) {
    this->coefficients = new double[degree+1];

    //initialise to zeros
    for (int i = 0; i < degree + 1; i++) {
        this->coefficients[i] = 0;
    }

    this->degree = degree;
}

//destructor
polynomial::~polynomial() {
    cout << "Calling destructor of polynomial" << endl;
}

//assignment overloaded operator
polynomial& polynomial::operator=(const polynomial &ref) {
    this->coefficients = ref.coefficients;
    this->degree = ref.degree;

    return *this;
}

double& polynomial::at(const int &i) {
    return this->coefficients[i];
}

double polynomial::evaluate(const double &d) const {
    double result = 0;

    for (int i = 0; i < this->degree + 1; i++) {
        result += this->coefficients[i] * (pow(d, i));
    }

    return result;
}

int polynomial::get_degree() const {
    return this->degree;
}

double polynomial::operator[](const int &index) const {
    return this->coefficients[index];
}

double& polynomial::operator[](const int &index) {
    return this->coefficients[index];
}

ostream& operator<<(ostream &os, const polynomial &poly) {
    
    //insert constant
    if (poly.degree > 0) {
        os << poly[0] << " + ";        
    } else {
        os << poly[0];
    }

    for (int i = 1; i < poly.degree; i++) {
        os << poly[i] << "x^" << i << " + ";
    }

    //highest degree 
    if (poly.degree > 0) {
        os << poly[poly.degree] << "x^" << poly.degree;
    }

    return os;
}