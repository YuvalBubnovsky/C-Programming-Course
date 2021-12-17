#include <stdio.h>
#include <string.h>
#include "stringLib.h"

/*
A simple C program which recieves user input for a word and text (up to 1024 characters)
and runs 3 function on it:
1) Gematria sequence finder - find all characters that correspond the the gematria value of th given word
2) Atbash sequence - find & print only sequences which are the given word or it's reversed value in Atbash cihper - see https://en.wikipedia.org/wiki/Atbash
3) Anagram sequence - find & print all Anagram sequences which are equal to the given word
*/

char word[WORD];
char txt[TXT];

int main(void)
{
    getValues();
    // making a copy of the word so we can manipulate it
    char wordCopy[WORD];
    strcpy(wordCopy, word);

    printf("Gematria Sequences: ");
    gematriaSubStrings(gematriaValue(word), txt);
    printf("\n");

    printf("Atbash Sequences: ");
    atbashSubStrings(word, txt);
    printf("\n");

    printf("Anagram Sequences: ");
    Anagram(wordCopy, txt);
    printf("\n");
}

void getValues()
{
    // Recieves user input
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