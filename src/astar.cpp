#include "../headers/astar.h"

using namespace std;

astar_t::astar_t() {
    generated_.resize(0);
    notexplored_.resize(0);

}

astar_t::astar_t(int m, int n, int x, int y) {
    street_.resizev(m,n);
    street_.addInitial(x,y);
}

astar_t::astar_t(int m, int n, int x, int y,int function) {
    street_.resizev(m,n);
    street_.addInitial(x,y);
    function_ = function;
}

astar_t::~astar_t() {
    generated_.resize(0);
    notexplored_.resize(0);
}
void astar_t::filestreet(zone_t& zone) { street_ = zone;}

void astar_t::setfunction(int function) { function_ = function;}

int astar_t::resultofh(int g, int x, int y) {

    int result = 0;
    result = g + calculateh(x,y,street_.get_destx(),street_.get_desty());
    return result;
}

int astar_t::calculateh(int x, int y, int destx, int desty) {
    int cox, coy;
    int result = 0;
    if (function_ == 1) { //lineas rectas en x e y 
        cox = x - destx;
        coy = y - desty;
        result = (fabs(cox) + fabs(coy));
        return result;
    } else if (function_ == 2) { //pitagoras linea recta exacta
        cox = destx - x;
        coy = desty - y;
        pow(cox,2);
        pow(coy,2);
        result = sqrt(cox + coy);
        return result;
    } else {
        cout << "Funcion no establecida" << endl;
        return result;
    }
}

void astar_t::writetest() { street_.print();}