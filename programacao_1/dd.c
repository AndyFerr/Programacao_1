#include <stdio.h>

void calc(int arr1[], int arr2[], int arr3[], int pos){
    if (pos == 5){
        return;
    }
    arr1[pos] = arr2[pos] + arr3[pos];
    return calc(arr1, arr2, arr3, pos+1);
}

void verif(int arr[], int *pass, int *maior, int *menor, int pos, int cd){
    if (pos == 5){
        return;
    }else if(arr[pos] > maior){
        *maior = arr[pos];
    }else if (arr[pos] < menor){
        *menor = arr[pos];
    }else if(arr[pos] >= cd){
        *pass += 1;
    }
    verif(arr, pass, maior, menor, pos+1, cd);
}

int main(){
    int n;
    scanf("%d", &n);

    int dado[5];
    int bonus[5];

    scanf("%d %d %d %d %d", &dado[0], &dado[1], &dado[2], &dado[3], &dado[4]);
    scanf("%d %d %d %d %d", &bonus[0], &bonus[1], &bonus[2], &bonus[3], &bonus[4]);

    int resultz[5];

    calc(resultz, dado, bonus, 0);

    int pass = 0;
    int maior = 0;
    int menor = 20;

    verif(resultz, pass, maior, menor, 0, n);

    printf("Jogadores que passaram: %d\n", pass);
    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

}