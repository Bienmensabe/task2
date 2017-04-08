#include "circle.h"

int main()
{

//The Earth and the rope

    Circle earth(6378.1);
    Circle rope;

    rope.set_ference((earth.get_ference() + 0.001));

    double gap = rope.get_radius() - earth.get_radius();

    std::cout << "Gap between the Earth and the rope is  " << gap << " km \n" << std::endl;

//The pool

    Circle pool(3);
    Circle perimeter ((pool.get_radius()+1));

    const int track_price_sqm = 1000;
    const int fence_price_m = 2000;

    double track_area = perimeter.get_area() - pool.get_area();
    double fence_ference = perimeter.get_ference();

    double track_cost = track_area * track_price_sqm;
    double fence_cost = fence_ference * fence_price_m;

    std::cout << "Materials cost for the track is " << track_cost << " rub" << std::endl;
    std::cout << "Materials cost for the fence is " << fence_cost << " rub" << std::endl;

    return 0;
}
