
#include "funcos.h"


int main() {
    int opcion,tamano;
    bool game_running=true,running=true;
    while(game_running) {
        menu(opcion, tamano,game_running,running);
        vector<vector<int>> tablero(tamano, vector<int>(tamano));
        crea_matriz(tablero, tamano, opcion);
        while (running) {
            imprime_matriz(tablero, tamano);
            mueve_ficha(tablero, tamano);
            detecta_fichas(tablero, tamano, running);
        }
    }
    return 0;
}
