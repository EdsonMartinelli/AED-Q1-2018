#include <stdio.h>
#include <math.h>
int main(){
    int a = 0, b = 3;
    char x[4];
    scanf("%s",x);
    for(;a<2;a++){
        char temp=x[a];
        x[a]=x[3-a];
        x[3-a]=temp;
    }
    printf("%s\n", x);
    return 0;
}