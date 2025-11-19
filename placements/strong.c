#include<stdio.h>

int fact(int n){
    int f = 1;

    for(int i = 1; i <= n; i++){
        f *= i;
    }

    return f;
}

int main(){
    int n, temp, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    temp = n;

    while(temp > 0){
        int d = temp % 10;
        int f = fact(d);
        sum = sum + f;
        temp /= 10;
    }

    if(sum == n){
        printf("%d is a strong number", n);
    } else {
        printf("%d is not a strong number", n);
    }


    return 0;
}
