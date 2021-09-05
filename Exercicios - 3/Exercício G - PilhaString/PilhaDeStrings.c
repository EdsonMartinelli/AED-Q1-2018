#include <stdio.h>
#include <stdlib.h>
struct Lista
{
    char ** itens;
    int tamanho, fim;
};

struct Lista criaLista(int);
void inserir(struct Lista*,char*);
void remover(struct Lista*);
void mostrarT(struct Lista);
void mostrarX(struct Lista);
void mostrarB(struct Lista);
char * copia(char*);

int main (){
    int q;
    char * val =(char*)malloc(100*sizeof(char));
    char op;
    struct Lista l;
    
    scanf("%d", &q);
    l =  criaLista(q);
    while(scanf("\n%c",&op)!=EOF){
        if(op=='E'){
            scanf("%s",val);
            inserir(&l,val);
        }else if (op == 'D'){
            remover(&l);
        }else if (op == 'B'){
            mostrarB(l);
        }else if (op == 'X'){
            mostrarX(l);
        }else if (op == 'T'){
            mostrarT(l);
        }
        
    }
    return 0;
}

struct Lista criaLista(int n){
    struct Lista l;
    l.itens = (char**)malloc(n*sizeof(char*));
    l.fim = -1;
    l.tamanho = n;
    return l;
}

void inserir(struct Lista *l,char * chave){
    if(l->fim >= l->tamanho-1 ){
        return;
    }
    char* chavecopiada = copia(chave);
    l->fim ++;
    l->itens[l->fim] = chavecopiada; 
    
}

void remover(struct Lista *l){
    if(l->fim > -1){
        l->fim--;
    }else{
        return;
    }
}
void mostrarT(struct Lista l){
    if(l.fim > -1){
        printf("%s\n", l.itens[l.fim]);
    }else{
        return;
    }
    
}
void mostrarX(struct Lista l){
    if(l.fim > -1){
        int i;
        for(i=l.fim; i >= 0+1; i--){
            printf("%s ", l.itens[i]);
        }
        printf("%s\n", l.itens[0]);
    }else{
        return;
    }
    
}

void mostrarB(struct Lista l){
    if(l.fim > -1){
        int i;
        for(i=0; i <= l.fim-1; i++){
            printf("%s ", l.itens[i]);
        }
        printf("%s\n", l.itens[i]);
    }else{
        return;
    }
    
}

char * copia(char* nome){
    int i=0;
    while(nome[i]!='\0'){
        i++;
    }
    char * rafaws = (char *) malloc (100*sizeof(char));
    int x=0;
    for(; x<i;x++){
        rafaws[x] = nome[x]; 
    }
    rafaws[x]='\0';
    return rafaws;
}