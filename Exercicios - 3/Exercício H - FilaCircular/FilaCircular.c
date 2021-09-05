#include <stdio.h>
#include <stdlib.h>
struct Lista
{
    int * itens;
    int tamanho, inicio,fim, nitens;
};

struct Lista criaLista(int);
void inserir(struct Lista*,int);
void remover(struct Lista*);

int main (){
    int q, val;
    char op;
    struct Lista l, v;
    
    scanf("%d", &q);
    l =  criaLista(q);
    while(scanf("\n%c %d",&op,&val)!=EOF){
        if(op=='E'){
            inserir(&l,val);
        }else if(op=='D'){
            remover(&l);
        }
    }
    return 0;
}

struct Lista criaLista(int n){
    struct Lista l;
    l.itens=(int*)malloc(n*sizeof(int));
    l.fim = 0;
    l.inicio = 0;
    l.nitens = 0;
    l.tamanho=n;
    return l;
}

void inserir(struct Lista *l,int chave){
    if(l->nitens < l->tamanho-1 ){
        if(l->fim == l->tamanho-1 ){
            //printf("%d na posição %d \n",chave,l->fim);
            l->itens[l->fim] = chave;
            l->fim=0;
            l->nitens++;
        }else{
           // printf("%d na posição %d \n",chave,l->fim);
            l->itens[l->fim] = chave;
            l->fim++;
            l->nitens++;
        }
    }else{
        //printf("Fila cheia\n");
    }
    
}

void remover(struct Lista *l){
    if(l->nitens > 0){
        printf("%d\n",l->itens[l->inicio]);
        if(l->inicio == l->tamanho-1 ){
            l->inicio=0;
            l->nitens--;
        }else{
            l->inicio++;
            l->nitens--;
        }
    }else{
       // printf("Fila vazia\n");
    }
    
}
