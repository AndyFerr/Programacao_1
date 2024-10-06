#include <stdio.h>

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
    int *pam = &programasAcimadaMedia;
    int linhasAcimadaMedia = 0;
    int *lam = &linhasAcimadaMedia;
    int indiceDiaMaisProdutivo = 0;
    int *imp = &indiceDiaMaisProdutivo;

    //produtividade(programasAcimadaMedia, linhasAcimadaMedia, 0, 0, indiceDiaMaisProdutivo);

    printf("Programas acima da media: %d\n", programasAcimadaMedia);

    produtividade(&programasAcimadaMedia, &linhasAcimadaMedia, 0, 0, &indiceDiaMaisProdutivo);

    printf("Programas acima da media: %d\n", programasAcimadaMedia);
    return 0;
}