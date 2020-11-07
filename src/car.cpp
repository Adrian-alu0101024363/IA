#include "../headers/car.h"

using namespace std;

car_t::car_t () {
    x_ = 1;
    y_ = 1; 
    perception.resize(4);
}
car_t::car_t(int x, int y) {
    x_ = x;
    y_ = y;
}

int car_t::getx() { return x_;}

void car_t::setx(int x) { x_ = x; }

int car_t::gety() { return y_;}

void car_t::sety(int y) { y_ = y; }

void car_t::calculatePerception(int i, int j,zone_t& road) {

char bloque = 219;
string muro;
muro.push_back(bloque);
perception[0] = road(i - 1,j) == muro ? 1 : 0; //N
perception[1] = road(i,j - 1) == muro ? 1 : 0; //O
perception[2] = road(i + 1,j) == muro ? 1 : 0; //S
perception[3] = road(i,j + 1) == muro ? 1 : 0; //E

}