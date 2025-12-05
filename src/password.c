#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "password.h"

char rand_char()
{
    char *letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int first = 0;
    int last = strlen(letters);

    int i = rand() % (last - first);

    return letters[i];
}

char *create_password(int len)
{
    // + 1 to account for the null character to end the string.
    char *password = malloc(len + 1);

    for (int i = 0; i < len; i++)
    {
        password[i] = rand_char();
    }

    // Set the last character to null character to end the string.
    password[len] = '\0';

    return password;
}
