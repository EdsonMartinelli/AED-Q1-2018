#include <stdio.h>
#include <math.h>
int main(){
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    scanf("%lf %lf %lf", &a, &b, &c);
    double delta=pow(b,2)-(4*a*c);
    x1=((-b+sqrt(delta)))/(2*a);
    x2=((-b-sqrt(delta)))/(2*a);
    printf("%.4lf %.4lf\n", x1, x2);
    return 0;
}