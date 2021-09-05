#include <stdio.h>
#include <stdlib.h>

struct Lista{
    int * vetor;
    int tamanho;
};
struct Lista criaLista(int);
void Imprime(int *, int, int);
int filhoDir(int);
int filhoEsq(int);
int pai(int);
void Peneirar(int *, int, int);
int ultimoPai(struct Lista);
void Heap(struct Lista);

int main(){
    int tamanho, i;
    struct Lista l;
    while(1){
        scanf("%d", &tamanho);
        if(tamanho == 0 ){
            break;
        }
        l = criaLista(tamanho);
        for(i = 0; i < tamanho; i++){
            scanf("%d", &l.vetor[i]);
        }
        Heap(l);
        Imprime(l.vetor,0,l.tamanho-1);
    }
    return 0;
    
}

struct Lista criaLista(int tamanho){
    struct Lista l;
    l.vetor =  (int * ) malloc ( (tamanho) * sizeof( int ));
    l.tamanho = tamanho;
    return l;
}

int filhoDir(int i){
    return (2 * i) + 1;
}
int filhoEsq(int i){
    return (2 * i) + 2;
}

int pai(int i){
    return (i - 1) / 2;
}

int ultimoPai(struct Lista l){
    return (l.tamanho - 1) / 2;
}

void Peneirar(int * vetor, int indice, int ultInd){
    int indMaior = indice;
    int indEsq = filhoEsq(indice);
    int indDir = filhoDir(indice);
    int temp;
    
    if(indEsq <= ultInd && vetor[indEsq] > vetor[indMaior]){
        indMaior = indEsq;
    }
    if(indDir <= ultInd && vetor[indDir] > vetor[indMaior]){
        indMaior = indDir;
    }
    if(indMaior != indice){
        temp = vetor [indice];
        vetor[indice] = vetor[indMaior];
        vetor[indMaior] = temp;
        Peneirar(vetor,indMaior,ultInd);
    }
}

void Heap(struct Lista l){
    int i;
    for(i = ultimoPai(l); i >= 0; i--){
        Peneirar(l.vetor, i, (l.tamanho -1));
    }
}
  


void Imprime(int * vetor, int inicio, int final){
    int i;
    for( i = inicio; i <= final; i++){
        (i == final ? printf("%d\n", vetor[i]) : printf("%d ", vetor[i])  );
    }
    
}

