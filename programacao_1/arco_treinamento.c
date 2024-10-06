// Online C compiler to run C program online
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

void printInverso(int arr[], int tam){
    if(tam == 0){
        printf("%d\n", arr[tam]);
        return;
    }
    printf("%d ", arr[tam]);
    printInverso(arr, tam-1);
}

int verifQuant(int arr[], int n, int x, int cont, int pos){
    if (pos == n){
        return cont;
    }else{
        if (arr[pos] == x){
            cont += 1;
        }
        return verifQuant(arr, n, x, cont, pos+1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int bandeiras[n];
    atribuir(bandeiras, n, 0);

    int vermelho = verifQuant(bandeiras, n, 1, 0, 0);
    int laranja = verifQuant(bandeiras, n, 2, 0, 0);
    int amarelo = verifQuant(bandeiras, n, 3, 0, 0);

    printf("Amarelo = %d\n", amarelo);
    printf("Laranja = %d\n", laranja);
    printf("Vermelho = %d\n", vermelho);
    
    printInverso(bandeiras, n-1);

    return 0;
}