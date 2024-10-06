#include <stdio.h>

int mdc(int a, int b){
    
    if (a%b == 0){
        return b;
    }else{
        return mdc(b, a%b);
    }
}

int main(){

    int a, b;
    // Le 2 números a e b;
    scanf("%d%d", &a, &b);

    // Se certifica de que a > b
    if (b > a){
        int c = a;
        a = b;
        b = c;
    }

    printf("mdc: %d\n", mdc(a, b));
}