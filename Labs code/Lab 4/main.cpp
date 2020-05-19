#include "polynomial.hpp"
#include <iostream>

using namespace std;

int main() {
    //Test 1) at(int) member function
    polynomial p(2);
    cout << p << endl;
    p.at(0) = 2; p.at(1) = 3; p.at(2) = 1;
    cout << p << endl;

    //Test 2) copy constructor
    polynomial p1(p);
    cout << p1 << endl;

    //Test 3) subscript operator[]
    p[0] = 5; p[1] = -4; p[2] = 3;
    cout << p << endl;

    //Test 4) assignment operator
    polynomial p2 = p;
    cout << p2 << endl;

    cout << "A" << endl;
    p = p; //self assignment
    cout << "B" << endl;

    cout << p << endl;

    polynomial p3 = p2 = p1; //chain assignment
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;

    // polynomial pconst; 
    // cout << pconst << endl;

    // //Test shallow/deep copy
    // polynomial ptest(2);
    // ptest.at(0) = 1; ptest.at(1) = 2; ptest.at(2) = 3;

    // polynomial ptest1(ptest);
    // polynomial ptest2 = ptest; //THIS IS INITIALISATION NOT ASSIGNMENT ?!? 

    // cout << ptest << endl;
    // cout << ptest1 << endl;
    // cout << ptest2 << endl;

    // ptest.at(0) = 5;

    // cout << ptest << endl;
    // cout << ptest1 << endl;
    // cout << ptest2 << endl; 

    // ptest2 = ptest; 

    // ptest.at(0) = 10;

    // cout << ptest << endl;
    // cout << ptest1 << endl;
    // cout << ptest2 << endl;  

}