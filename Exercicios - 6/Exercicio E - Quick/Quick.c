#include <stdio.h>
#include <stdlib.h>

struct Lista{
    int * vetor;
    int tamanho;
};
struct Lista criaLista(int);
int Particiona(int *, int, int, int);
void Imprime(int *, int, int);
void quickSort(int *, int, int, int);

int main(){
    int tamanho, i, p;
    struct Lista l;
    scanf("%d ", &tamanho);
    l = criaLista(tamanho);
    for(i = 0; i < tamanho; i++){
        scanf("%d", &l.vetor[i]);
    }
    
   
    Imprime(l.vetor, 0, l.tamanho);
    quickSort(l.vetor, 0, tamanho - 1, tamanho);
    Imprime(l.vetor, 0, l.tamanho);
    
    return 0;
    
}

struct Lista criaLista(int tamanho){
    struct Lista l;
    l.vetor =  (int * ) malloc ( tamanho * sizeof( int ));
    l.tamanho = tamanho;
    return l;
}

int Particiona(int * vetor, int inicio, int final, int tamanho){
    int temp, pm = inicio - 1 , i;
    for(i = inicio; i < final; i++){
        if(vetor[i] <=  vetor[final]){
            pm++;
            temp = vetor[i];
            vetor[i] = vetor[pm];
            vetor[pm] = temp;
        }
        Imprime(vetor,0,tamanho);
    }
    temp = vetor[pm+1];
    vetor[pm+1] = vetor[final];
    vetor[final] = temp;
    Imprime(vetor,0,tamanho);
    return pm+1;
    
}

void quickSort(int * vetor, int inicio, int final, int tamanho) {
    int p;
    if(inicio < final)
    {
        p = Particiona(vetor, inicio, final, tamanho);
        quickSort(vetor, inicio, p-1, tamanho);
        quickSort(vetor, p+1, final, tamanho);
    }
}

void Imprime(int * vetor, int inicio, int final){
    int i;
    for( i = inicio; i < final; i++){
        (i == final - 1 ? printf("%d\n", vetor[i]) : printf("%d ", vetor[i])  );
    }
    
}


