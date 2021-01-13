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

//copy constructor (this is shallow copy)
// polynomial::polynomial(const polynomial &ref) {
//     cout << "Copy constructor ! (shallow)" << endl;
//     this->coefficients = ref.coefficients;
//     this->degree = ref.degree;
// }

//assignment overloaded operator (this is shallow copy)
// polynomial& polynomial::operator=(const polynomial &ref) {
//     cout << "Overloaded assignment ! (shallow)" << endl;
//     this->coefficients = ref.coefficients;
//     this->degree = ref.degree;

//     return *this;
// }

//copy constructor (this is deep copy)?
//this is not allowed (will not compile) 
//parameter must be of type const polynomial& or others (cannot be of type polynomial)
//because when you pass a parameter by value, it will be copied
//but you are still in the midst of defining a copy constructor
//so it will not work 
// polynomial::polynomial(polynomial ref) {
//     this->coefficients = ref.coefficients;
//     this->degree = ref.degree;
// }

//assignment overloaded operator (this is deep copy)?
//no, because ref.coefficients is a pointer to double
//so this->coefficients will be a dangling pointer 
//after exiting this scope (ref will be destroyed since it is a local variable)
// polynomial& polynomial::operator=(polynomial ref) {
//     cout << "Address of param ref: " << &ref << endl;
//     cout << "Overloaded assignment ! (deep?)" << endl;
//     this->coefficients = ref.coefficients;
//     this->degree = ref.degree;

//     return *this;
// }

//assignment overload operator (deep copy)
polynomial& polynomial::operator=(const polynomial& ref) {

    //if statement needed to protect self assignment
    //however, i think it depends on the compiler
    //clang will still allow you to access deleted memory locations
    //so this->coefficients[i] = ref.coefficients[i]; would still work 
    //however clang will raise runtime error if you try to delete twice 
    if (&ref != this) {
        //needed to prevent memory leak
        delete[] this->coefficients;

        cout << "Overloaded assignment ! (deep)" << endl;
        this->degree = ref.degree;
        this->coefficients = new double[this->degree + 1];

        for (int i = 0; i < this->degree + 1; i++) {
            this->coefficients[i] = ref.coefficients[i];
        }
    }
    return *this;
}

//copy constructor (deep copy) 
polynomial::polynomial(const polynomial &ref) {

    cout << "Copy constructor ! (deep)" << endl;
    this->degree = ref.degree;
    this->coefficients = new double[this->degree + 1];
    cout << "Coefficients at add: " << &(this->coefficients) << endl;

    for (int i = 0; i < this->degree + 1; i++) {
        this->coefficients[i] = ref[i];
    }
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
    cout << "Calling destructor of polynomial " << endl;
    cout << "Destroying coefficients at add: " << &(this->coefficients) << endl;
    delete[] this->coefficients;
    cout << "Destroyed" << endl;
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
    // cout << "Const version of []" << endl;
    return this->coefficients[index]; 
}

double& polynomial::operator[](const int &index) {
    // cout << "Non-const version of []" << endl;
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