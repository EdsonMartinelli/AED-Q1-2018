#include <stdio.h>
#include <stdlib.h>

struct Lista{
    char ** matriz;
    int tamanhomatriz;
};
struct Lista criaLista(int tamanho);
void OrdenaStrings(struct Lista *);
void Imprime(struct Lista);
char * copia(char *);

int main(){
    int i, numero, tamanho;
    char * vetor =  (char * ) malloc ( 100000 * sizeof( char ));
    struct Lista l;
    scanf("%d", &tamanho);
    l = criaLista(tamanho);
    for(i = 0; i < tamanho; i++){
        scanf("%s", vetor);
        char * stringcopiada = copia(vetor);
        l.matriz[i]= stringcopiada;
    }
    OrdenaStrings(&l);
    return 0;
    
}

struct Lista criaLista(int tamanho){
    struct Lista l;
    l.matriz =  (char ** ) malloc ( tamanho * sizeof( char * ));
    l.matriz[0]="aaaa";
    l.tamanhomatriz = tamanho;
    return l;
}

void OrdenaStrings(struct Lista * l){
    int i, tamanho1, tamanho2, j, w;
    for(i = l->tamanhomatriz-1; i > 0; i--){
        for(w = 0; w < i; w++){
            tamanho1 = 0;
            tamanho2 = 0;
            j = 0;
            while (l->matriz[w][j] != '\0'){
                tamanho1++;
                j++;
            }
            j = 0;
            while (l->matriz[w+1][j] != '\0'){
                tamanho2++;
                j++;
            }
            
            if(tamanho2 > tamanho1 ){
                char *  novo1 = (char *) copia (l->matriz[w]);
                char *  novo2 = (char *) copia (l->matriz[w+1]);
                l->matriz[w] = novo2;
                l->matriz[w+1] = novo1;
            }
        }
    }
    Imprime(*l);
}

void Imprime(struct Lista l){
    int i, j, k, tamanho;
    for(i = 0; i < l.tamanhomatriz; i++){
        tamanho = 0;
        j = 0;
        while (l.matriz[i][j] != '\0'){
            tamanho++;
            j++;
        }
        for(k = 0; k < tamanho; k++){
            if(k ==  tamanho-1){
                printf("%c\n", l.matriz[i][k]);
            }else{
                printf("%c", l.matriz[i][k]);
            }
        }
    }
}

char * copia(char * nome){
    int i=0;
    while (nome[i] != '\0'){
        i++;
    }
    char * copiadastring = (char *) malloc (100000*sizeof(char));
    int x=0;
    for (; x < i; x++){
        copiadastring[x] = nome[x]; 
    }
    copiadastring[x]='\0';
    return copiadastring;
}
