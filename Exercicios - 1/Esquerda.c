#include <stdio.h>
#include <math.h>

int main (){
    int n = 0;
    scanf("%d",&n);
    char v[n];
    scanf("%s",v);
    char x='N';
    int i=0;
    for(;i<n;i++){
        if(v[i]=='D'){
                 if(x=='N'){x='L';}
            else if(x=='L'){x='S';}
            else if(x=='S'){x='O';}
            else if(x=='O'){x='N';}
        }else if(v[i]=='E') {
                 if(x=='N'){x='O';}
            else if(x=='O'){x='S';}
            else if(x=='S'){x='L';}
            else if(x=='L'){x='N';}
        }
    }
    printf("%c\n",x);
    
    return 0;
}