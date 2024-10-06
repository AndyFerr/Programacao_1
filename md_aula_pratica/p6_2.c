#include <stdio.h>

int tam(int a, int b, int cont){
    
    if (a%b == 0){
        return cont;
    }else{
        return tam(b, a%b, cont+1);
    }
}
 
// Calcula os quocientes da divisao euclidiana
// Atribui esses quocientes no array quocientes
int quoc(int quocientes[], int a, int b, int size, int pos){
    if (pos == size){
        return 0;
    }
    else{
        quocientes[pos] = a/b;
        return quoc(quocientes, b, a%b, size, pos+1);
    }  
}

//calcula os valores da variável s e t;
int calcST(int arr[], int size, int quocientes[], int pos){

    if (pos == size){
        return 0;
    }else{
        arr[pos+2] = arr[pos] - (arr[pos+1]*quocientes[pos]);
        return calcST(arr, size, quocientes, pos+1);
    }

}


int main(){
    int a, b;

    scanf("%d%d", &a, &b);
    
    // Se certifica de que a > b
    if (b > a){
        int c = a;
        a = b;
        b = c;
    }

    int size;
    size = tam(a, b, 0);

    int quocientes[size];

    quoc(quocientes, a, b, size, 0);

    int s[size+2];
    int t[size+2];

    // define os 2 primeiros valores de s e t;
    s[0] = 1;
    s[1] = 0;
    t[0] = 0;
    t[1] = 1;

    calcST(s, size, quocientes, 0);
    calcST(t, size, quocientes, 0);

    //printf("%d %d %d %d\n", s[0], s[1], s[2], s[3]);

    printf("s: %d t: %d\n", s[size+1], t[size+1 ]);

}