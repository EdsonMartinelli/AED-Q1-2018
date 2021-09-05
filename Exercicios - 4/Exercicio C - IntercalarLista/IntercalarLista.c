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

struct Lista * mergeLists(struct Lista *, struct Lista *);
void inserirTemp( struct Lista * , int );




int main (){
    int val, n1,n2, q;
    char op;
    struct Lista l,k;
    scanf("%d", &q);
    for (;q>0;q--){
        scanf("%d", &n1);
        l =  criaLista();
        k =  criaLista();
        if (n1 != 0){
            for(; n1 > 0; n1--){
                scanf("%d", &val);
                inserir(&l,val);
            }
        }
        scanf("%d", &n2);
        if (n2 != 0){
            for(; n2 > 0; n2--){
                scanf("%d", &val);
                inserir(&k,val);
            }
        }
        struct Lista * resul = mergeLists(&l,&k);
        if(resul->inicio != NULL){
            mostrarL(*resul);
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

struct Lista * mergeLists(struct Lista * l, struct Lista * k){
    int achei;
    int repetido;
    struct Item * novo;
    struct Item * anterior;
    struct Item * atual;
    struct Item * cont = k->inicio;
    if(k->inicio ==  NULL){
        return l;
    }
    if(l->inicio ==  NULL){
        return k;
    }
    
    while(cont!=NULL){
        novo= novoItem(cont->item);
        anterior = NULL;
        atual = l->inicio;
        achei = 0;
        repetido = 0;
        while(atual != NULL && achei!=1){
            if (novo->item < atual->item){
                achei = 1;
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
        
        cont =  cont->prox;
    }
    
    return l;
    
}
