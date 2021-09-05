#include <stdio.h>
#include <math.h>
int achei(int * a, int p, int x);
int main (){
    int x = 0;
    scanf("%d", &x);
    int * a =(int *)malloc(x*sizeof(int));
    int i = 0;
    for(;i<x;i++){
        scanf("%d", a+i);
    }
    int y =0;
    scanf("%d", &y);
    i = 0;
    for(;i<y;i++){
        int p = 0;
        scanf("%d", &p);
        int result = prodesc(a, p, x);
        if(result == 1 ? printf("ACHEI\n") : printf("NAO ACHEI\n") );
    }
    
    return 0;
}

int prodesc(int * a, int p, int x){
    if(x==0){
        return 0;
    }
    if(*(a+x-1)==p){
        return 1;
    }
    return prodesc(a, p, x-1);
}