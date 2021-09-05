#include <stdio.h>
#include <stdlib.h>

struct Lista{
    int * vetor;
    int tamanho1;
    int tamanho2;
};
struct Lista criaLista(int, int);
int * Intercala(struct Lista);
void Imprime(int *, int );

int main(){
    int tamanho1, tamanho2, i;
    struct Lista l;
    scanf("%d %d", &tamanho1, &tamanho2);
    l = criaLista(tamanho1,tamanho2);
    for(i = 0; i < tamanho1+tamanho2; i++){
        scanf("%d", &l.vetor[i]);
    }
    Imprime(Intercala(l), (l.tamanho1+l.tamanho2));
    return 0;
    
}

struct Lista criaLista(int tamanho1, int tamanho2){
    struct Lista l;
    l.vetor =  (int * ) malloc ( (tamanho1+tamanho2) * sizeof( int ));
    l.tamanho1 = tamanho1;
    l.tamanho2 = tamanho2;
    return l;
}

int * Intercala(struct Lista  l){
    int * vetorAux = (int * ) malloc ( (l.tamanho1+l.tamanho2) * sizeof( int ));
    int i, p1 = 0, p2 = l.tamanho1;
    for(i = 0; i < l.tamanho1+l.tamanho2; i++){
        if(p1 >= l.tamanho1){
            vetorAux[i] = l.vetor[p2];
            p2++;
        }else if(p2 > l.tamanho1+l.tamanho2-1){
            vetorAux[i] = l.vetor[p1];
            p1++;
        }else{
            if(l.vetor[p1] <= l.vetor[p2]){
                vetorAux[i] = l.vetor[p1];
                p1++;
            }else{
                vetorAux[i] = l.vetor[p2];
                p2++;
            }
        }
    }
    return vetorAux;
}

void Imprime(int * vetor, int tamanho){
    int i;
    for( i = 0; i < tamanho; i++){
        printf("%d\n", vetor[i]);
    }
    
}


