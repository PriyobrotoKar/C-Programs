#include<stdio.h>

int main(){
    int n, temp, rev = 0;

    printf("Enter a no: ");
    scanf("%d", &n);

    temp = n;

    while(temp > 0){
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }

    if(rev == n){
        printf("%d is a palindrome no.\n", n);
    } else {
        printf("%d is not a palindrome no.\n", n);
    }


    return 0;
}
