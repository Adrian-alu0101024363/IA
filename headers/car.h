#include <iostream>
#include <algorithm>
#include "zone.h"

using namespace std;

class car_t{

private:
    int x_;
    int y_;
    vector<int> perception;

public: 

    car_t ();
    car_t (int x, int y);
    ~car_t();
    int getx();
    void setx(int x);
    int gety();
    void sety(int y);
    void calculatePerception(int i, int j,zone_t& road);

};