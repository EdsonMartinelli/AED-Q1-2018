#include <stdio.h>
#include <stdlib.h>

struct Lista{
    int ** matriz;
    int tamanholinha;
    int tamanhocoluna;
};
struct Lista criaLista(int, int);
void OrdenaStrings(struct Lista *);
void Imprime(struct Lista);
int * copia(int * nome, int tamanho);

int main(){
    int i, j, linha, coluna;
    int * vetor =  (int * ) malloc ( coluna * sizeof( int ));
    struct Lista l;
    scanf("%d %d", &linha, &coluna);
    l = criaLista(linha,coluna);
    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            scanf("%d", &vetor[j]);
        }
        int * copiavetor = copia(vetor, coluna);
        l.matriz[i]= copiavetor;
    }
    OrdenaStrings(&l);
    return 0;
    
}

struct Lista criaLista(int linha, int coluna){
    struct Lista l;
    l.matriz =  (int ** ) malloc ( linha * sizeof( int * ));
    l.tamanholinha = linha;
    l.tamanhocoluna = coluna;
    return l;
}

void OrdenaStrings(struct Lista * l){
    int i, w, j, temp;
    for(j = 0; j < l->tamanhocoluna; j++){
        for(i = l->tamanholinha-1; i > 0; i--){
            for(w = 0; w < i; w++){
                if(l->matriz[w+1][j] < l->matriz[w][j]){
                    temp = l->matriz[w][j];
                    l->matriz[w][j] = l->matriz[w+1][j];
                    l->matriz[w+1][j] = temp;
                }
            }
        }
    }
    
    Imprime(*l);
}

void Imprime(struct Lista l){
    int i, j;
    for(j = 0; j <l.tamanholinha ; j++){
        for(i = 0; i < l.tamanhocoluna; i++){
            if(i ==  l.tamanhocoluna-1){
                printf("%d\n", l.matriz[j][i]);
            }else{
                printf("%d ", l.matriz[j][i]);
            }
        }
    }
}


int * copia(int * nome, int tamanho){
    int * copiadovetor = (int *) malloc (tamanho*sizeof(int));
    int x=0;
    for (; x < tamanho; x++){
        copiadovetor[x] = nome[x]; 
    }
    return copiadovetor;
}