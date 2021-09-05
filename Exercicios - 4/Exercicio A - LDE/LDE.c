#include <stdio.h>
#include <stdlib.h>
struct Item
{
    int item;
    struct Item * prox;
};

struct Lista{
    struct Item * inicio;
    int quantidade;
};

struct Lista criaLista();
void inserir( struct Lista *, int);
struct Item * novoItem(int);
void inserir( struct Lista *, int);
void mostrarL(struct Lista);
int buscarI(struct Lista, int);
void remover( struct Lista *, int);


int main (){
    int val;
    char op;
    struct Lista l;
    l =  criaLista();
    while(scanf("\n%c", &op)!= EOF){
        if( op == 'I'){
            scanf("%d", &val);
            inserir(&l,val);
        }else if( op == 'R') {
            scanf("%d", &val);
            remover(&l,val);
        }else if(op == 'B'){
            scanf("%d", &val);
            if(buscarI(l,val)==1? printf("SIM\n") : printf("NAO\n"));
        }else if(op == 'L'){
            mostrarL(l);
        }
    }
    return 0;
}

struct Lista criaLista(){
    struct Lista l;
    l.inicio=NULL;
    l.quantidade=0;
    return l;
    
}

struct Item * novoItem(int n){
    struct Item * i = (struct Item *) malloc (sizeof(struct Item));
    i->item=n;
    i->prox=NULL;
    return i;
}

void inserir( struct Lista * l , int chave){
    int achei = 0;
    struct Item * novo = novoItem(chave);
    struct Item * anterior = NULL;
    struct Item * atual = l->inicio;
    while(atual != NULL && achei!=1){
        if (novo->item < atual->item){
            achei = 1;
        }else if(novo->item == atual->item ){
            return;
        }else{
            anterior = atual;
            atual = atual->prox;
        }
    }
    if (anterior == NULL){
        l->inicio= novo;
    }else {
        anterior->prox = novo;
    }
    novo->prox = atual;
    l->quantidade++;
}

void mostrarL(struct Lista l){// TEM ERRO;
    struct Item * cont;
    for(cont = l.inicio; cont != NULL; cont = cont->prox){
        if(cont->prox==NULL){
            printf("%d\n", cont->item);
        }else{
            printf("%d ", cont->item);
        }
        
    }
}
int buscarI(struct Lista l, int chave){
    struct Item * cont;
    int achei = 0;
    for(cont = l.inicio; cont != NULL && achei!=1; cont = cont->prox){
        if(cont->item == chave ){
            achei = 1;
        }
    }
    return achei;
}

void remover( struct Lista * l , int chave){
    int achei = 0;
    struct Item * anterior = NULL;
    struct Item * atual = l->inicio;
    while(atual != NULL && achei!=1){
        if (chave == atual->item){
            achei = 1;
        }else{
            anterior = atual;
            atual = atual->prox;
        }
    }
    if(achei == 1){
        if (anterior == NULL){
            l->inicio= atual->prox;
        }else {
            anterior->prox = atual->prox;
        }
        free(atual);
        l->quantidade--;
    }
    
    
}
