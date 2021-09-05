#include <stdio.h>
#include <stdlib.h>
struct Lista
{
    int * itens;
    int tamanho, inicio,fim;
};

struct Lista criaLista(int);
void inserir(struct Lista*,int);
void remover(struct Lista*);

int main (){
    int q, k, i = 0, val;
    char op;
    struct Lista l, v;
    
    scanf("%d", &q);
    l =  criaLista(q);
    while(scanf("\n%c %d",&op,&val)!=EOF){
        if(op=='E'){
            inserir(&l,val);
            
        }else{
            remover(&l);
        }
    }
    return 0;
}

struct Lista criaLista(int n){
    struct Lista l;
    l.itens=(int*)malloc(n*sizeof(int));
    l.fim = -1;
    l.inicio = -1;
    l.tamanho=n;
    return l;
}

void inserir(struct Lista *l,int chave){
    
    if(l->fim >= l->tamanho-1 && l->inicio <= l->fim ){
        return;
    }
    if(l->inicio == -1 && l->fim == -1){
       l->fim = 0;
       l->itens[l->fim] = chave;
       l->inicio = 0;
    }else{
       l->fim ++;
       l->itens[l->fim] = chave; 
    }
}

void remover(struct Lista *l){
    if(l->inicio <= l->fim && l->inicio != -1){
        printf("%d\n", l->itens[l->inicio]);
        l->inicio ++;
    }
    if(l->inicio > l->fim){
        l->fim = -1;
        l->inicio = -1;
    }
}