#include <stdio.h>
#include <stdlib.h>

struct Lista{
    int * vetor;
    int tamanho;
};
struct Lista criaLista(int);
int * Intercala(struct Lista , struct Lista );
void Imprime(int *, int );

int main(){
    int tamanho1, tamanho2, i1, i2, item;
    struct Lista l1, l2;
    scanf("%d", &tamanho1);
    l1 = criaLista(tamanho1);
    scanf("%d", &tamanho2);
    l2 = criaLista(tamanho2);
    for(i1 = 0; i1 < tamanho1; i1++){
        scanf("%d", &item);
        l1.vetor[i1] = item;
    }
    for(i2 = 0; i2 < tamanho2; i2++){
        scanf("%d", &item);
        l2.vetor[i2] = item;
    }
    Imprime(Intercala(l1, l2), (l1.tamanho+l2.tamanho));
    return 0;
    
}

struct Lista criaLista(int tamanho){
    struct Lista l;
    l.vetor =  (int * ) malloc ( tamanho * sizeof( int ));
    l.tamanho = tamanho;
    return l;
}

int * Intercala(struct Lista  l1, struct Lista  l2){
    int * vetorfinal = (int * ) malloc ( (l1.tamanho+l2.tamanho) * sizeof( int ));
    int i, p1 = 0, p2 = 0;
    for(i = 0; i < l1.tamanho+l2.tamanho; i++){
        if(p1 >= l1.tamanho){
            vetorfinal[i] = l2.vetor[p2];
            p2++;
        }else if(p2 >= l2.tamanho){
            vetorfinal[i] = l1.vetor[p1];
            p1++;
        }else{
            if(l1.vetor[p1] <= l2.vetor[p2]){
                vetorfinal[i] = l1.vetor[p1];
                p1++;
            }else{
                vetorfinal[i] = l2.vetor[p2];
                p2++;
            }
        }
    }
    return vetorfinal;
}

void Imprime(int * vetor, int tamanho){
    int i;
    for( i = 0; i < tamanho; i++){
        printf("%d\n", vetor[i]);
    }
    
}


