
#include <stdio.h>

void sort (int n, int i, double arr [ ]){
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
    int m;
    if (cont == n){
        return;
    }else{
        scanf("%d", &m);
        arr[cont] = m;
        return atribuir(arr, n, cont+1);
    }
}

double media(int n, double arr[], int cont, double soma){

    if (cont == n){
        return soma/n;
    }else{
        soma += arr[cont];
        return media(n, arr, cont+1, soma);
    }

}

double mediana(double arr[], int n){

    if (n%2 != 0){
        return arr[(n/2)];
    }else{
        return (arr[n/2]+arr[(n/2)-1])/2;
    }
}


double moda (double arr[], int n, int pos, int md, int cont1, int cont2){
    
    if (pos == n){
        return md;
    }
    

    if (arr[pos] == arr[pos+1]){
        cont2 += 1;
        return moda(arr, n, pos+1, md, cont1, cont2);
    }else if (arr[pos] != arr[pos+1]){
        if (cont2 >= cont1){
            cont1 = cont2;
            cont2 = 0;
            md = arr[pos];
        }
        return moda(arr, n, pos+1, md, cont1, cont2);
    }

}


int main() {
    
    int n;;
    scanf("%d", &n);
    double arr[n];
    
    atribuir(arr, n, 0);
    bubble(n, arr);
    
    printf("%.2lf %.2lf %.2lf\n", media(n, arr, 0, 0), mediana(arr, n), moda(arr, n, 0, 0, 0, 0));
    

    return 0;
}