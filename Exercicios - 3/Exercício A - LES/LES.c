#include <stdio.h>
#include <stdlib.h>
struct Lista
{
    int * itens;
    int quantidade, tamanho;
};

struct Lista criaLista(int);
void inserir( struct Lista *, int);
int buscaBinaria(int *, int, int , int);
void remover(struct Lista *, int);
void mostrar(struct Lista);

int main (){
    int q, i, val;
    char op;
    struct Lista l;
    
    scanf("%d", &q);
    l =  criaLista(q);
    for(i = 0; i < q ; i++){
        scanf("\n%c %d", &op, &val);
        if( op == 'I'){
            inserir(&l,val);
        }else {
            remover(&l,val); 
        }
    }
    mostrar(l);
    return 0;
}

struct Lista criaLista(int n){
    struct Lista l;
    l.itens = ( int *) malloc ( n*sizeof(int));
    l.quantidade = 0;
    l.tamanho = n;
    return l;
    
}
void inserir( struct Lista * l , int chave){
    int i, j, achei = 0;
    i=0;
    while(i < l->quantidade && !achei){
        if(chave == l->itens[i]){
            return;
        }else if( chave < l->itens[i]){
            achei = 1;
        }else{
            i++;
        }
    }
    for(j=l->quantidade-1; j>=i; j--){
        l->itens[j+1] = l->itens[j];
    }
    l->itens[i] = chave;
    l->quantidade++;
}
int buscaBinaria(int*v, int e, int d, int x){
    int meio;
    while(e <= d){
        meio = (e + d)/2;
        if(v[meio] == x){
            return meio;
        }
        else if (v[meio] <x){
            e = meio+1;
        }
        else{
            d = meio-1;
        }
    }
    return -1;
    
}
void remover(struct Lista * l, int chave){
    int i = buscaBinaria(l->itens, 0, l->quantidade-1, chave), j;
    if(i != -1){
        for(j = i; j < l->quantidade; j++){
            l->itens[j] = l->itens[j+1];
        }
        l->quantidade--;
    }
    
}
void mostrar(struct Lista l){
    int i;
    for(i=0; i < l.quantidade; i++){
        printf("%d\n", l.itens[i]);
    }
}

