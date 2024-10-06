#include <stdio.h>
#include <math.h>

int fib(int n) {
    if (n == 0){
        return 0;
    }else if (n == 1){
        return 1;
    }else{
        return fib(n-1) + fib(n-2);
    }
}

int verif(int n, int cont){
    if (fib(cont) > n){
        return 0;
    }else if(fib(cont) == n){
        return 1;
    }else{
        return verif(n, cont+1);
    }
}

int verif3(int n, int divisor){
    
    if (n == 0 || n == 2){
        return 1;
    }else if (divisor > sqrt(n)){
        return 1;
    }else if(n%divisor == 0){
        return 0;
    }else{
        return verif3(n, divisor+1);
    } 

} 

}

int entrada(int *ekul, int *aim){
    int n;
    scanf("%d", &n);
    if (n == -1){
        return 0;
    }else{
        *ekul += verif(n, 0);
        *aim += verif3(n, 0, 1);
        return entrada(ekul, aim);
    }
}

int main(){

    int ekul = 0;
    int aim = 0;

    entrada(&ekul, &aim);
/*
    printf("aim: %d\n", aim);
    printf("ekul: %d\n", ekul);
*/

    if (ekul > aim){
        printf("Ekul conquistou o pote de ração!\n");
    }else if(aim > ekul){
        printf("Aim conquistou o pote de ração!\n");
    }else{
        printf("A ração se perdeu durante o duelo.\n");
    }

    return 0;
}