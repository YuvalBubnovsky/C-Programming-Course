#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define WORD 30
#define TXT 1024

void getValues();
int gematria(char c);
char Atbash(char c);
char *AtbashString(char *word);
int gematriaValue(char *word);
void gematriaSubStrings(int gematriaVal, char *txt);
void atbashSubStrings(char *word, char *txt);
void Anagram(char *w, char *text);
int weight(char c);
int english(char c);
int isEqual(char *string, char *word);