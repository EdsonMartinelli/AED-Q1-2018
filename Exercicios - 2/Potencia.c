#include <stdio.h>
#include <math.h>
double potencia(int n, int p);
int main (){
    int x = 0;
    int y = 0;
    scanf("%d %d", &x,&y);
    printf("%.0lf\n", potencia(x,y));
    return 0;
}

double potencia(int n, int p){
    if(p==0){
        return 1;
    }
    return potencia(n,p-1)*n;
}