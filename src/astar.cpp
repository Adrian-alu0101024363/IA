#include "../headers/astar.h"

using namespace std;

astar_t::astar_t() {

    generated_.resize(0);
    notexplored_.resize(0);
	perception_.resize(4);
}



astar_t::astar_t(zone_t& zone,int function) {

    street_ = zone;
    function_ = function;
    perception_.resize(4);
}

astar_t::astar_t(int m, int n, int x, int y,int function) {
    street_.resizev(m,n);
    street_.addInitial(x,y);
    function_ = function;
	perception_.resize(4);
}

astar_t::~astar_t() {
    generated_.resize(0);
    notexplored_.resize(0);
	perception_.resize(0);
}

void astar_t::filestreet(zone_t& zone) { street_ = zone;}

void astar_t::setfunction(int function) { function_ = function;}

int astar_t::resultofh(int g, int x, int y) {

    int result = 0;
    result = g + calculateh(x,y,street_.get_destx(),street_.get_desty());
    return result;
}

int astar_t::calculateh(int x, int y, int destx, int desty) {
    int cox, coy;
    int result = 0;
    if (function_ == 1) { //lineas rectas en x e y 
        cox = x - destx;
        coy = y - desty;
        result = (fabs(cox) + fabs(coy));
        return result;
    } else if (function_ == 2) { //pitagoras linea recta exacta
        cox = destx - x;
        coy = desty - y;
        pow(cox,2);
        pow(coy,2);
        result = sqrt(cox + coy);
        return result;
    } else {
        cout << "Funcion no establecida" << endl;
        return result;
    }
}

void astar_t::writetest() { street_.print();}

