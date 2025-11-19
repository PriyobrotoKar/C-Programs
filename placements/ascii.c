#include<stdio.h>

int main(){
    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);

    int ascii = ch;

    printf("The ASCII value of '%c' is %d\n", ch, ascii);

    return 0;
}
