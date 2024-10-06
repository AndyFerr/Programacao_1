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


int printpar(int integers[], int arr2[], int tam, int pos, int poss){
    if (pos >= tam){
        return poss;
    }
    arr2[poss] = integers[pos];
    printpar(integers, arr2, tam, pos+2, poss+1);
}

void printimpar(int integers[], int arr2[], int tam, int pos, int poss){
    if (tam%2 == 0 && pos == tam-1){
        arr2[poss] = integers[pos];
        return;
    }else if(tam%2 != 0 && pos == tam-2){
        arr2[poss] = integers[pos];
        return;
    }
    arr2[poss] = integers[pos];
    printimpar(integers, arr2, tam, pos+2, poss+1);
}


void print(int arr[], int tam, int pos){
    if(pos == tam-1){
        printf("%d\n", arr[pos]);
        return;
    }
    printf("%d ", arr[pos]);
    print(arr, tam, pos+1);
}

void printA(int arr[], int tam){
    if(tam == 0){
        printf("%d\n", arr[tam]);
        return;
    }
    printf("%d ", arr[tam]);
    printA(arr, tam-1);
}

void copiar(int arr1[], int arr2[], int tam, int pos){
    if (pos == tam){
        return;
    }
    arr2[pos] = arr1[pos];
    copiar(arr1, arr2, tam, pos+1);
}

void printC(int integer[], int arr2[], int tam, int pos, int aux){
    if(pos == tam-1){
        printf("%d\n", (integer[aux] + arr2[pos]));
        return;
    }
    printf("%d ", (integer[aux] + arr2[pos]));
    printC(integer, arr2, tam, pos+1, aux-1);
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

    int arr2[tam];
    int arr3[tam];

    copiar(integers, copia, tam, 0);

    // for (int i = 0; i < tam; i++){
    //     printf("%d ", integers[i]);
    // }
    // printf("\n");
    printf("Invert: ");
    printA(integers, tam-1);

    int tam2 = printpar(copia, arr2, tam, 0, 0);
    printimpar(copia, arr2, tam, 1, tam2);
    

    printf("ParImp: ");
    print(arr2, tam, 0);

    printf("Soma: ");
    printC(integers, arr2, tam, 0, tam-1);

    free(copia);
    free(integers);

}
