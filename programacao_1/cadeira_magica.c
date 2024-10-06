#include <stdio.h>

int seq(int n, int m){
    if (n == 0){
        return 0;
    }
    seq(n-1, m);
    if (n == m){
        printf("%d\n", n);
    }else{
        printf("%d ", n);
    }
    
}

int chamada(int n){
    if (n == 0){
        return 0;
    }
    chamada(n-1);
    seq(n, n);
}

int main(){
    int n;
    scanf("%d", &n);

    chamada(n);
    return 0;
}

