#include <iostream>
#include "point.hpp"
#include "triangle.hpp"
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

// int farthestpoint(vector<point> pointsvec) {
//     double currentfarthestdist = 0;
//     int indexoffarthest = 0;

//     for (int i = 0; i < pointsvec.size(); i++) {
//         double distance = pointsvec[i].get_distance_org();

//         if (distance > currentfarthestdist) {
//             currentfarthestdist = distance;
//             indexoffarthest = i;
//         }
//     }
//     return indexoffarthest;
// }

//these can be defined in point.cpp
bool operator< (const point &p1, const point &p2) {
    if (p1.get_distance_org() < p2.get_distance_org()) {
        return true;
    } else {
        return false;
    }
}

bool operator== (const point &p1, const point &p2) {
    if (p1.x == p2.x && p1.y == p2.y) {
        return true;
    } else {
        return false;
    }
}

int farthestpoint (vector<point> pointsvec) {
    int i = 0;

    for (int j = 1; j < pointsvec.size(); j++) {
        if (pointsvec[i] < pointsvec[j]) {
            i = j;
        }
    }
    return i;
}

int member_point_unordsearch (const point &pref, const vector<point> &pointsvec) {
    for (int i = 0; i < pointsvec.size(); i++) {
        if (pointsvec[i] == pref) {
            return i; 
        }
    }
    return pointsvec.size();
}

int member_point_binsearch (const point &pref, const vector<point> &pointsvec) {
    bool found = false;
    int start = 0; 
    int end = pointsvec.size();

    while (found != true) {

        if (pref == pointsvec[(end - start) / 2 + start]) {
            found = true;
            return (end - start) / 2 + start;
        } else if (pref < pointsvec[(end - start) / 2 + start]) {
            if (end < start) {
                return pointsvec.size();
            }
            end = (end - start) / 2 + start - 1;
        } else {
            if (end < start) {
                return pointsvec.size();
            }
            start = (end - start) / 2 + start + 1;
        } 
    }
}

//sorts using bubble sort
void member_point_sort (vector<point> &pointsvec) {
    int length = pointsvec.size(); 
    bool swapped = true; 

    //repeat until not swapped
    while (swapped == true) {

        swapped = false; 

        for (int i = 0; i < length - 1; i++) {
            if (!(pointsvec[i] < pointsvec[i+1])) {
                //swap points 
                point tmp = pointsvec[i+1];
                pointsvec[i+1] = pointsvec[i];
                pointsvec[i] = tmp;
                swapped = true; 
            }
        }

        length = length - 1; 
    }
}

int member_point (const point &pointref, const vector<point> &pointsvec, bool ordered = false) { 
    
    int index; 

    if (ordered == false) {
        cout << "using linear search" << endl;
        index = member_point_unordsearch(pointref, pointsvec);
    } else {
        cout << "using binary search" << endl;
        index = member_point_binsearch(pointref, pointsvec);
    }
    return index; 
}

vector<point> pointdup (const vector<point> &vec1, const vector<point> &vec2, bool ordered2 = false) {
    
    vector<point> vec3;
    
    for (int i = 0; i < vec1.size(); i++) {
        int index = member_point (vec1[i], vec2, ordered2);
        if (index != vec2.size()) {
            vec3.push_back(vec1[i]);
        }
    }

    return vec3;
}

int main(int argc, char* argv[]) {
    // point p;
    // point p2; 

    // p.display(); // junk values 
    // p.set_x(3);
    // p.set_y(4);
    // p.display();
    // p2.set_x(1);
    // p2.set_y(2);
    // cout << p.get_distance_org() << endl;
    // cout << p.get_distance_point(3, 4) << endl;
    // p.translate(p2);
    // p.display();

    //points and lines
    // vector<double> linepoints;
    // point pref;
    // double xref;
    // double yref;

    // cout << "Please enter 5 numbers: " << endl;
    // while (linepoints.size() < 5) {
    //     double linepoint;
    //     cin >> linepoint;
    //     linepoints.push_back(linepoint);
    // }

    // cout << "Enter a point: (x then y)" << endl;
    // cin >> xref; 
    // cin >> yref;
    // pref.set_x(xref);
    // pref.set_y(yref);

    // cout << "The distances between the lines and the point are: " << endl;
    // for (int i = 0; i < linepoints.size(); i++) {
    //     double distance = pref.get_distance_point(pref.get_x(), linepoints[i]);
    //     cout << distance << endl;
    // }

    // point p;

    // point p1(2, 4);

    // point p2(2, 4);

    // triangle t1(p, p1, p2);
    // t1.display();
    // cout << t1.perimeter() << endl;
    // t1.translate(p2);
    // t1.display();
    // cout << t1.perimeter() << endl;
    // cout << "Is p1 < p2 ?: " << (p1 < p2) << endl;
    // cout << "Is p1 == p2 ?: " << (p1 == p2) << endl;

    // vector<point> pointsvec; 
    // cout << "Enter 5 points: (x then y)" << endl;
    // while (pointsvec.size() < 5) {
    //     point newpoint;
    //     double newx, newy;
    //     cin >> newx;
    //     cin >> newy;
    //     newpoint.set_x(newx);
    //     newpoint.set_y(newy);
    //     newpoint.display();
    //     pointsvec.push_back(newpoint);
    // }

    // cout << "The index of point farthest from origin is: " << endl;
    // cout << farthestpoint(pointsvec) << endl;

    // ifstream infile1, infile2; 

    // infile1.open(argv[1]);
    // infile2.open(argv[2]);

    // int n1, n2;
    // char comma; 
    // vector<point> vec1;
    // vector<point> vec2;
    // vector<point> vec3;
    
    // while (infile1 >> n1 >> comma >> n2) {
    //     point tmp(n1, n2);
    //     vec1.push_back(tmp);
    // }

    // while (infile2 >> n1 >> comma >> n2) {
    //     point tmp(n1, n2);
    //     vec2.push_back(tmp);
    // }

    // bool ordered;

    // if (strcmp(argv[3], "true") == 0) {
    //     ordered = true;
    // }

    // if (strcmp(argv[3], "false") == 0) {
    //     ordered = false;
    // }

    // vec3 = pointdup(vec1, vec2, ordered);

    // ofstream myfile;
    // myfile.open(argv[4]);
 
    // for(int i = 0; i < vec3.size(); i++) {
    //     myfile << vec3[i];
    // }

    // myfile.close();

    // infile1.close();
    // infile2.close();

    ifstream infile; 

    infile.open(argv[1]);

    int n1, n2;
    char comma; 
    vector<point> vec;
    vector<point*> vecptr;

    while (infile >> n1 >> comma >> n2) {
        // point tmp(n1, n2);
        vec.push_back(point(n1, n2));
        cout << "Size of vec is: " << vec.size() << endl;
        cout << "Capacity of vec is: " << vec.capacity() << endl;

        // point* tmpptr = new point(n1, n2);
        // vecptr.push_back(tmpptr);
        // cout << "Size of vecptr is: " << vecptr.size() << endl;
        // cout << "Capacity of vecptr is: " << vecptr.capacity() << endl;
        // delete tmpptr;
    }


    // cout << "end of inner scope" << endl;
    
    return 0;
}