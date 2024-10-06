#include <stdio.h>

int ano_bi(int a, int b){
    if (a > b){
        return 0;
    } else {
        if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)){
            printf("%d\n", a);
        }
        return ano_bi(a + 1, b);
    }
}

int ano_bit(int a, int b, int c){
    if (a > b){
        return c;
    } else if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)){
        c = 1;
        
    }
    return ano_bit(a + 1, b, c);
}

int main(){
    int a, b;

    scanf("%d%d", &a, &b);
    
    int verif = ano_bit(a, b, 0);

    if (verif){
        printf("-1\n");
    }else{
        ano_bi(a, b);
    }
    
    return 0;
}
