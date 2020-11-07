#include <iostream>
#include <algorithm>
#include "zone.h"

using namespace std;

class car_t{

private:
    int x_;
    int y_;
    vector<int> perception;
    int dir_; //0 left, 1 up, 2 right, 3 down

public: 

    car_t ();
    car_t (int x, int y);
    ~car_t();
    int getx();
    void setx(int x);
    int gety();
    void sety(int y);
    int getdir();
    void setdir(int dir);
    void calculatePerception(int i, int j,zone_t& road);
    void move(int dir,zone_t& road);

};
