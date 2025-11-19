#include<stdio.h>

int power(int x, int y){
    if(y==0){
        return 1;
    }

    return x * power(x, y - 1);
}

int main(){
    int n, p;

    printf("Enter a number and power: ");
    scanf("%d %d", &n, &p);

    int ans = power(n, p);

    printf("The power of %d to %d is %d", n, p, ans);

    return 0;
}
