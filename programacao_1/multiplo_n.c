#include <stdio.h>

int multiplo(int n, int x){
    return n*x;
}

int print(int n, int a, int b, int x){
    if (n <= b && n >= a){

        if (multiplo(n, x) < a ){
            return print(n, a, b, x+1);
        }else if(multiplo(n, x) <= b){
            printf("%d\n", multiplo(n, x));
            return print(n, a, b, x+1);
        }else{
            return 0;
        }
    }else{
        printf("INEXISTENTE\n");
    }
}

int main(){
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);

    print(n, a, b, 0);

    return 0;
}