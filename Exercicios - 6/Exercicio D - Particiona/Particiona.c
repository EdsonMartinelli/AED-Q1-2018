#include <stdio.h>
#include <stdlib.h>

struct Lista{
    int * vetor;
    int tamanho;
    int pivo;
};
struct Lista criaLista(int, int);
void Particiona(struct Lista);
void Imprime(int *, int );

int main(){
    int tamanho, i, p;
    struct Lista l;
    scanf("%d %d", &tamanho, &p);
    l = criaLista(tamanho,p);
    for(i = 0; i < tamanho; i++){
        scanf("%d", &l.vetor[i]);
    }
    Particiona(l);
    Imprime(l.vetor,l.tamanho);
    return 0;
    
}

struct Lista criaLista(int tamanho, int pivo){
    struct Lista l;
    l.vetor =  (int * ) malloc ( tamanho * sizeof( int ));
    l.tamanho = tamanho;
    l.pivo = pivo;
    return l;
}

void Particiona(struct Lista  l){
    int temp = l.vetor[l.tamanho-1], pm = -1 , i;
    l.vetor[l.tamanho-1] = l.vetor[l.pivo];
    l.vetor[l.pivo] = temp;
    for(i = 0; i < l.tamanho-1; i++){
        if(l.vetor[i] <=  l.vetor[l.tamanho-1]){
            pm++;
            temp = l.vetor[i];
            l.vetor[i] = l.vetor[pm];
            l.vetor[pm] = temp;
        }
    }
    temp = l.vetor[pm+1];
    l.vetor[pm+1] = l.vetor[l.tamanho-1];
    l.vetor[l.tamanho-1] = temp;
    
}

void Imprime(int * vetor, int tamanho){
    int i;
    for( i = 0; i < tamanho; i++){
        printf("%d\n", vetor[i]);
    }
    
}


