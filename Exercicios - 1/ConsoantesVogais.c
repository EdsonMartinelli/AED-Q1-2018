#include <stdio.h>
#include <math.h>
int main(){
    char x;
    scanf("%c",&x);
    if(x=='A' ||x=='E' ||x=='I' ||x=='O' ||x=='U' ||x=='a' ||x=='e' ||x=='i' ||x=='o'||x=='u'){
        printf("vogal\n");
    }else{
        printf("consoante\n");
    }
    return 0;
}