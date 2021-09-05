#include <stdio.h>
#include <stdlib.h>
struct Lista
{
    int * ra;
    char ** nomes;
    int tamanho, inicio,fim;
};

struct Lista criaLista(int);
void inserir(struct Lista*,int, char *);
void remover(struct Lista*);
void mostrarM(struct Lista l);
void mostrarR(struct Lista l);
char * copia(char*);

int main (){
    int q, i = 0, ra;
    char op;
    char * nome = ( char *) malloc (100*sizeof(char));
    struct Lista l;
    
    scanf("%d", &q);
    l =  criaLista(q);
    while(scanf("\n%c %d %s", &op, &ra, nome)!=EOF){
        if(op=='I'){
            inserir(&l, ra, nome);
        }else if ( op == 'A'){
            remover(&l);
        }else  if( op == 'M'){
            mostrarM(l);
        }else  if( op == 'R'){
            mostrarR(l);
        }else  if( op == 'Q'){
            if(l.fim==-1){
                printf("Quantidade: %d\n", l.fim-l.inicio);
            }else{
                printf("Quantidade: %d\n", l.fim-l.inicio+1);
            }
        }
    }
    return 0;
}

struct Lista criaLista(int n){
    struct Lista l;
    l.ra=(int*)malloc(n*sizeof(int));
    l.nomes = (char**)malloc(n*sizeof(char*));
    l.fim = -1;
    l.inicio = -1;
    l.tamanho=n;
    return l;
}

void inserir(struct Lista *l, int ra, char * nome){
    char * nomecopiado = copia(nome);
    if(l->fim >= l->tamanho-1 && l->inicio <= l->fim ){
        return;
    }
    if(l->inicio == -1 && l->fim == -1){
       l->fim = 0;
       l->ra[l->fim] = ra;
       l->nomes[l->fim] = nomecopiado;
       l->inicio = 0;
    }else{
       l->fim ++;
       l->ra[l->fim] = ra;
       l->nomes[l->fim] = nomecopiado ;
    }
}

void remover(struct Lista *l){
    if(l->inicio <= l->fim && l->inicio != -1){
        printf("[%d] %s\n", l->ra[l->inicio], l->nomes[l->inicio]);
        l->inicio ++;
    }    
    if(l->inicio > l->fim){
        l->fim = -1;
        l->inicio = -1;
    }
    
}

void mostrarM(struct Lista l){  
   // printf("TESTE M: %d %d ||\n", l.inicio, l.fim );
    int i;
    if(l.fim != -1){
        for(i=l.inicio; i<=l.fim; i++){
            printf("[%d] %s\n", l.ra[i], l.nomes[i]);
        }
    }else{
        return;
    }
    
}

void mostrarR(struct Lista l){
    //printf("TESTE R: %d %d ||\n", l.inicio, l.fim );
    int i;
    if(l.fim != -1){
        for(i=l.fim; i>=l.inicio; i--){
            printf("[%d] %s\n", l.ra[i], l.nomes[i]);
        }
    }
    else{
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
