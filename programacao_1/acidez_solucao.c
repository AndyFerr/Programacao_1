#include <stdio.h>

int entrada(){
    double n;
    scanf("%lf", &n);

    if (n != -1){
        if (n < 7.0){
            printf("ACIDA\n");
        }else if (n == 7.0){
            printf("NEUTRA\n");
        }else if(n > 7.0){
            printf("BASICA\n");
        }
        return entrada();
    }else{
        return 0;
    }
}

int main(){
    entrada();
    return 0;
}