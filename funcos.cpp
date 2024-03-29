#include "funcos.h"

void menu(int & opcion,int & tamano,bool & game_running, bool & running)
{
    do{
        std::cout<<"Bienvenido a nuestro proyecto final"<<endl;
        cout<<"Este es el juego Senku"<<endl;
        cout<<"Por favor, seleccione una opción"<<endl;
        cout<<"1) Estilo alemán"<<endl;
        cout<<"2) Estilo Inglés"<<endl;
        cout<<"3) Estilo Diamante"<<endl;
        cout<<"0) salir del programa"<<endl;
        cout<<"Por favor, seleccione una opción : ";
        cin>>opcion;
        cout<<endl;


        if (opcion == 1 || opcion == 3) {
            tamano = 9;
            break;
        }
        if (opcion == 2) {
            tamano = 7;
            break;
        }
        if(opcion == 0)
        {
            cout<<endl<<"Hasta luego"<<endl;
            game_running= false;
            running= false;
        }}while(game_running== true);

}

void crea_matriz(vector< vector< int > >& tablero,unsigned int tamano,unsigned int opcion)
{
    if(opcion==1)
    {
        tablero = {{9, 9, 9, 0, 0, 0, 9, 9, 9},
                   {9, 9, 9, 0, 0, 0, 9, 9, 9},
                   {9, 9, 9, 0, 0, 0, 9, 9, 9},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {9, 9, 9, 0, 0, 0, 9, 9, 9},
                   {9, 9, 9, 0, 0, 0, 9, 9, 9},
                   {9, 9, 9, 0, 0, 0, 9, 9, 9}};
    }
    if(opcion==2)
    {
        tablero = {{9, 9, 0, 0, 0, 9, 9},
                   {9, 9, 0, 0, 0, 9, 9},
                   {0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 1, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0},
                   {9, 9, 0, 0, 0, 9, 9},
                   {9, 9, 0, 0, 0, 9, 9}};
    }
    if(opcion==3)
    {
        tablero={
                {
                        9,9,9,9,0,9,9,9,9},
                {
                        9,9,9,0,0,0,9,9,9},
                {
                        9,9,0,0,0,0,0,9,9},
                {
                        9,0,0,0,0,0,0,0,9},
                {
                        0,0,0,0,1,0,0,0,0},
                {
                        9,0,0,0,0,0,0,0,9},
                {
                        9,9,0,0,0,0,0,9,9},
                {
                        9,9,9,0,0,0,9,9,9},
                {
                        9,9,9,9,0,9,9,9,9}};
    }
}

void imprime_matriz(vector< vector< int > >& tablero, unsigned int tamano)
{
    int contador=1;
    if (tamano==9)
        cout<<"   1  2  3  4  5  6  7  8  9"<<endl;
    if (tamano==7)
        cout<<"   1  2  3  4  5  6  7"<<endl;
    for(int f=0;f<tamano;f++)
    {
        cout<<contador<<" ";
        contador++;
        for(int c=0;c<tamano;c++)
        {
            if (tablero[f][c]==9)
                cout<<"   ";
            if (tablero[f][c]==0)
                cout<<" o ";
            if (tablero[f][c]==1)
                cout<<" + ";


        }
        cout<<endl;
    }
}

