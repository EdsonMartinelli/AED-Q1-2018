#include <stdio.h>
#include <stdlib.h>
struct Item
{
    int item;
    struct Item * prox;
    struct Item * ant;
};

struct Lista{
    struct Item * inicio;
    struct Item * final;
    int quantidade;
};

struct Lista criaLista();
void inserir( struct Lista *, int);
struct Item * novoItem(int);
void inserir( struct Lista *, int);
void mostrarM(struct Lista);
void mostrarR(struct Lista);
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
        }else if( op == 'E') {
            scanf("%d", &val);
            remover(&l,val);
        }else if(op == 'M'){
            mostrarM(l);
        }else if(op == 'R'){
            mostrarR(l);
        }
    }
    return 0;
}

struct Lista criaLista(){
    struct Lista l;
    l.inicio=NULL;
    l.final=NULL;
    l.quantidade=0;
    return l;
    
}

struct Item * novoItem(int n){
    struct Item * i = (struct Item *) malloc (sizeof(struct Item));
    i->item=n;
    i->prox=NULL;
    i->ant=NULL;
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
        novo->ant = NULL;
        
        if (atual == NULL){
            l->final = novo;
        }else{
            atual->ant = novo;
            novo->prox = atual;
        }
        
    }else if (atual == NULL){
        anterior->prox = novo;
        novo->ant = anterior;
        l->final = novo;
    }else{
        anterior->prox = novo;
        novo->ant = anterior;
        atual->ant = novo;
    }
    novo->prox = atual;
    l->quantidade++;
}

void mostrarM(struct Lista l){
    struct Item * cont;
    if(l.inicio != NULL){
        for(cont = l.inicio; cont != NULL; cont = cont->prox){
            printf("%d ", cont->item);
        }
        printf("\n");
    }
    
}

void mostrarR(struct Lista l){
    struct Item * cont;
    if(l.final != NULL){
        for(cont = l.final; cont != NULL; cont = cont->ant){
            printf("%d ", cont->item);
        }
        printf("\n");
    }
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
           
            if (atual ->prox == NULL){
                l->final = NULL;
                l->inicio = NULL;
            }else{
                 l->inicio= atual->prox;
                 atual->prox->ant = NULL;
            }
            }else if (atual ->prox == NULL){
                atual->ant->prox = NULL;
                l->final = anterior;
            }else{
                anterior->prox = atual->prox;
                atual->prox->ant = anterior;
            }
            free(atual);
            l->quantidade--;
    }
}


