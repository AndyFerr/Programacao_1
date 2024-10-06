#include <stdio.h>

int seqq(int a, int b, int c){

    if (b == 0){
        return a;
    }else if (c == 1){
        return seqq(a+3, b-1, 0);
    }else if (c == 0){
        return seqq(a+(a%5), b-1, 1);
    }

}

int main(){
    int a, b;

    scanf("%d%d", &a, &b);

    printf("%d\n", seqq(a, b, 1));

    return 0;
}