void mueve_ficha(vector<vector<int>>& tablero, int tamano)
{
    int f1,c1,f2,c2;
    do{
        do{
            cout<<"De la fila de la ficha a mover : ";
            cin>>f1;
            f1-=1;
            if(f1>tamano-1||f1<0)
                cout<<endl<<"fila invalida"<<endl;
        }while(f1>tamano-1||f1<0);
        do{
            cout<<"De la columna de la ficha a mover : ";
            cin>>c1;
            c1-=1;
            if(c1>tamano-1||c1<0)
                cout<<endl<<"columna invalida"<<endl;
        }while(c1>tamano-1||c1<0);
        if(tablero[f1][c1]!=0)
            cout<<endl<<"Debe seleccionar una ficha"<<endl;
    }while(tablero[f1][c1]==9||tablero[f1][c1]==1);

    do{
        do{
            cout<<"De la fila del espacio disponible : ";
            cin>>f2;
            f2-=1;
            if(f2>tamano-1||f2<0)
                cout<<endl<<"fila invalida"<<endl;
        }while(f2>tamano-1||f2<0);
        do{
            cout<<"De la columna del espacio disponible : ";
            cin>>c2;
            c2-=1;
            if(c2>tamano-1||c2<0)
                cout<<endl<<"columna invalida"<<endl;
        }while(c2>tamano-1||c2<0);
        if(tablero[f2][c2]!=1)
            cout<<endl<<"Debe seleccionar un espacio vacio"<<endl;
    }while(tablero[f2][c2]==9||tablero[f2][c2]==0);

    if(f1!=0&&f1!=tamano-1&&c1!=0&&c1!=tamano-1)
    {
        
        
    if (f1+2==f2&&c1==c2)
    {
        if(tablero[f1+1][c1]==0) {
            tablero[f1][c1] = 1;
            tablero[f1 + 1][c1] = 1;
            tablero[f1 + 2][c1] = 0;
        }

    }
    else if (f1-2==f2&&c1==c2)
    {
        if(tablero[f1-1][c1]==0) {
            tablero[f1][c1]=1;tablero[f1-1][c1]=1;tablero[f1-2][c1]=0;
        }
    }
    else if (c1+2==c2&&f1==f2)
    {
        if(tablero[f1][c1+1]==0) {
            tablero[f1][c1]=1;tablero[f1][c1+1]=1;tablero[f1][c1+2]=0;
        }
    }
    else if (c1-2==c2&&f1==f2)
    {
        if(tablero[f1][c1-1]==0) {
            tablero[f1][c1]=1;tablero[f1][c1-1]=1;tablero[f1][c1-2]=0;
        }
    }
    else cout<<endl<<"Trataste de hacer una jugada invalida"<<endl;
}

else if (f1==0&&c1==0)
{
     if (f1+2==f2&&c1==c2)
    {
        if(tablero[f1+1][c1]==0) {
            tablero[f1][c1] = 1;
            tablero[f1 + 1][c1] = 1;
            tablero[f1 + 2][c1] = 0;
        }

     }
    else if (c1+2==c2&&f1==f2)
    {
        if(tablero[f1][c1+1]==0) {
            tablero[f1][c1]=1;tablero[f1][c1+1]=1;tablero[f1][c1+2]=0;
        }
    }
    else cout<<endl<<"Trataste de hacer una jugada invalida"<<endl;
}
else if (f1==0&&c1==tamano-1)
{
     if (f1+2==f2&&c1==c2)
    {
        if(tablero[f1+1][c1]==0) {
            tablero[f1][c1] = 1;
            tablero[f1 + 1][c1] = 1;
            tablero[f1 + 2][c1] = 0;
        }

    }
    else if (c1-2==c2&&f1==f2)
    {
        if(tablero[f1][c1-1]==0) {
            tablero[f1][c1]=1;tablero[f1][c1-1]=1;tablero[f1][c1-2]=0;
        }
    }
    else cout<<endl<<"Trataste de hacer una jugada invalida"<<endl;
}
else if (f1==tamano-1&&c1==0)
{
    if (f1-2==f2&&c1==c2)
    {
        if(tablero[f1-1][c1]==0) {
            tablero[f1][c1]=1;tablero[f1-1][c1]=1;tablero[f1-2][c1]=0;
        }
    }
    else if (c1+2==c2&&f1==f2)
    {
        if(tablero[f1][c1+1]==0) {
            tablero[f1][c1]=1;tablero[f1][c1+1]=1;tablero[f1][c1+2]=0;
        }
    }
    else cout<<endl<<"Trataste de hacer una jugada invalida"<<endl;
}
else if (f1==tamano-1&&c1==tamano-1)
{
    if (f1-2==f2&&c1==c2)
    {
        if(tablero[f1-1][c1]==0) {
            tablero[f1][c1]=1;tablero[f1-1][c1]=1;tablero[f1-2][c1]=0;
        }
    }
    else if (c1-2==c2&&f1==f2)
    {
        if(tablero[f1][c1-1]==0) {
            tablero[f1][c1]=1;tablero[f1][c1-1]=1;tablero[f1][c1-2]=0;
        }
    }
    else cout<<endl<<"Trataste de hacer una jugada invalida"<<endl;
}
else if (f1==0)
{
     if (f1+2==f2&&c1==c2)
    {
        if(tablero[f1+1][c1]==0) {
            tablero[f1][c1] = 1;
            tablero[f1 + 1][c1] = 1;
            tablero[f1 + 2][c1] = 0;
        }

    }
    else if (c1+2==c2&&f1==f2)
    {
        if(tablero[f1][c1+1]==0) {
            tablero[f1][c1]=1;tablero[f1][c1+1]=1;tablero[f1][c1+2]=0;
        }
    }
    else if (c1-2==c2&&f1==f2)
    {
        if(tablero[f1][c1-1]==0) {
            tablero[f1][c1]=1;tablero[f1][c1-1]=1;tablero[f1][c1-2]=0;
        }
    }
    else cout<<endl<<"Trataste de hacer una jugada invalida"<<endl;
}
else if (f1==tamano-1)
{
 if (f1-2==f2&&c1==c2)
    {
        if(tablero[f1-1][c1]==0) {
            tablero[f1][c1]=1;tablero[f1-1][c1]=1;tablero[f1-2][c1]=0;
        }
    }
    else if (c1+2==c2&&f1==f2)
    {
        if(tablero[f1][c1+1]==0) {
            tablero[f1][c1]=1;tablero[f1][c1+1]=1;tablero[f1][c1+2]=0;
        }
    }
    else if (c1-2==c2&&f1==f2)
    {
        if(tablero[f1][c1-1]==0) {
            tablero[f1][c1]=1;tablero[f1][c1-1]=1;tablero[f1][c1-2]=0;
        }
    }
    else cout<<endl<<"Trataste de hacer una jugada invalida"<<endl;
}
else if (c1==0)
{
     if (f1+2==f2&&c1==c2)
    {
        if(tablero[f1+1][c1]==0) {
            tablero[f1][c1] = 1;
            tablero[f1 + 1][c1] = 1;
            tablero[f1 + 2][c1] = 0;
        }

    }
    else if (f1-2==f2&&c1==c2)
    {
        if(tablero[f1-1][c1]==0) {
            tablero[f1][c1]=1;tablero[f1-1][c1]=1;tablero[f1-2][c1]=0;
        }
    }
    else if (c1+2==c2&&f1==f2)
    {
        if(tablero[f1][c1+1]==0) {
            tablero[f1][c1]=1;tablero[f1][c1+1]=1;tablero[f1][c1+2]=0;
        }
    }
    else cout<<endl<<"Trataste de hacer una jugada invalida"<<endl;
}
else if (c1==tamano-1)
{
     if (f1+2==f2&&c1==c2)
    {
        if(tablero[f1+1][c1]==0) {
            tablero[f1][c1] = 1;
            tablero[f1 + 1][c1] = 1;
            tablero[f1 + 2][c1] = 0;
        }

    }
    else if (f1-2==f2&&c1==c2)
    {
        if(tablero[f1-1][c1]==0) {
            tablero[f1][c1]=1;tablero[f1-1][c1]=1;tablero[f1-2][c1]=0;
        }
    }
    else if (c1-2==c2&&f1==f2)
    {
        if(tablero[f1][c1-1]==0) {
            tablero[f1][c1]=1;tablero[f1][c1-1]=1;tablero[f1][c1-2]=0;
        }
    }
    else cout<<endl<<"Trataste de hacer una jugada invalida"<<endl;
}}


