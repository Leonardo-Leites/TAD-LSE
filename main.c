#include <stdio.h>

#include "data.h"

int main(void){

    
    ptLSE* l;
    int num;

    l = cria_lista();

    printf("\nInforme os numeros que deseja inserir na lista\n [Para parar informe 0]\n\n");

    do{
        printf("Numero: ");
        scanf("%d", &num);
            if(num == 0){}
            else
                l = preenche(l, num);
    }while(num != 0);

    printf("\nExibindo a lista...\n");
    imprime(l);

    printf("\n\nInforme um numero: ");
    scanf("%d", &num);

    l = insere(l, num);

    printf("\nExibindo a lista depois do insere...\n\n");
    imprime(l);

    printf("\nDestruindo a lista...");
    l = destroi(l);
    printf("\nExibindo a lista...\n\n");
    imprime(l);
}