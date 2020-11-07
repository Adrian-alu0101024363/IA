#include <windows.h>
#include <iostream>
#include "../headers/car.h"

using namespace std;

int main (int argc, char *argv[]) {

    string filename;
    filename = argv[1];
    zone_t zona(5,5);
    zone_t zona2;
    zona2.readFromFile(filename);
    zona2.print();
    /*zona.addWall(2,2);
    zona.addWall(2,3);
    zona.addWall(4,2);
    zona.addInitial(1,4);
    zona.addFinal(3,1);
    zona.addPath(1,1);
    zona.addPath(1,2);
    zona.addPath(1,3);
    zona.addPath(2,1);
    zona.print();
    //zona.clear();
    zona.generate(50);
    zona.print();
    zona.generate(25);
    zona.print();
    zona.generate(90);
    zona.print();*/
    //zone_t zona2(20,14);
    //zona2.print();
    
} 
