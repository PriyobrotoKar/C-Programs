#include<stdio.h>

int power(int x, int y){
    if(y == 0){
        return 1;
    }

    return x * power(x, y-1);
}

int main(){
    int n, digits = 0, temp, sum = 0;

    printf("Enter a no.: ");
    scanf("%d", &n);


    temp = n;

    while(temp > 0){
        digits++;
        temp/=10;
    }

    temp = n;

    while(temp > 0){
        int d = temp % 10;
        sum = sum + power(d, digits);
        temp = temp / 10;
    }


    if(sum == n){
        printf("%d is an armstrong no.", n);
    } else {
        printf("%d is not an armstrong no.", n);
    }

    return 0;
}
