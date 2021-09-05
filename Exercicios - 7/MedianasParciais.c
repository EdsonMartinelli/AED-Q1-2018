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
int ultimoPai(int);
void Heap(int *, int);
void HeapSort(int *, int);

int main(){
    int tamanho, i;
    struct Lista l;
    scanf("%d", &tamanho);
    l = criaLista(tamanho);
    for(i = 0; i < tamanho; i++){
        scanf("%d", &l.vetor[i]);
        HeapSort(l.vetor, i);
        if((i+1)%2 != 0 ){
            printf("%.1lf\n", (double)l.vetor[ultimoPai(i)]);
        }else{
            printf("%.1lf\n", (l.vetor[ultimoPai(i)]+l.vetor[ultimoPai(i+1)])/(double)2);
        }
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

int ultimoPai(int ultInd){
    return ultInd / 2;
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

void Heap(int * vetor, int ultInd){
    int i;
    for(i = ultimoPai(ultInd); i >= 0; i--){
        Peneirar(vetor, i, ultInd);
    }
}

void HeapSort(int * vetor, int ultInd){
    int i, temp;
    for(i = ultInd; i >= 0; i--){
        Heap(vetor,i);
        temp = vetor[i];
        vetor[i] = vetor[0];
        vetor[0] = temp;
    }
}

void Imprime(int * vetor, int inicio, int final){
    int i;
    for( i = inicio; i <= final; i++){
        (i == final ? printf("%d\n", vetor[i]) : printf("%d ", vetor[i])  );
    }
    
}

