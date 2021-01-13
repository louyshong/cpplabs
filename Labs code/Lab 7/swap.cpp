#include <string>
#include <iostream>

using namespace std;

template <class Type>
void my_swap(Type& a, Type& b) {
    Type c; 
    c = a; 
    a = b; 
    b = c; 
}

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

    return 0; 
}