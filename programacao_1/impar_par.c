#include <stdio.h>

void printPAR(int arr[], int n, int pos){
    if (pos == n){
        return;
    }
    if (arr[pos]){
        printf("par[%d] = %d\n", pos, arr[pos]);
        printPAR(arr, n, pos+1);
    }
    return;
}

void printIMPAR(int arr[], int n, int pos){
    if (pos == n){
        return;
    }
    if (arr[pos]){
        printf("impar[%d] = %d\n", pos, arr[pos]);
        printIMPAR(arr, n, pos+1);
    }
    return;
}

// void atribuir(int arr[], int n, int cont){
//     if(cont == n) return;

//     arr[cont] = NULL;
//     atribuir(arr, n, cont+1);
// }

void ler(int par[], int impar[], int pos1, int pos2, int cont){
    if (cont == 15){
        printIMPAR(impar, pos2, 0);
        printPAR(par, pos1, 0);
        return;
    }

    if (pos1 == 5){
        printPAR(par, 5, 0);
        return ler(par, impar, 0, pos2, cont);
    }else if(pos2 == 5){
        printIMPAR(impar, 5, 0);
        return ler(par, impar, pos1, 0, cont);
    }

    int n;
    scanf("%d", &n);

    if (n%2 == 0){
        par[pos1] = n;
        return ler(par, impar, pos1+1, pos2, cont+1);
    }else{
        impar[pos2] = n;
        return ler(par, impar, pos1, pos2+1, cont+1);
    }
}

int main(){

    int par[5];
    int impar[5];

    ler(par, impar, 0, 0, 0);
}