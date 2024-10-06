#include <stdio.h>
#include <math.h>

int eq(int n, int b){
    if (n <= b){
        printf("%lf\n", (pow(n, 2) - 4*n + 5));
        return eq(n+1, b);    
    }
    else{
        return 0;
    }
}

int main(){
    int n, b;
    scanf("%d%d", &n, &b);

    eq(n, b);

    return 0;
}

