#include <stdio.h>

int tam(int a, int b, int cont){
    
    if (a%b == 0){
        return cont;
    }else{
        return tam(b, a%b, cont+1);
    }
}

// Calcula os quocientes da divisao euclidiana
// Oraganiza no array quociente no sentido inverso da divisão euclidiana
// (o último quociente é o primeiro do array e assim por diante)
int quoc(int quocientes[], int a, int b, int size){
    
    if (a%b == 0){
        return 0;
    }else{
        quocientes[size-1] = a/b;
        return quoc(quocientes, b, a%b, size-1);
    }  

}

//x=1
//y=a

void calcularST(int x, int y, int quocientes[], int st[], int size, int pos){
    if (size > 2){
            if (pos == size-2){
            st[1] = quocientes[pos]*y + x;
            st[2] = quocientes[pos+1]*st[1] + st[pos-1];
        }
        else{
            y = quocientes[pos]*y + x;
            x = quocientes[pos];
            calcularST(x, y, quocientes, st, size, pos+1); 
        }
    }else{
        st[1] = quocientes[pos]*y + x;
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

    quoc(quocientes, a, b, size);

    int st[3];

    st[0] = quocientes[0];

    calcularST(1, st[0], quocientes, st, size, 1);

    if (size > 2){
        if (size%2 == 0){
            st[1] = st[1]*(-1);
        }else{
            st[2] = st[2]*(-1);
        }

        printf("s: %d t: %d\n", st[1], st[2]);
    }else{
        printf("s: %d t: %d\n", st[0]*(-1), st[1]);
    }

}

/*
#include <stdio.h>

int tam(int a, int b, int cont){
    
    if (a%b == 0){
        return cont;
    }else{
        return tam(b, a%b, cont+1);
    }
}

int quoc(int quocientes[], int a, int b, int size){
    
    if (a%b == 0){
        return 0;
    }else{
        quocientes[size-1] = a/b;
        return quoc(quocientes, b, a%b, size-1);
    }  

}

void printArray(int arr[], int n, int pos){
    if (pos == n){
        return;
    }else{
        printf("%d\n", arr[pos]);
        printArray(arr, n, pos+1);
    }
}

int main() {
    int a, b;
    
    scanf("%d%d", &a, &b);
    
    int size;
    size = tam(a, b, 0);

    int quocientes[size];

    quoc(quocientes, a, b, size);
    
    printArray(quocientes, size, 0);

    return 0;
}
*/