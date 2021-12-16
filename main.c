#include <stdio.h>
#include <string.h>
#include "stringLib.h"

char word[WORD];
char txt[TXT];

int main(void)
{
    getValues();
    char wordCopy[WORD];
    strcpy(wordCopy, word);
    printf("Gematria Sequences: ");
    gematriaSubStrings(gematriaValue(word), txt);
    printf("\n");
    printf("Atbash Sequences: ");
    azbySubStrings(word, txt);
    printf("\n");
    printf("Anagram Sequences: ");
    Anagram(wordCopy, txt);
    printf("\n");
}

void getValues()
{
    char input;
    int i = 0;
    while (input != '\n' && input != '\t' && input != ' ')
    {
        scanf("%c", &input);
        if (input == '\n' || input == '\t' || input == ' ' || i == WORD)
        {
            break;
        }
        word[i] = input;
        i++;
    }
    i = 0;
    while (input != '~')
    {
        scanf("%c", &input);
        if (input == '~' || i == TXT)
        {
            break;
        }
        txt[i] = input;
        i++;
    }
}