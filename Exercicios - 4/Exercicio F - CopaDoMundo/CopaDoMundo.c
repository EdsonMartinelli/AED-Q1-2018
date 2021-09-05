#include <stdio.h>
#include <stdlib.h>
struct Item
{
    char item;
    struct Item * prox;
};

struct Lista{
    struct Item * inicio;
    int quantidade;
};

struct Lista criaLista();
struct Item * novoItem(char);
void inserir( struct Lista *, char);
void mostrarL(struct Lista);
void remover( struct Lista * l , char chave);
void inserirtodos(struct Lista *);
struct Item * verificaresultado(struct Lista *, int, int,struct Item *);

int main (){
    int val1, val2, i;
    char op;
    struct Lista l;
    l = criaLista();
    inserirtodos(&l);
    struct Item * temp = l.inicio;
    for (i=0; i<15 ;i++){
        scanf("%d %d", &val1, &val2);
        temp =verificaresultado(&l, val1, val2, temp);
        if(temp == NULL){
            temp=l.inicio;
        }
    }
    mostrarL(l);
    return 0;
}

struct Lista criaLista(){
    struct Lista l;
    l.inicio=NULL;
    l.quantidade=0;
    return l;
    
}

struct Item * novoItem(char n){
    struct Item * i = (struct Item *) malloc (sizeof(struct Item));
    i->item=n;
    i->prox=NULL;
    return i;
}

void inserir( struct Lista * l , char chave){

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
            printf("%c\n", cont->item);
        }else{
            printf("%c ", cont->item);
        }
        
    }
}

void remover( struct Lista * l ,  char chave){
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

void inserirtodos(struct Lista * l){
    inserir(l,'A');
    inserir(l,'B');
    inserir(l,'C');
    inserir(l,'D');
    inserir(l,'E');
    inserir(l,'F');
    inserir(l,'G');
    inserir(l,'H');
    inserir(l,'I');
    inserir(l,'J');
    inserir(l,'K');
    inserir(l,'L');
    inserir(l,'M');
    inserir(l,'N');
    inserir(l,'O');
    inserir(l,'P');
}

struct Item * verificaresultado(struct Lista * l, int val1, int val2, struct Item * temp){
    struct Item * primeiro = temp;
    struct Item * segundo = temp->prox;
    if(val1<val2){
        remover(l,primeiro->item);
    }else if (val1>val2){
        remover(l,segundo->item);
    }
    temp = segundo->prox;
    return temp;
}