#include<stdio.h>
#include<ctype.h>

int main(){
    char ch;
    int isAlphabet = 1;

    printf("Enter a character: ");
    scanf("%c", &ch);

    ch = tolower(ch);

    if(ch < 'a' || ch > 'z'){
        isAlphabet = 0;
    }

    if(isAlphabet){
        printf("The character is an alphabet.\n");
    } else {
        printf("The character is not an alphabet.\n");
    }

    return 0;
}
