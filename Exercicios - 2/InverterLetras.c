#include <stdio.h>
void inverterletras(char *v, int i);
int main (){
    char p[100];
    while(scanf("%s", p)!=EOF){
        int i = 0;
        while(*(p+i)!='\0'){
            i++;
        }
        inverterletras(p,i);
        printf("\n");
    }
    
    return 0;
}

void inverterletras(char *v, int i){
    
    if(i==0){
        return;
    }
    printf("%c", *(v+i-1));
    inverterletras(v,i-1);
}