#include <stdio.h>

int main(){
    int a = 0, b = 0;
    char x[1000];
    scanf("%d %s %d", &a,x, &b);
    printf("%s, voce completa %d anos de idade neste ano.\n", x, (a-b));
    return 0;
}