#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stringLib.h"

int getGematriaValue(char *word)
{
    int strSize = strlen(word);
    int gValue = 0;
    for (int i = 0; i < strSize; i++)
    {
        if (('a' <= word[i]) && (word[i] <= 'z'))
        {
            gValue += (word[i] - 96);
        }
        else if (('A' <= word[i]) && (word[i] <= 'Z'))
        {
            gValue += (word[i] - 64);
        }
        else
        {
            gValue += 0;
        }
    }
    return gValue;
}

void gematriaSequences(char *txt, int gValueWord)
{
    int i = 0;
    int j = 0;
    int gValueTxt = 0;
    char *toPrint = (char *)malloc(1024 * sizeof(char));
    if (toPrint == NULL)
    {
        printf("Memory Allocation Failed!");
        exit(1);
    }

    for (i = 0; txt[i]; i++)
    {
        gValueTxt = 0;
        for (j = i; txt[j]; j++)
        {
            if (gValueTxt > gValueWord)
            {
                break;
            }
            if (gValueTxt == gValueWord)
            {
                if (gValueTxt != 0)
                {
                    char *toAdd = (char *)malloc(30 * sizeof(char));
                    if (toAdd == NULL)
                    {
                        printf("Memory Allocation Failed!");
                        exit(1);
                    }
                    int temp = 0;
                    for (int k = 0; k < j; k++)
                    {
                        toAdd[temp] = txt[k];
                        temp++;
                    }
                    toAdd[temp] = '~';
                    temp++;
                    // toAdd[temp] = '\0';
                    strcat(toPrint, toAdd);
                }
                break;
            }
            else
            {
                char c = txt[j];
                char *temp_p = &c;
                gValueTxt += getGematriaValue(temp_p);
            }
        }
    }
    printf("%s\n", toPrint);
}
