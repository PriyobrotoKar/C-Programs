#include<stdio.h>

int main(){
    int n, temp, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    temp = n;

    while(temp > 0){
        int d = temp % 10;
        sum = sum + d;
        temp = temp / 10;
    }

    if(n % sum == 0){
        printf("%d is a harshad number", n);
    } else {
        printf("%d is not a harshad number", n);
    }

    return 0;
}
