#include "../headers/node.h"

using namespace std;

node_t::node_t(): 
    x_(0),
    y_(0),
    cost_(0) {}

node_t::node_t(int x, int y):
    x_(x),
    y_(y),
    cost_(0){}

node_t::node_t(int x,int y, int cost):
    x_(x),
    y_(y),
    cost_(cost){}

node_t::~node_t(){
    x_ = 0;
    y_ = 0;
    cost_ = 0;
    sucesors_.resize(0);
    //predecesors_.resize(0);
    //g_ = 0;
}

int node_t::getx() { return x_;}
int node_t::gety() { return y_;}
int node_t::getg() { return g_;}
int node_t::getcost() { return cost_;}

node_t* node_t::getpred() { return predecesor_;}

void node_t::setx(int x) { x_ = x;}
void node_t::sety(int y) { y_ = y;}
void node_t::setcost(int cost) { cost_ = cost;}
void node_t::setg(int g) { g_ = g;}
void node_t::setsuc(node_t* aux) {sucesors_.push_back(aux);}
void node_t::setpred(node_t* aux) {predecesor_ = aux;}
