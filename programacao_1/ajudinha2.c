#include <stdio.h>
#include <stdlib.h>

void atribuirC(double nota[], char curso[], int k, int pos){
    char m;
    double n;
    if (pos == k){
        return;
    }else{
        scanf("%lf", &n);
        scanf("%*c");
        scanf("%c", &m);
        scanf("%*c");
        nota[pos] = n;
        curso[pos] = m;
        return atribuirC(nota, curso, k, pos+1);
    }
}

void ec(double nota[], char curso[], double EC[], int pos, int pos1){
    if (pos == 10){
        return;
    }
    if (curso[pos] == 'e'){
        EC[pos1] = nota[pos];
        pos1 += 1;
    }
    ec(nota, curso, EC, pos+1, pos1);
}

void cc(double nota[], char curso[], double CC[], int pos, int pos1){
    if (pos == 10){
        return;
    }
    if (curso[pos] == 'c'){
        CC[pos1] = nota[pos];
        pos1 += 1;
    }
    cc(nota, curso, CC, pos+1, pos1);
}

int verif(char arr[], int cont, int pos){
    if (pos == 10){
        return cont;
    }else{
        if (arr[pos] == 'e'){
            cont += 1;
        }
        return verif(arr, cont, pos+1);
    }
}

void sort (int n, int i, double arr [ ]){
    double temp;
    
    if(i <  n){

        if ( arr[ i ] < arr[ i + 1 ]){

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

void print(double arr[], int n, int pos){
    if (pos == n){
        printf("\n")
        return;
    }else if (pos > 0){
        printf(" ");
    }
    printf("%.2lf", arr[pos]);
    print(arr, n, pos+1)
}

int main() {
    
    double nota[10];
    char curso[10];
    
    atribuirC(nota, curso, 10, 0);

    int tamEC = verif(curso, 0, 0);
    int tamCC = 10 - tamEC;

    double EC[tamEC], CC[tamCC];

    ec(nota, curso, EC, 0, 0);
    cc(nota, curso, CC, 0, 0);

    bubble(tamEC, EC);
    bubble(tamCC, CC);

    print(EC, tamEC, 0);
    print(CC, tamCC, 0);

    return 0;
}