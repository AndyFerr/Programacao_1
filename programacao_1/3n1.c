#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int ciclo(int a, int cont){

    if (a == 1){
        return cont+1;
    }else if (a%2 == 0){
        return ciclo(a/2, cont+1);
    }else{
        return ciclo(a*3 + 1, cont +1);
    }

}


int rec(int n, int m, int cont){
    if (n == m){
        return cont;
    }else{
        int c = ciclo(n, 0);

        if (c > cont){
            cont = c;
            return rec(n+1, m, cont);
        }else{
            return rec(n+1, m, cont);
        }
    }
}
/*
int entrada(){

    int a, b;

    if (scanf("%d%d", &a, &b) == 2){
        //scanf("%d", &b);
        printf("%d\n", rec(a, b, 0));
        entrada();
    }
}
*/

void lerPares() {
    char linha[100];
    int a, b;

    if (fgets(linha, sizeof(linha), stdin) != NULL) {
        // Se a linha for só um "enter" (linha vazia ou só com \n), chama recursão
        if (linha[0] == '\n') {
            lerPares();  // Chama a função novamente
        }
        // Tenta extrair dois inteiros da linha
        else if (sscanf(linha, "%d %d", &a, &b) == 2) {
            // Se conseguir ler dois inteiros, imprime o par
            printf("%d\n", rec(a, b, 0));

            // Chama a função novamente
            lerPares();
        }
        // Se a linha não tiver dois inteiros, simplesmente para
    }
}

int main(){

    lerPares();
    
    return 0;

}