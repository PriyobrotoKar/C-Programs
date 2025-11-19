#include<stdio.h>

int main(){
    int start, end, sum = 0;

    printf("Enter start and end: ");
    scanf("%d %d", &start, &end);

    for(int i = start; i <= end; i++){
        sum += i;
    }

    printf("Sum of numbers from %d to %d is %d", start, end, sum);

    return 0;
}
