#ifndef POINT_HPP
#define POINT_HPP

class point {
    public: 
        void display() const;
        void set_x(const double &x_in);
        void set_y(const double &y_in);
        double get_x() const;
        double get_y() const;
        void translate(const point &p_in);
        double get_distance_org() const;
        double get_distance_point(const double &x_ref, const double &y_ref) const;
        // point();
        point(const double &x_in = 0, const double &y_in = 0);

    private: 
        double x; 
        double y;

    friend bool operator == (const point &p1, const point &p2);
};

#endif