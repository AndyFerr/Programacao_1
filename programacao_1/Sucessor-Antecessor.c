# include<stdio.h>

int AcharValor(char letra, char letras[], int valor, int letrasV[], int cont);

int MenorValor(int totalCada[], int cont, int menor, int indice);


int main(){
    
    // Definindo e lendo os numeros
    int n1, n2, n3, n4;
    scanf("%d%d%d%d", &n1, &n2, &n3, &n4);
    scanf("");
    
    // Definindo e lendo as letras
    char l1, l2, l3, l4;
    scanf(" %c %c %c %c", &l1, &l2, &l3, &l4);
    char letras[4] = {l1, l2, l3, l4};
    int letrasV[4] = {0,0,0,0};
    scanf("");
    
    // Definindo e lendo os valores das letras
    int v1, v2, v3, v4;
    scanf("%d%d%d%d", &v1, &v2, &v3, &v4);
    int valores[4] = {v1, v2, v3, v4};
    
    int media = (n1, n2, n3, n4)/4;

    // Definindo as variáveis dos totais de cada um
    
    int totalCada[4] = {0,0,0,0};
    
    // Determinando o valor de cada letra
    AcharValor('a', letras, v1, letrasV, 0);
    AcharValor('b', letras, v2, letrasV, 0);
    AcharValor('c', letras, v3, letrasV, 0);
    AcharValor('d', letras, v4, letrasV, 0);
    
    if (media > 60){
        totalCada[0] = (n1 + letrasV[0] + (letrasV[0]*1));
        totalCada[1] = (n2 + letrasV[1] + (letrasV[1]*1));
        totalCada[2] = (n3 + letrasV[2] + (letrasV[2]*1));
        totalCada[3] = (n4 + letrasV[3] + (letrasV[3]*1));
    }else if (media > 30){
        totalCada[0] = (n1 + letrasV[0] + (letrasV[0]*0.8));
        totalCada[1] = (n2 + letrasV[1] + (letrasV[1]*0.8));
        totalCada[2] = (n3 + letrasV[2] + (letrasV[2]*0.8));
        totalCada[3] = (n4 + letrasV[3] + (letrasV[3]*0.8));
    }else if (media > 10){
        totalCada[0] = (n1 + letrasV[0] + (letrasV[0]*0.6));
        totalCada[1] = (n2 + letrasV[1] + (letrasV[1]*0.6));
        totalCada[2] = (n3 + letrasV[2] + (letrasV[2]*0.6));
        totalCada[3] = (n4 + letrasV[3] + (letrasV[3]*0.6));
    }else{
        totalCada[0] = (n1 + letrasV[0] + (letrasV[0]*0.4));
        totalCada[1] = (n2 + letrasV[1] + (letrasV[1]*0.4));
        totalCada[2] = (n3 + letrasV[2] + (letrasV[2]*0.4));
        totalCada[3] = (n4 + letrasV[3] + (letrasV[3]*0.4));
    }

    int indice = MenorValor(totalCada, 0, 999, 0);

    if (indice == 0){
        printf("Anderson quem vai pagar o lanche!:D");
    }else if (indice == 1);{
        printf("Guilherme quem vai pagar o lanche!:D");
    }else if (indice == 2){
        printf("Rita quem vai pagar o lanche!:D");
    }else{
        printf("Higor quem vai pagar o lanche!:D");
    }
    
    return 0;
}

int AcharValor(char letra, char letras[], int valor, int letrasV[], int cont){

    if (cont == 4){
        return 0;
    }
    else if (letras[cont] == letra){
        letrasV[cont] = valor;
        return AcharValor(letra, letras, valor, letrasV, cont+1);
    }
    else{
        return AcharValor(letra, letras, valor, letrasV, cont+1);
    }
}

int MenorValor(int totalCada[], int cont, int menor, int indice){
    if (cont == 4){
        return indice;
    }else if(totalCada[cont] < menor){
        menor = totalCada[cont];
        indice = cont;
        return MenorValor(totalCada, cont+1, menor, indice);
    }else{
        return MenorValor(totalCada, cont+1, menor, indice);
    }
}