#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Lista{
    char * vetor;
};
struct Lista criaLista();
void InsertionSort(struct Lista);
void Imprime(struct Lista, int , int);

int main(){
    int i, numero;
    struct Lista l;
    l = criaLista();
    while(scanf("%s", l.vetor)!=EOF){
        InsertionSort(l);
        l = criaLista();
    }
    return 0;
    
}

struct Lista criaLista(){
    struct Lista l;
    l.vetor = (char *) malloc (100000*sizeof(char));
    return l;
}

void InsertionSort(struct Lista l){
    int i, k, tamanho = 0, j = 0;
    char temp;
    while (l.vetor[j]!='\0'){
        tamanho++;
        j++;
    }
    for(i = 1; i < tamanho; i++){
        for(k = i; k > 0; k--){
            if(l.vetor[k] < l.vetor[k-1] ){
                temp = l.vetor[k-1];
                l.vetor[k-1] = l.vetor[k];
                l.vetor[k] = temp;
            }
        }
    }
     Imprime(l,0,tamanho);

}

void Imprime(struct Lista l, int inicio, int final){
    int i;
    for(i = inicio; i < final; i++){
        if(i ==  final-1){
            printf("%c\n", l.vetor[i]);
        }else{
            printf("%c", l.vetor[i]);
        }
        
    }
}