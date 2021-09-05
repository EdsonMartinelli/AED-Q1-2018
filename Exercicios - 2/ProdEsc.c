#include <stdio.h>
#include <math.h>
int prodesc(int * a, int * b, int x);
int main (){
    int x = 0;
    scanf("%d", &x);
    int * a =(int *)malloc(x*sizeof(int));
    int * b =(int *)malloc(x*sizeof(int));
    int i = 0;
    for(;i<x;i++){
        scanf("%d", a+i);
    }
    i = 0;
    for(;i<x;i++){
        scanf("%d", b+i);
    }
    int result = prodesc(a, b, x);
    printf("%d\n", result);
    return 0;
}

int prodesc(int * a, int * b, int x){
    if(x==0){
        return 0;
    }
    int v = (*(a+x-1))*(*(b+x-1));
    return prodesc(a, b, x-1)+v;
}