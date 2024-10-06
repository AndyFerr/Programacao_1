#include <stdio.h>
#include <stdlib.h>

void atribuirC(double nota[], char curso[], int k, int pos){
    char m;
    double n;
    if (pos == k){
        return;
    }else{
        scanf("%lf", &n);
        scanf("%*c");
        scanf("%c", &m);
        scanf("%*c");
        nota[pos] = n;
        curso[pos] = m;
        return atribuirC(nota, curso, k, pos+1);
    }
}

void ec(double nota[], char curso[], int pos, double *EC){
    if (pos == 10){
        return;
    }
    if (curso[pos] == 'e'){
        *(EC + pos) = nota[pos];
    }
    ec(nota, curso, pos+1, EC);
}

void cc(double nota[], char curso[], int pos, double *CC){
    if (pos == 10){
        return;
    }
    if (curso[pos] == 'c'){
        *(CC + pos) = nota[pos];
    }
    cc(nota, curso, pos+1, CC);
}

int main() {
    
    double nota[10];
    char curso[10];
    
    atribuirC(nota, curso, 10, 0);

    
    
    printf("EC:");
    ec(nota, curso, 0, EC);
    printf("\n");
    printf("CC:");
    cc(nota, curso, 0, CC);



    return 0;
}