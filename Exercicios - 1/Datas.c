#include <stdio.h>
#include <math.h>
int verificaano(int ano);
int main (){
    int x = 0;
    scanf("%d", &x);
    for(;x>0;x--){
        int d= 0, m = 0, a = 0;
        scanf("%d %d %d", &d, &m, &a);
        int bissexto = verificaano(a);
        if(d>31 || m>12){
            printf("DATA INVALIDA\n");
        }else if(( m==4 || m==6 || m==9 || m==11) && (d>30)){
            printf("DATA INVALIDA\n");
        }else if ((bissexto>0 && m==2 && d>29) ||(bissexto==0 && m==2 && d>28)){
            printf("DATA INVALIDA\n");
        }else {
            printf("DATA VALIDA\n");
        }
    }
    
    return 0;
}

int verificaano(int ano){
    if(ano%400==0){
       return 1;
    }else if(ano%4==0 && ano%100!=0){
       return 1;
    }else{
       return 0;
    }
}