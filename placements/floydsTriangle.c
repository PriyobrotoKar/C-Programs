#include<stdio.h>

int main(){
    int r = 5, k = 1;


    for(int i = 0; i < r; i++){
        for(int j = 0; j < i + 1; j++){
            printf("%d ", k++);
        }
        printf("\n");
    }

    return 0;
}
