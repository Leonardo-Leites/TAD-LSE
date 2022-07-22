#include <stdio.h>
#include <stdlib.h>

#include "data.h"

ptLSE* cria_lista(void){
       return NULL;
}

ptLSE* preenche(ptLSE *ptLista, int num){
    ptLSE *data;
    ptLSE *aux = NULL; 
    ptLSE *ptELO = ptLista;

    data = (ptLSE *)malloc(sizeof(ptLSE));
    data->numero = num;

    while(ptELO != NULL){
        aux = ptELO;
        ptELO = ptELO->prox;
    }

    if(aux == NULL){
        data->prox = ptLista;
        ptLista = data;
    }else{
        data->prox = ptELO;
        aux->prox = data;
    }

    return ptLista;

}

ptLSE* insere(ptLSE *ptLista,  int num){
    ptLSE *novo, *novo2;       
    ptLSE *ptaux = ptLista;
    ptLSE *ant = NULL;

    novo = (ptLSE *)malloc(sizeof(ptLSE));
    novo->numero = num;

    if(ptLista == NULL){
        novo->prox = ptLista;
        ptLista = novo;
    }else{

        novo2 = (ptLSE *)malloc(sizeof(ptLSE));
        novo2->numero = num+1;

        for (ptaux=ptLista; ptaux!=NULL; ptaux=ptaux->prox){

            if(ptaux->numero ==num){
                novo->numero = num-1;
                novo->prox = ptaux;
                if(ant == NULL){  
                    ptLista = novo; 
                }else
                    ant->prox = novo;

                if(ptaux->prox != NULL){
                    novo2->prox = ptaux->prox;
                    ptaux->prox = novo2;
                }else{
                    ptaux->prox = novo2;
                    novo2->prox = NULL;      
                }
                return ptLista;
            }
            ant = ptaux;
        }

            ptaux = ptLista;
            ant = NULL;

            printf("\nO numero nao existe na lista...");

            ptLista = ptaux->prox;
            ant = ptLista;
            free(ptaux);

            for(ptaux=ptLista; ptaux!=NULL;ptaux=ptaux->prox){
                if(ptaux->prox == NULL){
                    free(ptaux);
                    ant->prox = NULL;
                    printf("\nLista atualizada!");
                    return ptLista; 
                }
                ant = ptaux;
            }       
    }

    return ptLista;
}

void imprime(ptLSE* lista){
    
     ptLSE* ptaux;

     if (lista == NULL){
        printf("lista vazia");
     }else{
        for (ptaux=lista; ptaux!=NULL; ptaux=ptaux->prox){
            printf("Numero %d \n",ptaux->numero);
        }
     }
}

ptLSE* destroi(ptLSE *ptLista){
    ptLSE *ptaux;
    while (ptLista != NULL){
        ptaux = ptLista;
        ptLista = ptLista->prox;
        free(ptaux);
    }
    free(ptLista);
    return NULL;
}