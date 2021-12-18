#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stringLib.h"

// Convert a single character to it's gematria value
int gematria(char c)
{
    // 97 = a, 122 = z
    // 65 = A, 90 = Z
    if (97 <= c && c <= 122)
    {
        return c - 97 + 1;
    }
    if (65 <= c && c <= 90)
    {
        return c - 65 + 1;
    }
    return 0;
}

// Convert a single characted using Atbash cipher
char Atbash(char c)
{
    // 97 = a, 122 = z
    // 65 = A, 90 = Z
    if (97 <= c && c <= 122)
    {
        return 122 - (c - 97);
    }
    else if (65 <= c && c <= 90)
    {
        return 90 - (c - 65);
    }
    return c;
}

// Converting a string to it's gematria value
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

// Encrypting a string using Atbash cipher
char *AtbashString(char *word)
{
    int i = 0;
    while (word[i] != '\0')
    {
        word[i] = Atbash(word[i]);
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

void atbashSubStrings(char *word, char *txt)
{
    int i = 0;
    int length = strlen(word);
    char *atbashWord = AtbashString(word);
    int gematriaVal = gematriaValue(atbashWord);
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
            if (!(c == atbashWord[counter] || c == atbashWord[length - counter - 1]))
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

// Two helper function for Anagram finder
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

int isEqual(char *array1, char *words)
{
    int counter = 0;
    int Array1[128] = {0};
    for (int i = 0; i < strlen(words); ++i)
    {
        Array1[gematria(words[i])] += 1;
    }
    int Array2[128] = {0};
    for (int i = 0; i < strlen(array1); ++i)
    {
        Array2[gematria(array1[i])] += 1;
    }
    for (int i = 0; i < 128; ++i)
    {
        if (i == 32)
        {
            continue;
        }
        else
        {
            if (Array1[i] != 0 && Array2[i] != 0)
            {
                if (Array1[i] == Array2[i])
                {
                    counter += Array1[i];
                }
            }
        }
    }
    if (counter == strlen(words))
    {
        return 1;
    }
    return 0;
}

void Anagram(char *words, char *paragraph)
{
    if (strlen(paragraph) != 0)
    {
        int start = 0;
        int end = 0;
        int count_for_print = 0;
        // char *temp_print = (char *) malloc(strlen(paragraph) + 1);
        char *temp_print = calloc(strlen(paragraph) + 1, sizeof(char));
        // memset(temp_print, 0, strlen(paragraph) + 1);
        while (start < strlen(paragraph) - 1)
        {
            // char *temp_array = (char *) malloc(strlen(paragraph) + 1);
            // memset(temp_array, 0, strlen(paragraph) + 1);
            char *temp_array = calloc(strlen(paragraph) + 1, sizeof(char));
            int flag3 = 0;
            int count_array = 0;
            if (start + strlen(words) < strlen(paragraph))
            {
                for (int i = start; i < strlen(paragraph); ++i)
                {
                    for (int j = 0; j < strlen(words); ++j)
                    {
                        if (paragraph[i] == words[j])
                        {
                            start = i;
                            flag3 = 1;
                            break;
                        }
                    }
                    if (flag3)
                    {
                        break;
                    }
                }
            }
            if (flag3)
            {
                int counter2 = 0;
                int counter3 = start;
                int spaces = 0;
                while (counter2 < strlen(words))
                {
                    if (paragraph[counter3] != ' ')
                    {
                        counter2++;
                        counter3++;
                    }
                    else
                    {
                        spaces++;
                        counter3++;
                    }
                }
                if (counter2 == strlen(words))
                {
                    end = spaces + counter2 + start;
                    if (end <= strlen(paragraph))
                    {
                        for (int i = start; i < end; ++i)
                        {
                            temp_array[count_array] = paragraph[i];
                            count_array++;
                        }
                    }
                    if (isEqual(temp_array, words))
                    {
                        for (int i = 0; i < strlen(temp_array); ++i)
                        {
                            temp_print[count_for_print] = temp_array[i];
                            count_for_print++;
                        }
                        temp_print[count_for_print] = '~';
                        count_for_print++;
                        start += 1;
                    }
                    else
                    {
                        start += 1;
                    }
                }
                else
                {
                    start += 1;
                }
            }
            else
            {
                start += 1;
            }
        }
        if (strlen(temp_print) > 0)
        {
            char *tempy = (char *)calloc(strlen(temp_print), sizeof(char));
            strncpy(tempy, temp_print, count_for_print - 1);
            tempy[strlen(temp_print) - 1] = '\0';
            printf("%s", tempy);
            if (strlen(tempy) == 0)
            {
                printf("\n");
            }
        }
    }
}
