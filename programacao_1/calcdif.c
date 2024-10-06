    #include <stdio.h>

    double calc(int n, double x){
        if (n == 0){
            return x;
        }else{
            char a;
            scanf("%s ", &a);
            double b;
            scanf("%lf", &b);

            if (a == 'A'){
                return calc(n-1, x+b);
            }else if(a == 'C'){
                return calc(n-1, b);
            }else if(a == 'S'){
                return calc(n-1, x-b);
            }else if(a == 'M'){
                return calc(n-1, x*b);
            }else if(a == 'D'){
                return calc(n-1, x/b);
            }
        }
    }

    int main(){
        int n;
        double x;
        scanf("%d", &n);
        scanf("%lf", &x);

        x = calc(n, x);

        printf("Valor final: %.2lf\n", x);

        return 0;

    }