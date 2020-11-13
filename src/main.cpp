#include <windows.h>
#include <iostream>
//#include "../headers/car.h"
#include "../headers/astar.h"

using namespace std;

int main (int argc, char *argv[]) {

    string filename;
    filename = argv[1];
    zone_t zona(15,15);
    zone_t zona2;
    zona2.readFromFile(filename);
    COLOR_PINK;
    cout << "La nueva zona es: " << endl;
    COLOR_RESET;
    zona2.print();
    astar_t test(zona2,2);
    COLOR_BLUE;
    cout << "Camino optimo:" << endl;
    COLOR_RESET;
    test.resolve();
    test.path();
    test.writetest();
    zona.generate(25);
    COLOR_PINK;
    cout << "La nueva zona es: " << endl;
    COLOR_RESET;
    zona.print();
    astar_t test2(zona,2);
    COLOR_BLUE;
    cout << "Camino optimo:" << endl;
    COLOR_RESET;
    test2.resolve();
    test2.path();
    test2.writetest();
    zona.clear();
    zona.generate(50);
    astar_t test3(zona,1);
    COLOR_BLUE;
    cout << "Camino optimo:" << endl;
    COLOR_RESET;
    test3.resolve();
    test3.path();
    test3.writetest();
    

    
} 
