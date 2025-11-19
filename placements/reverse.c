#include<stdio.h>

int main(){
    int n, rev = 0, temp;

    printf("Enter a number to find the reverse: ");
    scanf("%d", &n);

    temp = n;

    while(temp > 0){
        int d = temp % 10;
        rev = rev * 10 + d;
        temp /= 10;
    }

    printf("The reverse of %d is %d", n, rev);

    return 0;
}
