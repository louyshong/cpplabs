#include <iostream>
#include <vector> 

using namespace std;

class Base {
    public: 
        Base() : n_priv(0), n_prot(0) {}
        Base(int n1, int n2) : n_priv(n1), n_prot(n2) {}
        ~Base() { 
            cout << "~Base(): n_priv=" << n_priv << ", n_prot=" << n_prot << " is leaving" << endl;
        }
        void f() { 
            cout << "Base::f()" << endl;
        }
        void display() {
            cout << "Base::display(): n_priv=" << n_priv << ", n_prot=" << n_prot << endl;
        }
        void call_all_function() {
            cout << "Base::call_all_functions()" << endl;
            f();
            f_priv();
            f_prot();
        }

    private:
        int n_priv;
        void f_priv() {
            cout << "Base::f_priv()" << endl;
        }

    protected: 
        int n_prot;
        void f_prot() {
            cout << "Base::f_prot()" << endl;
        }
};

class Derived : public Base {
    public:
        Derived() : Base(), n_base(0) {}
        Derived(int n1, int n2, int n3) : Base(n1, n2), n_base(n3) {}
        ~Derived() {
            cout << "~Derived(): n_base=" << n_base << " is leaving" << endl;
        } 
        void f() {
            cout << "Derived::f()" << endl;
        }
        void f(int n) {
            cout << "Derived::f(int n) with n=" << n << endl;
        } 
        void display() {
            cout << "Derived::display(): " << endl;
            Base::display();
            cout << "n_base=" << n_base << endl;
        }
        void new_function() {
            cout << "Derived::new_function()" << endl;
        }

    protected: 
        int n_base;
};

class DerivedAgain : public Derived {};

int main() {
    // Base b1; 
    // Derived d1; 
    DerivedAgain da1;
}
