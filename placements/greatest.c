#include<stdio.h>

int main(){
    int a,b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    if(a > b){
        printf("The greatest number is %d", a);
    }else{
        printf("The greatest number is %d", b);
    }

    return 0;
}
