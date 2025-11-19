#include<stdio.h>

void printRow(int r){
    int elem = 1;
    printf("%d ", elem);

    for(int i = 1; i <= r; i++){
        elem = elem * (r - i + 1);
        elem = elem / i;
        printf("%d ", elem);
    }

    printf("\n");
}

int main(){
    int n = 4;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            printf(" ");
        }

        printRow(i);
    }

    return 0;
}
