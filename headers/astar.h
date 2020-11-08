#include "../headers/car.h"
#include "../headers/node.h"

class astar_t {

private:
    zone_t street_;
    vector<node_t*> generated_;
    vector<node_t*> fpath_;
    vector<node_t*> notexplored_;
    int function_; //que tipo de funcion heuristica a usar
    int passengers; 

public:
    astar_t();
    astar_t(int m, int n, int x, int y);
    astar_t(int m, int n, int x, int y,int function);
    ~astar_t();
    void filestreet(zone_t& zone);
    int getpassengers();
    void setpassengers(int passenger);
    void setfunction(int function);
    int resultofh(int g, int x, int y);
    int calculateh(int x, int y, int destx, int desty);
    void writetest();

};