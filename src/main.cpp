#include <windows.h>
#include <iostream>
//#include "../headers/car.h"
#include "../headers/astar.h"

using namespace std;

int main (int argc, char *argv[]) {

    string filename;
    filename = argv[1];
    zone_t zona(25,25);
    zone_t zona2;
    zona2.readFromFile(filename);
    zona2.print();
    astar_t test(zona2,2);
    test.resolve();
    test.path();
    //test.filestreet(zona2);
    test.writetest();
    zona.generate(25);
    //zona.generate(90);
    zona.print();
    astar_t test2(zona,2);
    test2.resolve();
    test2.path();
    test2.writetest();
    zona.clear();
    zona.generate(50);
    astar_t test3(zona,1);
    test3.resolve();
    test3.path();
    test3.writetest();
    

    
} 
