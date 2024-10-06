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

void sort2 (int n, int i, int arr [ ]){
    int temp;
    
    if(i <  n){

        if ( arr[ i ] < arr[ i + 1 ]){

            temp = arr[ i ];
            arr[ i ] = arr[ i + 1 ];
            arr[ i + 1 ] = temp;

            }
        
        return sort2(n, i + 1, arr);

        }
}

void bubble2 (int n, int arr[]){
    if (n == 1){
        return;
    }
    else{
        sort2(n-1, 0, arr);
        bubble2(n-1, arr);
    }
}

void print(int arr[], int n, int pos){
    if (pos == n){
        printf("\n");
        return;
    }else if (pos > 0){
        printf(" ");
    }
    printf("%d", arr[pos]);
    print(arr, n, pos+1);
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

void ler(int n, int cont){
    if (cont == n+1){
        return;
    }

    int arr[10];

    atribuir(arr, 10, 0);

    bubble(10, arr);
    printf("turma %d:", cont);
    printf("\n");
    print(arr, 10, 0);
    bubble2(10, arr);
    print(arr, 10, 0);

    ler(n, cont+1);
}

int main(){
    int n;
    scanf("%d", &n);

    ler(n, 1);
}