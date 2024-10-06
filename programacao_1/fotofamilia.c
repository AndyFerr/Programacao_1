#include <stdio.h>

void sort (int n, int i, double arr [ ]){
    double temp;
    
    if(i <  n){

        if ( arr[ i ] > arr[ i + 1 ]){

            temp = arr[ i ];
            arr[ i ] = arr[ i + 1 ];
            arr[ i + 1 ] = temp;

            }
        
        return sort(n, i + 1, arr);

        }
}

void bubble (int n, double arr[]){
    if (n == 1){
        return;
    }
    else{
        sort(n-1, 0, arr);
        bubble(n-1, arr);
    }
}


void atribuir(double arr[], int n, int cont){
    double m;
    if (cont == n){
        return;
    }else{
        scanf("%lf", &m);
        arr[cont] = m;
        return atribuir(arr, n, cont+1);
    }
}

int main(){
    double arr[4];

    atribuir(arr, 4, 0);

    bubble(4, arr);

    double arr2[4];

    arr2[0] = arr[0];
    arr2[3] = arr[1];
    arr2[1] = arr[2];
    arr2[2] = arr[3];

    printf("%.2lf\n", arr2[0]);
    printf("%.2lf\n", arr2[1]);
    printf("%.2lf\n", arr2[2]);
    printf("%.2lf\n", arr2[3]);
}