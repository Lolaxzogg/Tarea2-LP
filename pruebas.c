#include <stdio.h>

int *global;

void mostrar(){
    printf("%d", *global);
}

int main(){
    int a;
    a=2;
    global= &a;
    a=2;
    mostrar();
    a = 3;
    mostrar();
    a=5;
    mostrar();
    int numero;
    printf("ingrese un numero: ");
    scanf("%d", &numero);
    printf("%d", numero);
    return 0;
}