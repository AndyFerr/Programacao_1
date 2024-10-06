#include <stdio.h>
#include <string.h>

int produtividade(int *pam, int *lam, int cont, int variavelControleLinhas, int *imp){
    if (cont == 7){
        return 0;
    }

    int a, b;

    scanf("%d%d", &a, &b);

    if (a >= 5){
        *pam += 1;
    }
    if (b >=100){
        *lam += 1;
    }
    if (b >= variavelControleLinhas){
        variavelControleLinhas = b;
        *imp = cont;
    }

    return produtividade(pam, lam, cont+1, variavelControleLinhas, imp);
}

int main(){
    int programasAcimadaMedia = 0;
    int linhasAcimadaMedia = 0;
    int indiceDiaMaisProdutivo = 0;

    char dias_semana[7][15];

    strcpy(dias_semana[0], "DOMINGO");
    strcpy(dias_semana[1], "SEGUNDA");
    strcpy(dias_semana[2], "TERCA");
    strcpy(dias_semana[3], "QUARTA");
    strcpy(dias_semana[4], "QUINTA");
    strcpy(dias_semana[5], "SEXTA");
    strcpy(dias_semana[6], "SABADO");

    produtividade(&programasAcimadaMedia, &linhasAcimadaMedia, 0, 0, &indiceDiaMaisProdutivo);

    printf("QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE PROGRAMAS: %d\n", programasAcimadaMedia);
    printf("QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE LINHAS: %d\n", linhasAcimadaMedia);
    printf("DIA QUE MAIS PRODUZIU: %s\n", dias_semana[indiceDiaMaisProdutivo]);


    return 0;
}