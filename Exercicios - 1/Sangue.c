#include <stdio.h>
int main(){
    char a[2];
    char b[2];
    scanf("%s %s", a, b);
    if(a[0]=='O' && a[1]=='\0'){
        if(b[0]=='O' && b[1]=='\0'){
            printf("transfusao compativel\n");
        }else{
            printf("transfusao incompativel\n");
        }
    }
    
    if(a[0]=='A' && a[1]=='\0'){
        if((b[0]=='O' && b[1]=='\0') || (b[0]=='A' && b[1]=='\0')){
            printf("transfusao compativel\n");
        }else{
            printf("transfusao incompativel\n");
        }
    }
    
    if(a[0]=='B' && a[1]=='\0'){
        if((b[0]=='O' && b[1]=='\0') || (b[0]=='B' && b[1]=='\0')){
            printf("transfusao compativel\n");
        }else{
            printf("transfusao incompativel\n");
        }
    }
    
    if(a[0]=='A' && a[1]=='B'){
        printf("transfusao compativel\n");
    }
    
    return 0;
}