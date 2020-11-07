
#include "../headers/zone.h"
#include <iomanip>

using namespace std;

zone_t::zone_t():
    rows_(),
    columns_(),
    zone_() {
        symbols_ = {"I","F","*"};
    }

zone_t::zone_t(int rows, int columns):
    rows_(rows), 
    columns_(columns),
    zone_(rows_ * columns_) {
    string inival = "-";
    write(inival);
    symbols_ = {"I","F","*"};

}
 zone_t::~zone_t() {

 }

void zone_t::resizev(int m, int n) {
    set_rows(m);
    set_columns(n);
    zone_.resize(rows_ * columns_);
    initval_ = "-";
    write(initval_);
}

string& zone_t::at (int i, int j) {

    return zone_.at(pos(i,j));
}
    
int zone_t::pos(int i, int j) const {

    return (i -1)* columns_ + j - 1;
}

string& zone_t:: operator() (int i, int j) {

    return at(i,j);
}

int zone_t::get_rows(void) const {
    return rows_;
}

int zone_t::get_columns(void) const {
    return columns_;
}

void zone_t::set_rows(int m) {
    rows_ = m;
}

void zone_t::set_columns(int n) {
    columns_ = n;
}

void zone_t::set_symbol(string symbol, int position) {
    symbols_[position] = symbol;
}

void zone_t::write(string inival) {
    initval_ = inival;
    for(int i = 1; i <= rows_; i++){
        for(int j = 1; j <= columns_; j++)
            at(i, j) = inival;
    }      
}

void zone_t::clear(void) {
    write(" ");     
}
//Usar switch case para mas elegancia y mas eficiencia
void zone_t::print() {
    cout << endl;
    for(int i = 1; i <= rows_; i++){
        cout << setw(6);
        for(int j = 1; j <= columns_; j++) {
         
             if (at(i,j) == symbols_[0]) {
                COLOR_PINK;
            } else if (at(i,j) == symbols_[1]) {
                COLOR_BLUE;
            } else if (at(i,j) == symbols_[2]) {
                COLOR_CYAN;
            } else 
            { 
                COLOR_RESET;
            }
            cout << at(i,j) << setw(6); 
            COLOR_RESET;
        }        
        cout << endl;
    }      
    cout << endl;
}

//To do in general: Control de overflow del rango
//Posible problema muro mal colocado imposible solucion
void zone_t::addWall(int i, int j) {
    int bloque = 219;
    //if ((at(i,j) == symbols_[0]) || (at(i,j) == symbols_[1])) {
      //  cout << "Muro no valido";
    //} else {
    at(i,j) = (char)bloque;
    //}
}

//to do: controlar si ya hay un punto inicial y sustituirlo
void zone_t::addInitial(int i, int j) {
    at(i,j) = symbols_[0];
}

//to do: controlar si ya hay un punto final y sustituirlo
void zone_t::addFinal(int i, int j) {

    at(i,j) = symbols_[1];
}

//función para usarla cuando implemente el algoritmo de la IA
void zone_t::addPath(int i, int j) {
    at(i,j) = symbols_[2];
}

void zone_t::readFromFile(string filename) {
    ifstream inputfile;
    int m, n, initiali, initialj, numberWalls;
    int x,y,finali,finalj;
    inputfile.open(filename);
    if (inputfile.is_open()) {
        inputfile >> m >> n;
        resizev(m,n);
        inputfile >> initiali >> initialj;
        inputfile >> numberWalls;
        for (int i = 0; i < numberWalls; i++) {
            inputfile >> x >> y;
            addWall(x,y);
        }
        inputfile >> finali >> finalj;
    }
    inputfile.close();
    addInitial(initiali,initialj);
    addFinal(finali,finalj);
}
//25%, 50%, 90% recursivo mejor?
void zone_t::generate(int porcentaje) {
    clear();
    string initval = "-";
    write(initval);
    int contador = 0;
    int randomsaishoi = (rand() % rows_) + 1;
    int randomsaishoj = (rand() % columns_) + 1;
    int randomsaigoi = (rand() % rows_) + 1;
    int randomsaigoj = (rand() % columns_) + 1;
    addInitial(randomsaishoi,randomsaishoj);
    addFinal(randomsaigoi,randomsaigoj);
    int nWalls = porcentaje * (rows_ * columns_) /100;
    int randomi, randomj;
    for(int i = 0; i < nWalls; i++){
        randomi = (rand() % rows_) + 1;
        randomj = (rand() % columns_) +1;
        if (at(randomi,randomj) == initval_ ) {
            addWall(randomi,randomj);
            contador++;
        } else  {
            --i;
        }
        
    }
    //cout << contador << endl;
}