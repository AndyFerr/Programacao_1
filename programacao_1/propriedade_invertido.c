#include <stdio.h>

int prop(char str[],int n){

    int m = str[0] - '0';
    if (n % 10 != 0 && n % m == 0){
        printf("%d\n", n);
    }

}

int chamada(int n, int m){

    if(n < m+1){

        char str[3];
        sprintf(str, "%d", n);

        prop(str, n);
        chamada(n+1, m);
    }
}

int main(){
    int n, m;


    scanf("%d", &n);
    scanf("%d", &m);
    
    chamada(n, m);

    return 0;
}