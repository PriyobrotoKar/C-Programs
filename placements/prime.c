#include<stdio.h>

int main(){
    int n, i;

    printf("Enter N:");
    scanf("%d", &n);

    for(i = 2; i * i <= n; i++){
        if(n % i == 0){
            break;
        }
    }

    if(i * i > n ){
        printf("%d is a prime number", n);
    } else {
        printf("%d is not a prime number", n);
    }

    return 0;
}
