#include <stdio.h>
#include <math.h>
int main(){
    int ano = 0;
    scanf("%d",&ano);
    if(ano%400==0){
        printf("ANO BISSEXTO\n");
    }else if(ano%4==0 && ano%100!=0){
        printf("ANO BISSEXTO\n");
    }else{
         printf("ANO NAO BISSEXTO\n");
    }
    return 0;
}