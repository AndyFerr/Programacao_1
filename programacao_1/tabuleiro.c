#include <stdio.h>

void atribuir(int arr[], int n, int cont){
    int m;
    if (cont == n){
        return;
    }else{
        scanf("%d", &m);
        arr[cont] = m;
        return atribuir(arr, n, cont+1);
    }
}


void atribuirExtended(int arr1[], int arr2[], int arr3[], int arr4[], int n, int cont){
    int a, b, c, d;
    if (cont == n){
        return;
    }else{
        scanf("%d %d %d %d", &a, &b, &c, &d);
        arr1[cont] = a;
        arr2[cont] = b;
        arr3[cont] = c;
        arr4[cont] = d;

        return atribuirExtended(arr1, arr2, arr3, arr4, n, cont+1);
    }
}

int rod(int tabuleiro[], int jogador[], int tamTabuleiro, int tamJogador, int posTabuleiro, int posJogador, int pontuacao){
    
    if (posJogador == tamJogador) return pontuacao;

    posTabuleiro += jogador[posJogador];

    if (posTabuleiro >= tamTabuleiro){
        posTabuleiro = posTabuleiro - tamTabuleiro;
    }

    if (tabuleiro[posTabuleiro] == 1) pontuacao += 10;
    if (tabuleiro[posTabuleiro] == 2) pontuacao += 15;
    if (tabuleiro[posTabuleiro] == 5) pontuacao -= 5;
    if (tabuleiro[posTabuleiro] == 7) pontuacao += jogador[posJogador];
    if (tabuleiro[posTabuleiro] == 9) pontuacao -= 20;

    if (pontuacao < 0) pontuacao = 0;

    return rod(tabuleiro, jogador, tamTabuleiro, tamJogador, posTabuleiro, posJogador+1, pontuacao);
}

int main(){
    int tamTabuleiro;

    scanf("%d", &tamTabuleiro);

    int tabuleiro[tamTabuleiro];
    int tamJogador;

    atribuir(tabuleiro, tamTabuleiro, 0);

    scanf("%d", &tamJogador);
    int T[tamJogador], D[tamJogador], V[tamJogador], H[tamJogador];
    atribuirExtended(T, D, V, H, tamJogador, 0);

    int tenorio = rod(tabuleiro, T, tamTabuleiro, tamJogador, 0, 0, 0);
    int davi = rod(tabuleiro, D, tamTabuleiro, tamJogador, 0, 0, 0);
    int vitor = rod(tabuleiro, V, tamTabuleiro, tamJogador, 0, 0, 0);
    int humberto = rod(tabuleiro, H, tamTabuleiro, tamJogador, 0, 0, 0);


    if (tenorio > davi && tenorio > vitor && tenorio > humberto) printf("Tenorio venceu!\n");
    else if (davi > tenorio && davi > vitor && davi > humberto) printf("Davi venceu!\n");
    else if(vitor > tenorio && vitor > davi && vitor > humberto) printf("Vitor venceu!\n");
    else if(humberto > tenorio && humberto > davi && humberto > vitor) printf("Humberto venceu!\n");
    else{
        printf("Houve um empate!\n");
    }
}