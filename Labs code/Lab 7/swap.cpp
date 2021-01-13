#include <string>
#include <iostream>
#include "complex.hpp"

using namespace std;

template <class Type>
void my_swap(Type& a, Type& b) {
    Type c; 
    c = a; 
    a = b; 
    b = c; 
}

template <class T1, class T2>
T2 my_add(T1 a, T2 b) {
    cout << "using 2 parameters version" << endl;
    return a + b; 
}

template <class Type>
Type my_add(Type a, Type b) {
    cout << "using 1 parameter version" << endl;
    return a + b; 
}


//doesn't work 
// template <class T1, class T2, class T3>
// T2 my_add(T1 a, T2 b) {
//     return a + b; 
// }

//doesn't work (template line only applies to function directly below it)
// void test(Type& a) {}

int main() {
    int i1 = 1, i2 = 2; 
    double d1 = 1, d2 = 2; 
    string s1 = "1", s2 = "2";

    my_swap(i1, i2);
    my_swap(d1, d2);
    my_swap(s1, s2);

    cout << i1 << " " << i2 << endl;
    cout << d1 << " " << d2 << endl;
    cout << s1 << " " << s2 << endl;

    int n1 = 10; 
    double n2 = 15.15; 
    cout << my_add(n1, n2) << endl;
    cout << my_add(n2, n1) << endl;

    //the most specific version is selected (1 parameter version)
    //if 1 parameter version not present, will use 2 parameters version 
    cout << my_add(n1, n1) << endl;
    cout << my_add(n2, n2) << endl;

    //to force a specific version 
    cout << my_add<int, int>(n1, n1) << endl;
    cout << my_add<double, double>(n2, n2) << endl;

    Complex<double> c; 
    //not allowed (must specify type), and even with default parameter, must use <> 
    // Complex d(5, 6);
    Complex<double> d(5, 6);
    Complex<> e(2, 7);

    return 0; 
}