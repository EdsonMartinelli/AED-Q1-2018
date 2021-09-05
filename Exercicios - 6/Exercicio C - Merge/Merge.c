#include <stdio.h>
#include <stdlib.h>

struct Lista{
    int * vetor;
    int tamanho;
};
struct Lista criaLista(int);
void Intercala(int *, int, int, int);
void Imprime(int *, int, int);
void mergeSort(int *, int , int, int);

int main(){
    int tamanho, i;
    struct Lista l;
    scanf("%d", &tamanho);
    l = criaLista(tamanho);
    for(i = 0; i < tamanho; i++){
        scanf("%d", &l.vetor[i]);
    }
    Imprime(l.vetor, 0, l.tamanho-1);
    mergeSort(l.vetor, 0, l.tamanho-1, l.tamanho);
    Imprime(l.vetor, 0, l.tamanho-1);
    return 0;
    
}

struct Lista criaLista(int tamanho){
    struct Lista l;
    l.vetor =  (int * ) malloc ( (tamanho) * sizeof( int ));
    l.tamanho = tamanho;
    return l;
}

void Intercala(int * vetor, int inicio, int meio, int final){
    
    int * vetorAux = (int * ) malloc ( (final - inicio + 1) * sizeof( int ));
    int i, p1 = inicio, p2 = meio;
    for(i = 0; i < final - inicio + 1; i++){
        if(p1 >= meio){
            vetorAux[i] = vetor[p2];
            p2++;
        }else if(p2 > final){
            vetorAux[i] = vetor[p1];
            p1++;
        }else{
            if(vetor[p1] <= vetor[p2]){
                vetorAux[i] = vetor[p1];
                p1++;
            }else{
                vetorAux[i] = vetor[p2];
                p2++;
            }
        }
    }
    for(i = inicio; i <= final; i++){
        vetor[i]=vetorAux[i-inicio];
    }

}

void mergeSort(int * vetor, int inicio, int final, int tamanho){
    int meio;
    if(inicio < final){
        meio = (final + inicio) / 2;
        mergeSort(vetor, inicio, meio, tamanho);
        mergeSort(vetor, meio+1, final, tamanho);
        Imprime(vetor, 0, tamanho-1);
        Intercala(vetor, inicio, meio+1, final);
    }
}

void Imprime(int * vetor, int inicio, int final){
    int i;
    for( i = inicio; i <= final; i++){
        (i == final ? printf("%d\n", vetor[i]) : printf("%d ", vetor[i])  );
    }
    
}

