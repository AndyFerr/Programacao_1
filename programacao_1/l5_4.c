#include <stdio.h>

void atribuir(int arr[], int n, int cont){
    int m;
    if (cont == n){
        return;
    }else{
        scanf("%d", &m);
        arr[cont] = m;
        return atribuir(arr, n, cont+1);
    }
}

int verif(int arr[], int x, int cont, int pos){
    if (pos == 10){
        return cont;
    }else{
        if (arr[pos] == x){
            cont += 1;
        }
        return verif(arr, x, cont, pos+1);
    }
}

int main(){
    int arr[10];
    int x;

    atribuir(arr, 10, 0);

    scanf("%d", &x);

    printf("%d", verif(arr, x, 0, 0));

}