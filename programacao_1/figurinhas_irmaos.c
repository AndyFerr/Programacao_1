
#include <stdio.h>

int verif(int arr[], int n, int pos, int num, int *n1, int *n2){
    if (pos == n){
        return 1;
    }else if (num == arr[pos]){
        if(num%2 == 0){
            *n1 += 1;
        }else{
            *n2 += 1;
        }
        return 0;
    }else{
        return verif(arr, n, pos+1, num, n1, n2);
    }
}

void atribuir(int arr[], int n, int pos, int *n1, int *n2){
    int m;
    if (pos == n){
        return;
    }else{
        scanf("%d", &m);
        if (verif(arr, n, 0, m, n1, n2)){
            arr[pos] = m;
            return atribuir(arr, n, pos+1, n1, n2);
        }
        return atribuir(arr, n, pos+1, n1, n2);
    }
}

void stdAtr(int arr[], int n, int cont){
    if (cont == n){
        return;
    }else{
        arr[cont] = 13001;
        return stdAtr(arr, n, cont+1);
    }
}

int separarFigurinhas(int arr[], int n, int *j, int *m, int pos, int *n1, int *n2){
    if (pos == n){
        return 0;
    }else if(arr[pos] == 13001){
        return separarFigurinhas(arr, n, j, m, pos+1, n1, n2);    
    }
    else if (arr[pos]%2 == 0){
        *j += arr[pos];
        *n1 += 1;
    }else{
        *m += arr[pos];
        *n2 += 1;
    }
    return separarFigurinhas(arr, n, j, m, pos+1, n1, n2);
}

int main() {
    int n;

    scanf("%d", &n);

    int nserie[n];
    
    int n1 = 0, n2 = 0;
    
    stdAtr(nserie, n, 0);
    atribuir(nserie, n, 0, &n1, &n2);
    
    int joao = 0, maria = 0;
    
    separarFigurinhas(nserie, n, &joao, &maria, 0, &n1, &n2);

    printf("\n\n%d\n", n1);
    printf("%d\n", n2);
    if (joao > maria){
        printf("%d\n", joao);
    }else{
        printf("%d\n", maria);
    }

    return 0;
}