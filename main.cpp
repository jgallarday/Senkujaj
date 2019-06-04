#include "funcos.h"


int main() {
   int opcion,tamano;
   bool running=true;
   menu(opcion,tamano);
   vector<vector<int>>tablero(tamano, vector<int>(tamano));
   crea_matriz(tablero,tamano,opcion);
   while(running) {
       imprime_matriz(tablero, tamano);
       mueve_ficha(tablero, tamano);
       detecta_fichas(tablero, tamano, running);
   }
   return 0;
   }
