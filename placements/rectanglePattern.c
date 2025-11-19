#include<stdio.h>

int main(){
    int r = 3, c = 8;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
