#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stringLib.h"

int gematria(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return c - 'a' + 1;
    }
    if (c >= 'A' && c <= 'Z')
    {
        return c - 'A' + 1;
    }
    return 0;
}

char AZBY(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return 'z' - (c - 'a');
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return 'Z' - (c - 'A');
    }
    return c;
}

int gematriaValue(char *word)
{
    int sum = 0;
    int i = 0;
    while (word[i] != '\0')
    {
        sum += gematria(word[i]);
        i++;
    }
    return sum;
}

char *AZBYString(char *word)
{
    int i = 0;
    while (word[i] != '\0')
    {
        word[i] = AZBY(word[i]);
        i++;
    }
    return word;
}

void gematriaSubStrings(int gematriaVal, char *txt)
{
    int i = 0;
    int printCheck = false;
    for (; txt[i] != '\0'; i++)
    {
        char c = txt[i];
        if (gematria(c) == 0)
        {
            continue;
        }
        int sum = 0;
        int j = i;
        for (; txt[j] != '\0'; j++)
        {
            sum += gematria(txt[j]);
            if (sum >= gematriaVal)
            {
                break;
            }
        }
        if (sum == gematriaVal)
        {
            if (printCheck == true)
            {
                printf("~");
            }
            for (int k = i; k <= j; k++)
            {
                printf("%c", txt[k]);
            }
            printCheck = true;
        }
    }
}

void azbySubStrings(char *word, char *txt)
{
    int i = 0;
    int length = strlen(word);
    char *azbyWord = AZBYString(word);
    int gematriaVal = gematriaValue(azbyWord);
    int printCheck = false;
    for (; txt[i] != '\0'; i++)
    {
        char c = txt[i];
        if (gematria(c) == 0)
        {
            continue;
        }
        int sum = 0;
        int j = i;
        int counter = 0;
        for (; txt[j] != '\0'; j++)
        {
            char c = txt[j];
            if (!(c == azbyWord[counter] || c == azbyWord[length - counter - 1]))
            {
                break;
            }
            counter++;

            sum += gematria(txt[j]);
            if (sum >= gematriaVal)
            {
                break;
            }
        }
        if (sum == gematriaVal)
        {
            if (printCheck == true)
            {
                printf("~");
            }
            for (int k = i; k <= j; k++)
            {
                printf("%c", txt[k]);
            }
            printCheck = true;
        }
    }
}

int weight(char c)
{
    if (97 <= c && c <= 122)
    {
        return (c - 97 + 1);
    }
    else if (65 <= c && c <= 90)
    {
        return (c - 90 + 1);
    }
    return 0;
}
int english(char c)
{
    if (c == 32)
    {
        return true;
    }
    if (97 <= (int)c && (int)c <= 122)
    {
        return true;
    }
    if (65 <= (int)c && (int)c <= 90)
    {
        return true;
    }
    return false;
}

void Anagram(char *w, char *text)
{
    // copying w
    char *word = (char *)malloc(sizeof(char) * WORD);
    strcpy(word, w);
    char c;
    int i;
    int wordWeight = 0;
    for (i = 0; i < strlen(w); i++)
    {
        c = w[i];
        wordWeight += weight(c);
    }
    int wght = 0;
    char *find;
    int pos;
    char *seq = (char *)malloc(sizeof(char) * TXT);
    int counter = 0;
    int flag = false;
    int printCheck = false;

    for (i = 0; i < strlen(text); i++)
    {
        c = text[i];
        // printf("%c",c);
        find = strchr(word, c);
        if (find == NULL && c != 32)
        {
            if (wght == wordWeight)
            {
                if (printCheck == true)
                {
                    printf("~");
                }
                printf("%s", seq);
                i -= counter - 1;
                printCheck = true;
            }
            // reset variables regardless:
            word = (char *)malloc(sizeof(char) * WORD);
            strcpy(word, w);
            seq = (char *)malloc(sizeof(char) * TXT);
            counter = 0;
            wght = 0;
            flag = false;
        }
        else if (english(c) == true && c != 32)
        {
            // this segment removes the found char from it's position
            pos = find - word;
            memmove(&word[pos], &word[pos + 1], strlen(word) - pos);
            seq[counter] = c;
            counter++;
            wght += weight(c);
            flag = true;
        }
        else if (flag != false)
        {
            // if current char is a " ".
            seq[counter] = c;
            counter++;
        }
        if (wght == wordWeight)
        {
            // question print condition
            if (printCheck == true)
            {
                printf("~");
            }
            printf("%s", seq);
            printCheck = true;
            word = (char *)malloc(sizeof(char) * WORD);
            strcpy(word, w);
            seq = (char *)malloc(sizeof(char) * TXT);
            i -= counter - 1;
            counter = 0;
            wght = 0;
            flag = false;
            free(seq);
            free(word);
        }
    }
}
