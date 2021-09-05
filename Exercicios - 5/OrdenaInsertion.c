#include <stdio.h>
#include <stdlib.h>

struct Lista{
    int * vetor;
    int tamanho;
};
struct Lista criaLista(int);
int InsertionSort(struct Lista);
void Imprime(struct Lista);

int main(){
    int tamanho, item, i, quantidade;
    struct Lista l;
    scanf("%d", &tamanho);
    l = criaLista(tamanho);
    for(i = 0; i < l.tamanho; i++){
        scanf("%d", &item);
        l.vetor[i] = item;
    }
    quantidade = InsertionSort(l);
    if (quantidade == 0){
        printf("MELHOR CASO\n");
    }else if (quantidade == (tamanho*(tamanho-1))/2){
        printf("PIOR CASO\n");
    }else{
         printf("CASO ALEATORIO\n");
    }
        
    return 0;
    
}

struct Lista criaLista(int tamanho){
    struct Lista l;
    l.vetor = (int *) malloc (tamanho*sizeof(int));
    l.tamanho = tamanho;
    return l;
}

int InsertionSort(struct Lista l){
    int i,k,temp;
    int quantidade = 0;
    Imprime(l);
    for(i = 1; i < l.tamanho; i++){

        for(k = i; k > 0; k--){
            if(l.vetor[k] < l.vetor[k-1] ){
                temp = l.vetor[k-1];
                l.vetor[k-1] = l.vetor[k];
                l.vetor[k] = temp;
                quantidade ++;
                Imprime(l);
            }
        }
        
    }
    Imprime(l);
    printf ("Trocas:%d\n", quantidade);
    return quantidade;
}

void Imprime(struct Lista l){
    int i;
    for(i = 0; i < l.tamanho; i++){
        if(i ==  l.tamanho-1){
            printf("%d\n", l.vetor[i]);
        }else{
            printf("%d ", l.vetor[i]);
        }
        
    }
}