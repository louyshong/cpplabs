#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// defining our own exception
class invalid_sqrt_argument : public invalid_argument {
    public: 
        invalid_sqrt_argument(const string& what) : invalid_argument(what) {}
};

double my_sqrt(double n) {
    if (n < 0) {
        // cout << "cannot compute sqrt of negative number" << endl;
        // exit(EXIT_FAILURE);
        // throw string("cannot compute sqrt of negative number");
        throw invalid_sqrt_argument("cannot compute sqrt of negative number");
    }
    double result = sqrt(n);
    if (isnan(result)) {
        // happens when cin is nan 
        // cout << "cannot compute sqrt" << endl;
        // exit(EXIT_FAILURE);
        // throw string("cannot compute sqrt");
        throw logic_error("cannot compute sqrt");
    }

    return result;
}

int main(){ 

    // test range check --------------------------------
    // vector<int> v(3); 
    // cout << v.size() << " " << v.capacity() << endl;

    // for (vector<int>::iterator it = v.begin(); it < v.end(); ++it) {
    //     cout << *it << endl;
    // }

    // // [] operator does not perform range check 
    // cout << v[33] << endl; // this gives 0
    // // cout << v[330000] << endl; // this gives seg fault 
    // // cout << v.at(33) << endl; // this throws exception 

    // try {
    //     cout << v.at(33) << endl;
    // }
    // // catch (const string& a) {
    // //     cout << "be careful with your bounds" << endl; 
    // // }
    // catch (const out_of_range& e) {
    //     cout << "be careful with your bounds" << endl;
    // }

    // now try my_sqrt --------------------------------

    // double n; 
    // cin >> n;
    // try {
    //     cout << my_sqrt(n) << endl;
    // }
    // catch (const string& msg) {
    //     cout << msg << endl;
    // }

    // now try this --------------------------------

    vector<int> v(3); 
    int i;
    double num, result;
    cin >> i; 
    cin >> num;
    try {
        result = my_sqrt(num);
        v.at(i) = result;
        cout << v.at(i) << endl;
    }
    catch (const invalid_sqrt_argument& e) {
        cout << "unsuccessful sqrt computation: " << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cout << "index not suitable: " << e.what() << endl;
    }
    catch (const logic_error& e) {
        cout << "logic error: " << e.what() << endl;
    }

    cout << "do something else" << endl;

    return 0; 
}   