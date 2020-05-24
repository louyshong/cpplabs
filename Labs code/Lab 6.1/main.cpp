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
        virtual void f() { 
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
    // Base b1(1, 2); 
    // Derived d1(3, 4, 5); 
    // b1.display();
    // b1.f();
    // d1.display();
    // d1.f();
    // d1.new_function();
    // d1.f(1);

    // DerivedAgain da1;
    // da1.f();
    // da1.display();
    // da1.new_function();
    // da1.call_all_function();
    // da1.f(2);

    Base b1;
    Derived d1;
    Derived da1;
    vector<Base> v1;
    v1.push_back(b1); v1.push_back(d1); v1.push_back(da1);

    for (int i = 0; i < v1.size(); i++) {
        v1[i].f();
    }

    vector<Base*> v2;
    Base* bp1 = new Base;
    Derived* dp1 = new Derived;
    DerivedAgain* dap1 = new DerivedAgain;
    v2.push_back(bp1); v2.push_back(dp1); v2.push_back(dap1);

    for (int i = 0; i < v2.size(); i++) {
        v2[i]->f();
    }
}
