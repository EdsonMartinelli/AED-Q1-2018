#include <stdio.h>
#include <stdlib.h>
struct Lista
{
    int * numerador;
    int * denominador;
    int quantidade, tamanho;
};

struct Lista criaLista(int);
void inserir( struct Lista *, int, int, int);
int buscaBinaria(int *, int *, int, int, double);
void remover(struct Lista *, double);
void mostrar(struct Lista);

int main (){
    int q, i = 0, valnum, valden, b;
    char op;
    struct Lista l;
    
    scanf("%d", &q);
    l =  criaLista(q);
    while(scanf("\n%c %d %d", &op, &valnum, &valden)!= EOF){
        if( op == 'I'){
            inserir(&l,valnum, valden, q);
        }else if( op == 'R') {
            remover(&l,valnum/(double)valden); 
        }else if(op == 'B'){
            if( buscaBinaria(l.numerador,l.denominador, 0, l.quantidade-1,valnum/(double)valden)>-1 ? printf("SIM\n") : printf("NAO\n"));
        }else if(op == 'M'){
            mostrar(l);
        }
    }
    return 0;
}

struct Lista criaLista(int n){
    struct Lista l;
    l.numerador = ( int *) malloc ( n*sizeof(int));
    l.denominador = ( int *) malloc ( n*sizeof(int));
    l.quantidade = 0;
    l.tamanho = n;
    return l;
    
}
void inserir( struct Lista * l , int chavenum, int chaveden , int max){//terminado
    if(l->quantidade >= max){
        return;
    }
    int i, j, achei = 0;
    i=0;
    while(i < l->quantidade && !achei){
        if((l->numerador[i] / (double)l->denominador[i]) == (chavenum/(double)chaveden) ){
            if(chavenum < l->numerador[i]){
                l->numerador[i]=chavenum;
                l->denominador[i]=chaveden;
            }
            return;
        }else if((chavenum/(double)chaveden) < (l->numerador[i] / (double)l->denominador[i])){
            achei = 1;
        }else{
            i++;
        }
    }
    for(j=l->quantidade-1; j>=i; j--){ 
        l->numerador[j+1] = l->numerador[j];
        l->denominador[j+1] = l->denominador[j];
    }
    l->numerador[i]=chavenum;
    l->denominador[i]=chaveden;
    l->quantidade++;
}
int buscaBinaria(int * v, int * k, int e, int d, double x){//terminado
    int meio;
    while(e <= d){
        meio = (e + d)/2;
        if((v[meio]/(double)k[meio])-x == 0){
            return meio;
        }
        else if ((v[meio]/(double)k[meio])-x < 0){
            e = meio+1;
        }
        else{
            d = meio-1;
        }
    }
    return -1;
    
}
void remover(struct Lista * l, double chave){//terminado
    int i = buscaBinaria(l->numerador,l->denominador, 0, l->quantidade-1,chave);
    int j;
    if(i != -1){
        for(j = i; j < l->quantidade; j++){
            l->numerador[j] = l->numerador[j+1];
            l->denominador[j] = l->denominador[j+1];
        }
        l->quantidade--;
    }
    
}
void mostrar(struct Lista l){  // terminado
    int i;
    for(i=0; i < l.quantidade; i++){
        if(i != l.quantidade -1 ){
           printf("%d/%d ", l.numerador[i],l.denominador[i]);
        }else{
           printf("%d/%d\n", l.numerador[i],l.denominador[i]);
        }
    }
}

