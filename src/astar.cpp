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
void astar_t::filestreet(zone_t& zone) {street_ = zone;}

void astar_t::writetest() {
    street_.addWall(1,1);
    street_.print();
    }