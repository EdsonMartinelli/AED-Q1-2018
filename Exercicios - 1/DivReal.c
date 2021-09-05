#include <stdio.h>

int main(){
    int a = 0, b = 0;
    double c = 0;
    scanf("%d %d", &a, &b);
    c=a/(double)b;
    printf("%.2lf\n",c);
    return 0;
}