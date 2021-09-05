#include <stdio.h>
#include <stdlib.h>
struct Lista
{
    int * itens;
    int quant, tamanho;
};

struct Lista criaLista(int);
void inserir(struct Lista*,int);
int buscaBinaria(int *, int,int,int);
void remover(struct Lista*,int);
void compara(struct Lista,struct Lista);

int main (){
    int q, k, i = 0, val;
    char op;
    struct Lista l, v;
    
    scanf("%d %d", &q, &k);
    l =  criaLista(q);
    v =  criaLista(k);
    for(; i < q ; i++){
        scanf("\n%c %d",&op,&val);
        if(op=='I'){
            inserir(&l,val);
        }else{
            remover(&l,val);
        }
    }
    for(i = 0; i < k ; i++){
        scanf("\n%c %d",&op,&val);
        if(op=='I'){
            inserir(&v,val);
        }else{
            remover(&v,val);
        }
    }
    compara(l,v);
    return 0;
}

struct Lista criaLista(int n){
    struct Lista l;
    l.itens=(int*)malloc(n*sizeof(int));
    l.quant=0;
    l.tamanho=n;
    return l;
}

void inserir(struct Lista *l,int chave){
    int i,j,achei=0;
    
    i=0;
    while(i<l->quant && !achei){
        if(chave==l->itens[i]){
            return;
        }else if(chave<l->itens[i]){
            achei=1;
        }else{
            i++;   
        }
    }
    for(j=l->quant-1;j>=i;j--){
        l->itens[j+1]=l->itens[j];
    }
    l->itens[i]=chave;
    l->quant++;
}

int buscaBinaria(int *v, int e,int d,int x){
    int meio;
    while(e<=d){
        meio=(e+d)/2;
        if(v[meio]==x){
            return meio;
        }else if(v[meio] < x){
            e=meio+1;
        }else{
            d=meio-1;
        }
    }
    return -1;
}

void remover(struct Lista *l,int chave){
    int i=buscaBinaria(l->itens,0,l->quant-1,chave),j;
    if(i!=-1){
        for(j=i;j<l->quant;j++){
            l->itens[j]=l->itens[j+1];
        }
        l->quant--;
    }
}

void compara(struct Lista l, struct Lista v){
    int i=buscaBinaria(v.itens,0,v.quant-1,l.itens[0]);
    int j;
    int w = 0;
    int result = 1;
    if(i == -1 ){
        printf("NAO\n");
    }else{
        for(j = i;  (w < l.quant) && (j < v.quant); j++){
            if(l.itens[w] != v.itens[j]){
                result = 0;
            }else{
                result=1;
                w++;
            }
        }
        if(result == 0){
            printf("NAO\n");
        }else{
            printf("SIM\n");
        }
        
    }
    
    
}