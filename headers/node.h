#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cstdio>
#include <math.h>
#include <locale>
#include <time.h>

using namespace std;

class node_t {

private:

    int x_;
    int y_;
    int g_;
    int cost_;
    vector<node_t*> sucesors_;
    node_t* predecesor_;

public:

    node_t();
    node_t(int x, int y);
    node_t(int x, int y, int cost);
    ~node_t();
    int getx();
    int gety();
    int getg();
    int getcost();
    node_t* getpred();
    void setx(int x);
    void sety(int y);
    void setcost(int cost);
    void setg(int g);
    void setsuc(node_t* aux);
    void setpred(node_t* aux);
};
