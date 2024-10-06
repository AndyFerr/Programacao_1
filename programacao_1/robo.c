#include <stdio.h>
#include <string.h>

int conversao(char num[], int tam, int cont){
    
    if (cont == tam-1){
        return 0;
    }else{
        
        conversao(num, tam, cont+1);
        if ((num[cont] - '0')%2 == 0){
            printf(".");
        }else{
            printf("-");
        }
    }

}

int chamada(int cont){
    if (cont == 10){
        return 0;
    }else{
        char num[10];
        fgets(num, sizeof(num), stdin);

        int tam = strlen(num);

        conversao(num, tam, 0);
        printf("\n");
        return chamada(cont + 1);
    }
}

int main(){
    chamada(0);

    return 0;
}