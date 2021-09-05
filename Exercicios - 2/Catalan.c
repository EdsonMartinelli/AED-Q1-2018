#include <stdio.h>
#include <math.h>
int catalan(int n);
int main (){
    int x = 0;
    while(x !=  -1){
        scanf("%d", &x);
        if(x != -1){
             int result = catalan(x);
             printf("%d\n", result);
        }
       
    }
    return 0;
}

int catalan(int n){
    if(n==0){
        return 1;
    }else{
        return (catalan(n-1)*(4*n-2))/(n+1);
    }
}