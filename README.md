# Prácitca de Inteligencia artifical ULL
## Por Adrián Fleitas de la Rosa

Para compilar el programa o bien ejecutar make all(make clean borra los .o) o 
g++ -o astar zone.cpp node.cpp astar.cpp main.cpp y ejecutar
./astar inputfile donde inputfile es el fichero de entrada.
El fichero inputfile tiene este formato por líneas: (todo en formato numerico)
 fila columna
 i j (siendo estos indices la posicion i,j del punto inicial)
 numerodemuros
 i j (tantos i,j posiciones de muro como numero de muros, un i,j por línea)
 fi fj (siendo estos indices la posicion i,j del punto final)
 