#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <cmath>

#define _USE_MATH_DEFINES

class Circle {

public:

    Circle(double);
    Circle();

    void set_radius(double);
    void set_ference(double);
    void set_area(double);

    double get_radius();
    double get_ference();
    double get_area();

private:

    double radius;
    double ference;
    double area;

};

#endif // CIRCLE_H
