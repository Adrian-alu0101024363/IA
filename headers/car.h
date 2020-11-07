#include <iostream>
#include <algorithm>
#include "zone.h"

using namespace std;

class car_t{

private:
    zone_t grid;
    int x;
    int y;
    vector<int> perception;

public: 

    car_t ();
    car_t (int x, int y);
    ~car_t();
    int getx();
    void setx();
    int gety();
    void sety();
    void calculatePerception(int i, int j);

};