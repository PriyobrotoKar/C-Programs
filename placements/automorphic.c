#include<stdio.h>

int power(int x, int y){
    if(y == 0){
        return 1;
    }

    return x * power(x, y-1);
}

int main(){
    int n, digits = 0, temp;

    printf("Enter a number: ");
    scanf("%d", &n);

    temp  = n;

    while(temp > 0){
        digits++;
        temp /= 10;
    }

    int sq = n * n;

    if(sq % power(10,digits) == n){
        printf("%d is an automorphic number", n);
    } else {
        printf("%d is not an automorphic number", n);
    }

    return 0;
}
