#include <stdio.h>

int sequencia(int n, int cont, int a, int b){

    if (n == b){
        printf("%d\n", n);
        return 0;
    }
    else if (cont == a-1){
        printf("%d\n", n);
        return sequencia(n+1, 0, a, b);
    }
    else{
        printf("%d ", n);
        return sequencia(n+1, cont+1, a, b);
    }
}

int main(){
    int a, b;

    scanf("%d%d", &a, &b);

    sequencia(1, 0, a, b);

    return 0;
}