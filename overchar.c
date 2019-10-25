#include <stdio.h>

void main(){
    int symbolX(char a){
    return (int)a;
}
    unsigned char x = 101 ;
    printf("x was: %d, %c \n", x, symbolX(x)); 
    x+= 156;
    printf("now x is: %d, %c \n", x, symbolX(x));
    return;
}
