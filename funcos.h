#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

#ifndef PROYECTO_MARIA_HILDA_MAURIZIO_FUNCOS_H
#define PROYECTO_MARIA_HILDA_MAURIZIO_FUNCOS_H






void menu(int & opcion,int & tablero,bool & game_running, bool & running);
void crea_matriz(vector< vector< int > >& tablero,unsigned int tamano,unsigned int opcion);
void imprime_matriz(vector< vector< int > >& tablero, unsigned int tamano);
void mueve_ficha(vector<vector<int>>& tablero, int tamano);
void detecta_fichas(vector<vector<int>>& tablero, int tamano, bool& running);


#endif //PROYECTO_MARIA_HILDA_MAURIZIO_FUNCOS_H
