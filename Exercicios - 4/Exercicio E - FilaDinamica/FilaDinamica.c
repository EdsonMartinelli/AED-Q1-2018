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
void remover( struct Lista * );




int main (){
    int val;
    char op;
    struct Lista l;
    l = criaLista();
    while(scanf("\n%c",&op)!=EOF){
        if (op == 'E'){
            scanf("%d", &val);
            inserir(&l,val);
        }else if( op == 'D'){
            remover(&l);
        }else if(op == 'M'){
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
    struct Item * novo = novoItem(chave);
    struct Item * atual = l->inicio;
    if(atual != NULL){
        while(atual->prox != NULL ){
            atual = atual->prox;
        }
        atual->prox = novo;
    }else{
        l->inicio= novo;
    }
    l->quantidade++;
}

void mostrarL(struct Lista l){
    struct Item * cont;
    for(cont = l.inicio; cont != NULL; cont = cont->prox){
        if(cont->prox==NULL){
            printf("%d\n", cont->item);
        }else{
            printf("%d ", cont->item);
        }
        
    }
}

void remover( struct Lista * l ){
    struct Item * temp = l->inicio;
    if(temp!=NULL){
        l->inicio = l->inicio->prox;
        printf("<%d>\n", temp->item);
        free(temp);
    }
    
    
}


