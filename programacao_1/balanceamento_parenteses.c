#include <stdio.h>

int balanceamentopar(int arr[], int n, int pos, int a, int b){
    if (pos == n/2){
        return 1;
    }else if (!(arr[pos] == a && arr[n-1-pos] == b || arr[pos])){
        return 0;
    }else{
        balanceamento(arr, n, pos+1, a, b);
    }
}

int balanceamento(int arr[], int n, int pos, int a, int b, int cont1, int cont2){
    if (pos == n){
        if (cont1 == cont2){
            return 1;
        }else{
            return 0;
        }
    }

    if(arr[pos] == a){
        cont1 += 1;
    }else if(arr[pos] = b){
        cont2 += 1;
    }

    balanceamento(arr, n, pos+1, a, b, cont1, cont2);
}

int balanceamentoImpar(int arr[], int n, int pos, int a, int b){
    if (pos == (n%2 + 1)){
        return 1;
    }else if (!(arr[pos] == a && arr[n-1-pos] == b)){
        return 0;
    }else{
        balanceamentoImpar(arr, n, pos+1, a, b);
    }
}

int main(){

}