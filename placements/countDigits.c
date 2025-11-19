#include<stdio.h>

int main(){
    int n, ncp, count = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    ncp = n;

    while(ncp > 0){
        count++;
        ncp /= 10;
    }

    printf("The number of digits in %d is %d\n", n, count);

    return 0;
}
