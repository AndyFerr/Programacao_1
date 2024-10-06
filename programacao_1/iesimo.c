#include <stdio.h>

void sort (int n, int i, int arr [ ]){
    int temp;
    
    if(i <  n){

        if ( arr[ i ] > arr[ i + 1 ]){

            temp = arr[ i ];
            arr[ i ] = arr[ i + 1 ];
            arr[ i + 1 ] = temp;

            }
        
        return sort(n, i + 1, arr);

        }
}

void bubble (int n, int arr[]){
    if (n == 1){
        return;
    }
    else{
        sort(n-1, 0, arr);
        bubble(n-1, arr);
    }
}

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

int main(){
    int n, m;
    
    scanf("%d %d", &n, &m);

    int arr[n];

    atribuir(arr, n, 0);

    bubble(n, arr);

    printf("%d", arr[n-m]);
}