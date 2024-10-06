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

int verif(int x, int cont, int arr[], int pos){
    if (pos == x){
        return cont;
    }
    else if (arr[pos] == x){
        cont +=1;
        
    }
    return verif(x, cont, arr, pos+1);
}

int main(){
    int arr[10];

    atribuir(arr, 10, 0);

    int x;
    scanf("%d", &x);
    
    printf("%d\n", x);
    printf("%d\n", verif(x, 0, arr, 0));
}