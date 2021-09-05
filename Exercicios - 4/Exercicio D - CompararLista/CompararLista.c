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

int compareLists(struct Lista *, struct Lista *);




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
        int resul = compareLists(&l,&k);
        printf("%d\n", resul);
        
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


int compareLists(struct Lista * l, struct Lista * k){
    if (l->inicio == NULL || k->inicio == NULL){
        return 0;
    }
    if (l->quantidade == k->quantidade){
        struct Item * cont;
        struct Item * cont2;
        for (cont = l->inicio, cont2 = k->inicio; cont != NULL && cont2!=NULL; cont = cont->prox, cont2 = cont2->prox){
            if (cont->item != cont2->item){
                return 0;
            }
        }
        return 1;
    }else{
        return 0;
    }
    
}