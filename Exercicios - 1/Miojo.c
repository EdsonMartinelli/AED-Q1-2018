#include <stdio.h>
#include <math.h>
int teste (int temp, int amp1, int amp2, int vezesamp1, int vezesamp2);
int main(){
    int a= 0, b = 0, t = 0;
    scanf("%d %d %d", &t, &a, &b);
    int result1 = teste(t,a,b,1,1);
    int result2 = teste(t,b,a,1,1);
    if( result1 > result2 ? printf("%d\n",result2) : printf("%d\n",result1));
    return 0;
}

int teste (int temp, int amp1, int amp2, int vezesamp1, int vezesamp2){
    amp1 = amp1*vezesamp1;
    amp2 = amp2*vezesamp2;
    if( amp1-amp2 == temp ){
        return amp1;
    }else if( amp1-amp2 < temp ){
        amp1 = amp1/vezesamp1;
        amp2 = amp2/vezesamp2;
        vezesamp1++;
        teste(temp,amp1,amp2,vezesamp1,vezesamp2);
    }else if( amp1-amp2 > temp ){
        amp1 = amp1/vezesamp1;
        amp2 = amp2/vezesamp2;
        vezesamp2++;
        teste(temp,amp1,amp2,vezesamp1,vezesamp2);
    }
}