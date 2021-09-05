#include <stdio.h>
int main(){
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    if(a>b && (3<=b && 96>=b)){
        printf("Minguante\n");
    }else if(0<=b && 2>=b){
        printf("Nova\n");
    }else if(3<=b && 96>=b){
        printf("Crescente\n");
    }else{
        printf("Cheia\n");
    }
    
    return 0;
}