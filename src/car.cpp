#include "../headers/car.h"

using namespace std;

car_t::car_t () {

    x_ = 1;
    y_ = 1; 
    perception.resize(4);
    dir_ = 0;
}
car_t::car_t(int x, int y) {

    x_ = x;
    y_ = y;
    perception.resize(4);
    dir_ = 0;
}

int car_t::getx() { return x_;}

void car_t::setx(int x) { x_ = x; }

int car_t::gety() { return y_;}

void car_t::sety(int y) { y_ = y; }

int car_t::getdir() { return dir_;}

void car_t::setdir(int dir) { dir_ = dir;}

void car_t::calculatePerception(int i, int j,zone_t& road) {

    char bloque = 219;
    string muro;
    muro.push_back(bloque);
    perception[0] = road(i - 1,j) == muro ? 1 : 0; //N
    perception[1] = road(i,j - 1) == muro ? 1 : 0; //O
    perception[2] = road(i + 1,j) == muro ? 1 : 0; //S
    perception[3] = road(i,j + 1) == muro ? 1 : 0; //E

}
//tratar como 1 por el vector de zone?
void car_t::move(int dir, zone_t& road) {

    switch(dir) {
    case 0:
        if (gety() != 0) {
            sety(gety() - 1);
            //setdir(0);
        }
        break;
    case 1:
        if (getx() != 0) {
            setx(getx() - 1);
            //setdir(1);
        }
        break;
    case 2:
        if (gety() != (road.get_columns()-1)) {
            sety(gety() + 1);
            //setdir(2);
        }
        break;
    case 3:
        if (getx() != (road.get_rows() - 1)) {
            setx(getx() + 1);
            //setdir(3);
        }
        break;
    }

}
