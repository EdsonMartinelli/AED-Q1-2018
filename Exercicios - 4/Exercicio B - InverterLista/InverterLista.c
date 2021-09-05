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


struct Lista * reverseList(struct Lista *);


int main (){
    int val, n, q;
    char op;
    struct Lista l;
    scanf("%d", &q);
    for (;q>0;q--){
        scanf("%d", &n);
        if (n != 0){
            l =  criaLista();
            for(;n>0;n--){
                scanf("%d", &val);
                inserir(&l,val);
            }
            struct Lista * reverso = reverseList(&l);
            mostrarL(*reverso);
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

struct Lista * reverseList(struct Lista * l){
    struct Item * temp = l->inicio;
    struct Item * temp2 = l->inicio->prox;
    l->inicio->prox = NULL;
    while (temp2 != NULL){
        temp = l->inicio;
        l->inicio= temp2;
        temp2 = l->inicio->prox;
        l->inicio->prox=temp;
    }
    return l;
}

