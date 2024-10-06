#include <stdio.h>

int ingresso(int a, int b, int c, int d, int total){
    if (b < a){
        return total;
    }else{
        if (b*d > total){
            total = b*d;
            return ingresso(a, b-1, c, d+c, total);
        }
    }
}

int main(){

    int a, b, c, d;

    scanf("%d%d%d%d", &a, &b, &c, &d);

    printf("%d\n", ingresso(a, b, c, d, 0));

}