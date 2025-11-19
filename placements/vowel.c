#include<stdio.h>
#include<ctype.h>

int main(){
    char ch;
    int isVowel = 0;

    printf("Enter a character: ");
    scanf("%c", &ch);

    ch = tolower(ch);

    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'u'){
        isVowel = 1;
    }

    if(isVowel){
        printf("It's a vowel");
    }else {
        printf("It's a consonant");
    }

    return 0;
}
