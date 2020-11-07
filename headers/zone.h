#define COLOR_BLUE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE)
#define COLOR_RESET SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15)
#define COLOR_RED SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED)
#define COLOR_GREEN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN) 
#define COLOR_PINK SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5)  
#define COLOR_CYAN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3) 

#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <fstream>

using namespace std;

class zone_t {
private:
    int rows_;
    int columns_;
    vector<string> symbols_;
    vector<string> zone_;
    string initval_;

public:   
    zone_t ();
    zone_t(int rows,int columns);
    ~zone_t();
    void resizev(int m, int n);
    string& at (int i, int j);
    string& operator()(int i, int j);
    int get_rows(void) const;
    int get_columns(void) const;
    void set_rows(int m);
    void set_columns(int n);
    void set_symbol(string symbol, int position);
    void write(string inival); //Rellena el vector con la string inival
    void clear(void);
    void print();
    void addWall(int i, int j);
    void addInitial(int i, int j);
    void addFinal(int i, int j);
    void addPath(int i, int j);
    void readFromFile(string filename);
    void generate(int porcentaje);

private: 

    int pos(int i, int j) const;


};