#include <stdio.h>

void main(){
    double x = 999999999999999;
    printf("%f\n", x);
    x+=10000*x;
    printf("%f\n", x);
    return;

}
