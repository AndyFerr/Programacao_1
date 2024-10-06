#include <stdio.h>

int fib(int n) {
    if (n == 0){
        return 0;
    }else if (n == 1){
        return 1;
    }else{
        return fib(n-1) + fib(n-2);
    }
}

int print(int n, int x){

    if (x == n){
        return 0;
    }else if (x+1 == n){
        printf("%d", fib(x));
        return print(n, x+1);
    }else{
        printf("%d ", fib(x));
        return print(n, x+1);
    }

}

int entrada(){
    int n;
    scanf("%d", &n);

    if (n == 0){
        return 0;
    }else{
        print(n, 0);
        printf("\n");
        return entrada();
    }
}

int main(){

    entrada();

    return 0;
}