void detecta_fichas(vector<vector<int>>& tablero, int tamano, bool& running)
{
    int cont_victoria=0,cont_derrota=0;
    for(int f=0;f<tamano;f++)
    {
        for(int c=0;c<tamano;c++)
        {
            if (tablero[f][c]==0)
            {
                cont_victoria++;
                if(f!=0&&f!=tamano-1&&c!=0&&f!=tamano-1)
                {
                    if (tablero[f + 1][c] == 0 || tablero[f - 1][c] == 0 || tablero[f][c + 1] == 0 ||
                        tablero[f][c - 1] == 0)
                        cont_derrota++;
                }
                //Esquinas
                if (f==0&&c==0)
                {if (tablero[f + 1][c] == 0|| tablero[f][c+1] == 0)
                        cont_derrota++;
                }

                if (f==0&&c==tamano-1)
                {if (tablero[f - 1][c] == 0|| tablero[f][c - 1] == 0)
                        cont_derrota++;}

                if (f==tamano-1&&c==0)
                {if (tablero[f - 1][c] == 0|| tablero[f][c + 1] == 0)
                        cont_derrota++;}

                if (f==tamano-1&&c==tamano-1)
                {if (tablero[f - 1][c] == 0|| tablero[f][c - 1] == 0)
                        cont_derrota++;}
                //Bordes
                if (f==0&&c!=0&&c!=tamano-1)
                {if (tablero[f + 1][c] == 0|| tablero[f][c + 1] == 0|| tablero[f][c - 1] == 0)
                        cont_derrota++;}

                if (f==tamano-1&&c!=0&&c!=tamano-1)
                {if (tablero[f - 1][c] == 0|| tablero[f][c + 1] == 0|| tablero[f][c - 1] == 0)
                        cont_derrota++;}

                if (c==0&&f!=0&&f!=tamano-1)
                {if (tablero[f+1][c] == 0|| tablero[f-1][c] == 0|| tablero[f][c+1] == 0)
                        cont_derrota++;}

                if (c==tamano-1&&f!=0&&f!=tamano-1)
                {if (tablero[f - 1][c] == 0|| tablero[f+1][c] == 0|| tablero[f][c - 1] == 0)
                        cont_derrota++;}


            }
        }
    }

    if(cont_victoria==1)
    {
        cout<<endl<<"Felicitaciones, ganaste!!!"<<endl;
        cout<<"WUUUUUU"<<endl;
        running=false;
    }
    else if(cont_derrota==0)
    {
        cout<<endl<<"GAME OVER"<<endl;
        running=false;
    }
}
