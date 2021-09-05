#include <stdio.h>
int main(){
    int c = 0;
    while(scanf("%d",&c)!=EOF){
        if(c>0){
            printf("vai ter duas!\n");
        }else{
            printf("vai ter copa!\n");
        }
    }
    return 0;
}