void astar_t::resolve() {

	clock_t time;
	time = clock();

    //Inicializar variables 
    int x = street_.get_orgx();
    int y = street_.get_orgy();
    int destinationx = street_.get_destx();
    int destinationy = street_.get_desty();
    bool notcompleted = false;
    int g = 0;
    bool ended = false;
    int initdir = -1;
    //Cost va a ser la funcion heuristica resultado 
    //y metemos nodo de comienzo en generated_
    int cost = resultofh(g,x,y);
    node_t* start;
    start = new node_t(x,y,cost);
    start->setg(g);
    start->setcost(cost);
    generated_.push_back(start);
    
    //Punto inicial y nodos auxiliares crear

    x = start ->getx();
    y = start->gety();
    node_t* auxleft = NULL;
	node_t* auxup = NULL;
	node_t* auxright = NULL;
	node_t* auxdown = NULL;
	node_t* eleccion = NULL;
    g++;
    int min = INT_MAX; //variable donde ir guardando costes empieza en infinito
    int costaux = 0;

    //Nodos iniciales, compruebo si hay muro alrededor o si estoy en un borde
    //Y comparo costes para elegir el de menor coste
    
    perception(x,y);

    if (perception_[1] != 1 && y > 1) {
        costaux = resultofh(g, x, y - 1);
		auxleft = new node_t(x, y - 1, costaux);
		auxleft->setcost(costaux);
		auxleft->setg(g);
		auxleft->setpred(start);
		start->setsuc(auxleft);
		generated_.push_back(auxleft);
		min = costaux;
		initdir = 0;
		eleccion = auxleft;
    }
    if (perception_[0] != 1 && x > 1) {
        costaux = resultofh(g, x - 1, y);
		auxup = new node_t(x - 1, y, costaux);
		auxup->setcost(costaux);
		auxup->setg(g);
		auxup->setpred(start);
		start->setsuc(auxup);
		generated_.push_back(auxup);
		if (costaux < min) {
			min = costaux;
			initdir = 1;
			eleccion = auxup;
		}
    }
    if (perception_[2] != 1 && y < street_.get_columns() - 1) {
		costaux = resultofh(g, x, y + 1);
		auxright = new node_t(x, y + 1, costaux);
		auxright->setcost(costaux);
		auxright->setg(g);
		auxright->setpred(start);
		start->setsuc(auxright);
		generated_.push_back(auxright);
		if (costaux < min) {
			min = costaux;
			initdir = 2;
			eleccion = auxright;
		}
    }
    if (perception_[3] != 1 && x < street_.get_rows() - 1) {
		costaux = resultofh(g, x + 1, y);
		auxdown = new node_t(x + 1, y, costaux);
		auxdown->setcost(costaux);
		auxdown->setg(g);
		auxdown->setpred(start);
		start->setsuc(auxdown);
		generated_.push_back(auxdown);
		if (costaux < min) {
			min = costaux;
			initdir = 3;
			eleccion = auxdown;
		} 
    }
   
    //Segun el nodo elegido arriba para empezar se ponen los demás 
    //que sean viables en el vector de no explorados
	if (eleccion != NULL) {
		if (eleccion == auxleft) {
			if (auxup != NULL) {
				notexplored_.push_back(auxup);
			}
			if (auxright != NULL) {
				notexplored_.push_back(auxright);
			}
			if (auxdown != NULL) {
				notexplored_.push_back(auxdown);
			}
		}
		if (eleccion == auxup) {
			if (auxleft != NULL) {
				notexplored_.push_back(auxleft); 
			}
			if (auxright != NULL) {
				notexplored_.push_back(auxright);
			}
			if (auxdown != NULL) {
				notexplored_.push_back(auxdown);
			}
		}
		if (eleccion == auxright) {
			if (auxup != NULL) {
				notexplored_.push_back(auxup);
			}
			if (auxleft != NULL) {
				notexplored_.push_back(auxleft);
			}
			if (auxdown != NULL) {
				notexplored_.push_back(auxdown);
			}
		}
		if (eleccion == auxdown) {
			if (auxup != NULL) {
				notexplored_.push_back(auxup);
			}
			if (auxright != NULL) {
				notexplored_.push_back(auxright);
			}
			if (auxleft != NULL) {
				notexplored_.push_back(auxleft);
			}
		}
	}
    //En caso de no ser viable 
    if (initdir == -1) {

		for (int i = 0; i < notexplored_.size(); i++) {
			if (min > notexplored_[i]->getcost()) {
				start = notexplored_[i];
				g = start->getg();
			}
		}  
    //Según resultado establecemos el nodo de partida       
    } else {
		if (initdir == 0) {
			start = auxleft;
		}
		else if (initdir == 1) {
			start = auxup;
		}
		else if (initdir == 2) {
			start = auxright;
		}
		else if (initdir == 3) {
			start = auxdown;
		}   
    }
    //Pasamos al bucle de ramas y eso
    do {
        x = start->getx();
        y = start->gety();

        bool visited = false;
        //Si ya esta visitado lo sacamos
		for (int i = 0; i < notexplored_.size(); i++) {
			
			if ((notexplored_[i]->getx() == x) && (notexplored_[i]->gety() == y)) {
				visited = true;
			}
			if (visited) {
				if (i < notexplored_.size() - 1) {
					notexplored_[i] = notexplored_[i + 1];
				}
			}	
		}
		if (visited) {
			notexplored_.pop_back();
		}
        //Necesito resetear las variables auxiliares
		auxleft = NULL;
		auxup = NULL;
		auxright = NULL;
		auxdown = NULL;
		eleccion = NULL;
		g++;
		int dir = -1;
		min = INT_MAX;
		costaux = 0;
		bool aux = false;
        perception(x,y);
        if(perception_[1] != 1 && initdir != 2 && y > 1) {
            aux = false;
			for (int i = 0; i < generated_.size(); i++) {
				if ((generated_[i]->getx() == x) && (generated_[i]->gety() == y - 1)) {
					aux = true;
				}
			}
			if (!aux) {
				costaux = resultofh(g, x, y - 1);
				auxleft = new node_t(x, y - 1, costaux);
				auxleft->setcost(costaux);
				auxleft->setg(g);
				auxleft->setpred(start);
				start->setsuc(auxleft);
				generated_.push_back(auxleft);
				min = costaux;
				dir = 0;
				eleccion = auxleft;
			}
        }
        if (perception_[0] != 1 && initdir != 3 && x > 1) {
            aux = false;
			for (int i = 0; i < generated_.size(); i++) {
				if ((generated_[i]->getx() == x - 1) && (generated_[i]->gety() == y)) {
					aux = true;
				}
			}
			if (!aux) {
				costaux = resultofh(g, x - 1, y);
				auxup = new node_t(x - 1, y, costaux);
				auxup->setcost(costaux);
				auxup->setg(g);
				auxup->setpred(start);
				start->setsuc(auxup);
				generated_.push_back(auxup);
				if (costaux < min) {
					min = costaux;
					dir = 1;
					eleccion = auxup;
				}
			}
        }
        if (perception_[2] != 1 && initdir != 0 && y < street_.get_columns() - 1) {
            aux = false;
			aux = false;
			for (int i = 0; i < generated_.size(); i++) {
				if ((generated_[i]->getx() == x) && (generated_[i]->gety() == y + 1)) {
					aux = true;
				}
			}
			if (!aux) {
				costaux = resultofh(g, x, y + 1);
				auxright = new node_t(x, y + 1, costaux);
				auxright->setcost(costaux);
				auxright->setg(g);
				auxright->setpred(start);
				start->setsuc(auxright);
				generated_.push_back(auxright);
				if (costaux < min) {
					min = costaux;
					dir = 2;
					eleccion = auxright;
				}
			}
        }
        if (perception_[3] != 1 && initdir != 1 && x < street_.get_rows() - 1) {
            aux = false;
			for (int i = 0; i < generated_.size(); i++) {
				if ((generated_[i]->getx() == x + 1) && (generated_[i]->gety() == y)) {
					aux = true;
				}
			}
			if (!aux) {
				costaux = resultofh(g, x + 1, y);
				auxdown = new node_t(x + 1, y, costaux);
				auxdown->setcost(costaux);
				auxdown->setg(g);
				auxdown->setpred(start);
				start->setsuc(auxdown);
				generated_.push_back(auxdown);
				if (costaux < min) {
					min = costaux;
					dir = 3;
					eleccion = auxdown;
				}
			}
        }
		if (auxup != NULL) {
			notexplored_.push_back(auxup);
		}
		if (auxleft != NULL) {
			notexplored_.push_back(auxleft);
		}
		if (auxright != NULL) {
			notexplored_.push_back(auxright);
		}
		if (auxdown != NULL) {
			notexplored_.push_back(auxdown);
		}
        //La nueva dirección en la que mira es dir calculada antes
        initdir = dir;

		if (dir == -1) {
			min = INT_MAX;
			for (int i = 0; i < notexplored_.size(); i++) {
				if (min > notexplored_[i]->getcost()) {
					min = notexplored_[i]->getcost();

					start = notexplored_[i];
					g = start->getg();
				}
			}
		}

		else {
			bool no_ramificado = false;
			min = start->getcost();
			for (int i = 0; i < notexplored_.size(); i++) {
				if (notexplored_[i]->getcost() < min) {
					
					min = notexplored_[i]->getcost();
					start = notexplored_[i];
					no_ramificado = true;
					g = start->getg();
					initdir = -1;
				}

				
				
			}
			
			if (!no_ramificado) {
				if (dir == 0) {
					start = auxleft;
				}
				else if (dir == 1) {
					start = auxup;
				}
				else if (dir == 2) {
					start = auxright;
				}
				else if (dir == 3) {
					start = auxdown;
				}
			}
		}
		if ((start->getx() == destinationx) && (start->gety() == destinationy)) {
		    ended = true;
		}

		notcompleted = false;


		if (notexplored_.size() == 0) {  
			ended = true;
			notcompleted = true;
		}

    } while(!ended);
    //Si no hay camino posible
    if (notcompleted) {
        COLOR_RED;
        cout << "No hay camino posible" << endl;
        COLOR_RESET;
    //Si hay camino meterlo en el vector de final path
    } else {
        bool owari = false;
        for (int i = 0; owari == false; i++) {
            fpath_.push_back(start);
            if ((start->getx() == street_.get_orgx() && (start->gety() == street_.get_orgy()))) {
                owari = true;
            } else {
                start = start->getpred();
            }
        }
    }
	time = clock() - time;
	cout << "CPU time: " << (float)time /CLOCKS_PER_SEC << " seconds" << endl;
	cout << "Generated nodes: " << generated_.size() << endl;
	if (fpath_.size() > 1) {
	cout << "Optimal path without counting I and F : " << fpath_.size() - 2 << endl;
	} else {
		cout << "No optimal path" << endl;
	}

}

void astar_t::perception(int x, int y) {

    char bloque = 219;
    string muro;
    muro.push_back(bloque);
    perception_[0] = 0;
    perception_[1] = 0;
    perception_[2] = 0;
    perception_[3] = 0;

    if ( x > 1 ) {
        perception_[0] = street_(x - 1,y) == muro ? 1 : 0; //O
    }
    if (y > 1) {
        perception_[1] = street_(x,y - 1) == muro ? 1 : 0; //N
    }
    if ( y < street_.get_columns() - 1) {
        perception_[3] = street_(x + 1,y) == muro ? 1 : 0; //S
    }
    if (x < street_.get_rows() - 1) {
         perception_[2] = street_(x,y + 1) == muro ? 1 : 0; //E
    }
   
}

void astar_t::path() {
    int x = 0;
    int y = 0;
    for (int i = fpath_.size() -1; i >= 0; i--) {

        x = fpath_[i]->getx();
        y = fpath_[i]->gety();
        street_.addPath(x,y);

    }
}
