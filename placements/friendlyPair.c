#include<stdio.h>

int findSumOfFactors(int n){
    int sum = 0;

    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            sum = sum + i;
        }
    }

    return sum;
}

int calculateRatio(int n){
    return findSumOfFactors(n) / n;
}

int main(){
    int n1, n2;

    printf("Enter two numbers: ");
    scanf("%d %d", &n1, &n2);

    if(calculateRatio(n1) == calculateRatio(n2)){
        printf("Its a friendly pair");
    } else {
        printf("Its not a friendly pair");
    }

    return 0;
}
