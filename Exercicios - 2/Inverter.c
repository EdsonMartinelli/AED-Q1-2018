#include <stdio.h>
#include <math.h>
void inverter(int *v, int x);
int main (){
    int x = 0;
    scanf("%d", &x);
    int *v=(int*)malloc(x*sizeof(int));
    int i = 0;
    for(;i<x;i++){
        scanf("%d",v+i);
    }
    inverter(v,x);
    printf("\n");
    return 0;
}

void inverter(int *v, int x){
    
    if(x==1){
        printf("%d",*(v+x-1));
        return;
    }
    printf("%d ",*(v+x-1));
    inverter(v,x-1);
}