#include <stdio.h>
#include "lab9.h"

int main() {
    
    StringBuilder* myBuilder = newBuilder();
    char * word = NULL;
    printf("Size: %d\n", getSize(myBuilder));
    word = toStr(myBuilder);
    printf("Word!: %s\n", word);
    free(word);
    word = NULL;
    printf("Last Index: %d\n", lastIndex(myBuilder, 'a'));
    printf("Last Char: %d\n", (int)lastChar(myBuilder));
    printf("Added char: %d\n", appendChar(myBuilder, 'a'));
    printf("Added char: %d\n", appendChar(myBuilder, 'b'));
    printf("Added char: %d\n", appendChar(myBuilder, 'c'));
    printf("Last Index: %d\n", lastIndex(myBuilder, 'a'));
    printf("Added char: %d\n", appendChar(myBuilder, 'a'));
    printf("Last Index: %d\n", lastIndex(myBuilder, 'a'));
    printf("Adding a word...: %d\n", appendStr(myBuilder, "Words are awesome!"));
    word = toStr(myBuilder);
    printf("Adding a word...: %d\n", appendStr(myBuilder, ""));
    printf("Adding a word...: %d\n", appendStr(myBuilder, ""));
    printf("Word!: %s\n", word);
    printf("Size: %d\n", getSize(myBuilder));
    printf("Last Char: %c\n", lastChar(myBuilder));
    printf("Last Index: %d\n", lastIndex(myBuilder, 'a'));

    free(word);
    destroy(myBuilder);

    return 0;
}