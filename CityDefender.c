#include <stdlib.h>
#include <stdio.h>
#include "Cartas.h"
#include "Tablero.h"


Mano cartas;
int *cap; //capacidad del tablero
void ***tablero;
const Ds DisparoSimple = {1, 1};
const Dg DisparoGrande = {2, 9};
const Dl DisparoLineal = {3, 3}; //cambiar esta area


void inicializarTablero(int casillas){
    tablero= (void***)malloc(casillas * sizeof(void(**)));
    for( int i=0; i<casillas; i++ ){
        tablero[i]=(void **)malloc(casillas * sizeof(void(**))); //fila 
        for(int j=0; j<casillas;j++){ //columna
            tablero[i][j]= NULL;
        }
    }
}

void inicializarMazo(){
    cartas.carta=(void **)malloc(5* sizeof(void *));
    cartas.disponibles = 5; 
    for(int i=0; i<5;i++){
        cartas.carta[i] = malloc(sizeof(Ds));   
        *(Ds *)(cartas.carta[i])=DisparoSimple;
    }



}
void mostrarMazo(){
    int desocupadas= cartas.disponibles;
    for(int i=0; i<5; i++){
        Ds *cartaActual = (Ds* )(cartas.carta[i]);
printf("Carta %d: id = %d, area = %d\n", i+1, cartaActual->id, cartaActual->area);
    }
}
void mostrarTablero(){
    for(int i=0; i<*cap;i++){ //fila
        for(int j=0;j<*cap;j++){
            printf("| ");
        }
        printf("| \n");                   //columna
    }
}

int main(int argc, char const *argv[]){
    int tamaño=11;
    cap= &tamaño;
    inicializarTablero(tamaño);
    mostrarTablero();
    inicializarMazo();
    mostrarMazo();



    
    return 0;
}
