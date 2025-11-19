#include<stdio.h>

int main(){
    int a = 0, b = 1, n;

    printf("Enter N: ");
    scanf("%d", &n);

    printf("The fibonacci series upto %d is : \n", n);

    if(n >= 1){
        printf("%d ", 0);
    }

    if(n >= 2){
        printf("%d ", 1);
    }

    if(n > 2){
        for(int i = 2; i < n; i++){
            int c = a + b;
            printf("%d ", c);
            a = b;
            b = c;
        }
    }

    return 0;
}
