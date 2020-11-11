#include "../headers/zone.h"
#include "../headers/node.h"
#include <climits>

class astar_t {

private:
    zone_t street_;
    vector<node_t*> generated_;
    vector<node_t*> fpath_;
    vector<node_t*> notexplored_;
    int function_; //que tipo de funcion heuristica a usar
    vector<int> perception_; //0 O,1 N,2 E,3 S

public:
    astar_t();
    astar_t(zone_t& zone,int function);
    astar_t(int m, int n, int x, int y,int function);
    ~astar_t();
    void filestreet(zone_t& zone);
    void setfunction(int function);
    int resultofh(int g, int x, int y);
    int calculateh(int x, int y, int destx, int desty);
    void writetest();
    void resolve();
    void perception(int x, int y);
    void path();
};