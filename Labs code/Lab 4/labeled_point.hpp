#ifndef LABELED_POINT_HPP
#define LABELED_POINT_HPP

#include <string>
#include "point.hpp"

class labeled_point {

    public:
        labeled_point();
        labeled_point(const std::string& label);
        labeled_point(const double &x, const double &y ,const std::string &label);
        double get_x() const;
        double get_y() const;
        std::string get_label() const;
        void set_x(const double &x);
        void set_y(const double &y);
        void set_label(const std::string &label);
        double distance_to(const point &ref) const;
        double distance_to(const labeled_point &ref) const;

    private:
        double x;
        double y; 
        std::string label;

    friend bool operator<(const labeled_point &p1, const labeled_point &p2);
    friend bool operator==(const labeled_point &p1, const labeled_point &p2);
    friend std::ostream& operator<<(std::ostream& os, const labeled_point& p);
};

#endif