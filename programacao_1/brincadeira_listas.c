#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sort (int n, int i, int arr [ ]){
    int temp;
    
    if(i <  n){

        if ( arr[ i ] < arr[ i + 1 ]){

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

// Note que em integers a função recebe um ponteiro para um ponteiro
int StringToInteger(char buffer[], int **integers, char *token, int pos){

    //Remove o caracter \n substituindo pelo nulo '\0'
    buffer[strcspn(buffer, "\n")] = '\0';

    
    if (token != NULL){

        // Realoca memória para o ponteiro integer
        *integers = realloc(*integers, (pos+1) * sizeof(int));

        (*integers)[pos] = atoi(token);

        //Pega o proximo token
        token = strtok(NULL, " ");

        StringToInteger(buffer, integers, token, pos+1);
    }else{
        return pos;
    }

}


void printimpar(int integers[], int tam, int pos){
    if (pos >= tam){
        return;
    }
    printf("%d ", integers[pos]);
    printimpar(integers, tam, pos+2);
}

void printpar(int integers[], int tam, int pos){
    if (tam%2 == 0 && pos == tam-1){
        printf("%d ", integers[pos]);
        return;
    }else if(tam%2 != 0 && pos == tam-2){
        printf("%d ", integers[pos]);
        return;
    }
    printf("%d ", integers[pos]);
    printpar(integers, tam, pos+2);
}


void print(int arr[], int tam, int pos){
    if(pos == tam-1){
        printf("%d\n", arr[pos]);
        return;
    }
    printf("%d ", arr[pos]);
    print(arr, tam, pos+1);
}

void copiar(int arr1[], int arr2[], int tam, int pos){
    if (pos == tam){
        return;
    }
    arr2[pos] = arr1[pos];
    copiar(arr1, arr2, tam, pos+1);
}

int main(){
    char buffer[100];

    fgets(buffer, sizeof(buffer), stdin);


    //Cria um ponteiro nulo para ter sua memoria realocada de acordo com as entradas
    int *integers = NULL;

    // Inicializa a variável token para percorrer a string
    char *token = strtok(buffer, " ");
    
    int tam = StringToInteger(buffer, &integers, token, 0);

    int copia[tam];

    copiar(integers, copia, tam, 0);

    bubble(tam, integers);

    // for (int i = 0; i < tam; i++){
    //     printf("%d ", integers[i]);
    // }
    // printf("\n");
    printf("Invert: ");
    print(integers, tam, 0);

    printf("ParImp: ");
    printpar(copia, tam, 1);
    printimpar(copia, tam, 0);
}
