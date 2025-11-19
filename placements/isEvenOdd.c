#include<stdio.h>

int main(){
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if(n & 1){
        printf("The number is odd.");
    } else {
        printf("The number is even.");
    }

    return 0;
}
