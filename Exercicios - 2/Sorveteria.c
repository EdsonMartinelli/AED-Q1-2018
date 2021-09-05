#include <stdio.h>
int * sor(int * v, int n , int m);
int main (){
    int t = 0;
    scanf("%d", &t);
    for(;t>0;t--){
        int m = 0;
        scanf("%d", &m);
        int n = 0;
        scanf("%d", &n);
        int * v= (int *) malloc (n* sizeof(int));
        int * k = (int *) malloc (2* sizeof(int));
        int i = 0;
        for(; i < n; i++){
            scanf("%d",v+i);
        }
        int * result =(int * ) sor(v, n, m);
        printf("%d %d\n", *(result),*(result+1));
    }
    return 0;
}

int * sor(int * v, int n , int m){
    int * k = (int *) malloc (2* sizeof(int));
    *(k+1) = n;
    int j = 0;
    for(; j < n-1; j++){
        if(m == (*(v+n-1))+(*(v+j))){
            *(k) = j+1;
            return k;
        }
    }
    return sor(v, n-1 , m);
}