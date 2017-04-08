#include "circle.h"

Circle::Circle(double r) {
    set_radius(r);
}

Circle::Circle() {
    radius = 0;
    ference = 0;
    area = 0;
}

void Circle::set_radius(double r) {
    radius = r;
    ference = 2*M_PI*r;
    area = M_PI*pow(r, 2);
}

void Circle::set_ference(double f) {
    ference = f;
    radius = ference/(2*M_PI);
    area = M_PI*pow(radius, 2);
}

void Circle::set_area(double a) {
    area = a;
    radius = pow(area/M_PI, 0.5);
    ference = 2*M_PI*radius;
}

double Circle::get_radius() {
    return radius;
}

double Circle::get_ference() {
    return ference;
}

double Circle::get_area() {
     return area;
}
