#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "password.h"

char rand_char(char *charset)
{
    int first = 0;
    int last = strlen(charset);

    int i = rand() % (last - first);

    return charset[i];
}

char *create_password(int len, int use_numbers, int use_symbols)
{
    char *letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *numbers = "0123456789";
    char *symbols = "!@#$%^&*()_-+={}[]|\:;\"'<,.?~";

    // Create the charset that will be used in this password.
    char *charset = malloc(strlen(letters) + 1);
    strcpy(charset, letters);

    if (use_numbers)
    {
        realloc(charset, strlen(charset) + strlen(numbers) + 1);
        strcat(charset, numbers);
    }
    if (use_symbols)
    {
        realloc(charset, strlen(charset) + strlen(symbols) + 1);
        strcat(charset, symbols);
    }

    // + 1 to account for the null character to end the string.
    char *password = malloc(len + 1);

    for (int i = 0; i < len; i++)
    {
        password[i] = rand_char(charset);
    }

    // Set the last character to null character to end the string.
    password[len] = '\0';

    return password;
}
