#include <stdio.h>
#include <string.h>

int convert(char n[], int algarismos[], int cont){
    if (cont == strlen(n) - 1){
        return 0;
    }else{
        algarismos[cont] = n[cont] - '0';
        return convert(n, algarismos, cont+1);
    }
    
}

int soma(int algarismos[], int cont, char n[]){
    if (cont == strlen(n)){
        return 0;
    }else{
        return algarismos[cont] + soma(algarismos, cont+1, n);
    }
}


int main(){
    static char n[10];
    static int algarismos[10];

    fgets(n, sizeof(n), stdin);

    convert(n, algarismos, 0);

    printf("A soma dos algarismos de %s", n);
    printf("é : %d\n", soma(algarismos, 0, n));
    
}