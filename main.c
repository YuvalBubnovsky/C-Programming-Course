#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stringLib.h"

// TXT & Word are defined in header file
char word[WORD];
char txt[TXT];
int gematriaValueWord;

// This will feature a Gematria sequence, an Atbash sequence and an Anagram sequence

int main(void)
{
    initValues();
    // Initialzing pointers to word & array strings
    char *p_word = word;
    char *p_txt = txt;
    gematriaValueWord = getGematriaValue(p_word);
    printf("%s", "Gematria Sequences: ");
    gematriaSequences(p_txt, gematriaValueWord);
    return 0;
}

void initValues()
{
    char input;

    // Recieving user input for word
    int i = 0;
    while (input != '\n' && input != '\t' && input != ' ')
    {
        scanf("%c", &input);
        if (input == '\n' || input == '\t' || input == ' ')
        {
            break;
        }
        if (i == 30)
        {
            break;
        }
        word[i] = input;
        ++i;
    }

    // Recieving user input for text
    i = 0;
    while (input != '~')
    {
        scanf("%c", &input);
        if (input == '~')
        {
            break;
        }
        if (i == 1024)
        {
            break;
        }
        txt[i] = input;
        ++i;
    }
}