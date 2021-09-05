#include <stdio.h>
#include <stdlib.h>
struct Lista
{
    int * itens;
    int tamanho, fim;
};

struct Lista criaLista(int);
void inserir(struct Lista*,int);
void remover(struct Lista*);
void mostrarT(struct Lista);
void mostrarB(struct Lista);

int main (){
    int q, k, i = 0, val;
    char op;
    struct Lista l, v;
    
    scanf("%d", &q);
    l =  criaLista(q);
    while(scanf("\n%c %d",&op,&val)!=EOF){
        if(op=='E'){
            inserir(&l,val);
        }else if(op=='D'){
            remover(&l);
        }else if(op=='T'){
            mostrarT(l);
        }else if(op=='B'){
            mostrarB(l);
        }
    }
    return 0;
}

struct Lista criaLista(int n){
    struct Lista l;
    l.itens=(int*)malloc(n*sizeof(int));
    l.fim = -1;
    l.tamanho=n;
    return l;
}

void inserir(struct Lista *l,int chave){
    if(l->fim >= l->tamanho-1 ){
        return;
    }else{
        l->fim ++;
        l->itens[l->fim] = chave; 
    }
    
}

void remover(struct Lista *l){
    if(l->fim > -1){
       // printf("%d\n", l->itens[l->fim]);
        l->fim--;
    }else{
        return;
    }
}

void mostrarT(struct Lista l){
    if(l.fim > -1){
        int i;
        for(i=l.fim; i >= 0; i--){
            printf("%d\n", l.itens[i]);
        }
    }else{
        return;
    }
    
}

void mostrarB(struct Lista l){
    if(l.fim > -1){
        int i;
        for(i=0; i <= l.fim; i++){
            printf("%d\n", l.itens[i]);
        }
    }else{
        return;
    }
    
}