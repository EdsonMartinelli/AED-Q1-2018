#include <stdio.h>
#include <stdlib.h>

struct Lista{
    int * vetor;
    int tamanho;
};
struct Lista criaLista(int);
void InsertionSort(struct Lista);
void Imprime(struct Lista, int , int);

int main(){
    int tamanho, item, i, numero;
    struct Lista l;
    scanf("%d", &tamanho);
    l = criaLista(tamanho);
    for(i = 0; i < l.tamanho; i++){
        scanf("%d", &item);
        l.vetor[i] = item;
    }
    InsertionSort(l);
    return 0;
    
}

struct Lista criaLista(int tamanho){
    struct Lista l;
    l.vetor = (int *) malloc (tamanho*sizeof(int));
    l.tamanho = tamanho;
    return l;
}

void InsertionSort(struct Lista l){
    int i, k, temp, quant = 0;
    for(i = 1; i < l.tamanho; i++){
        for(k = i; k > 0; k--){
            if(l.vetor[k] < l.vetor[k-1] ){
                temp = l.vetor[k-1];
                l.vetor[k-1] = l.vetor[k];
                l.vetor[k] = temp;
                quant ++ ;
            }
        }
    }
    printf("%d\n", quant);

}

void Imprime(struct Lista l, int inicio, int final){
    int i;
    for(i = inicio; i < final; i++){
        if(i ==  final-1){
            printf("%d\n", l.vetor[i]);
        }else{
            printf("%d ", l.vetor[i]);
        }
        
    }
}