#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "password.h"

char *l_letters = "abcdefghijklmnopqrstuvwxyz";
char *u_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char *numbers = "0123456789";
char *symbols = "!@#$%^&*()_-+={}[]|\\:;\"'<,.?~";

/**
 * Generate a random char from the given charset.
 */
char rand_char(char *charset)
{
    int first = 0;
    int last = strlen(charset);

    int i = rand() % (last - first);

    return charset[i];
}

/**
 * Checks whether a given password containers at least one of each required
 * char types. A lower and upper case letter is always required. A number and symbol
 * is optionally required based on the given flags.
 */
int check_valid_password(char *password, int requires_number, int requires_symbol)
{
    int contains_l_letter = 0;
    int contains_u_letter = 0;
    int contains_number = 0;
    int contains_symbol = 0;

    int len = strlen(password);

    for (int i = 0; i < len; i++)
    {
        char c = password[i];

        if (strchr(l_letters, c))
        {
            contains_l_letter = 1;
        }
        else if (strchr(u_letters, c))
        {
            contains_u_letter = 1;
        }
        else if (strchr(numbers, c))
        {
            contains_number = 1;
        }
        else if (strchr(symbols, c))
        {
            contains_symbol = 1;
        }
    }

    // If we need a number but don't have one, early return 0.
    if (requires_number && !contains_number)
    {
        return 0;
    }

    // If we need a symbol but don't have one, early return 0.
    if (requires_symbol && !contains_symbol)
    {
        return 0;
    }

    // If we get there then we either don't require a number/symbol or require
    // them and have them, so we only need to check for letters.
    return contains_l_letter && contains_u_letter;
}

char *create_password(int len, int numbers_enabled, int symbols_enabled)
{
    // Create the charset that will be used in this password.
    char *charset = malloc(strlen(l_letters) + strlen(u_letters) + 1);
    strcpy(charset, l_letters);
    strcat(charset, u_letters);

    // Add numbers to the charset if enabled
    if (numbers_enabled)
    {
        char *temp = realloc(charset, strlen(charset) + strlen(numbers) + 1);
        if (temp == NULL)
        {
            free(charset);
            return NULL;
        }
        charset = temp;
        strcat(charset, numbers);
    }
    // Add symbols to the charset if enabled
    if (symbols_enabled)
    {
        char *temp = realloc(charset, strlen(charset) + strlen(symbols) + 1);
        if (temp == NULL)
        {
            free(charset);
            return NULL;
        }
        charset = temp;
        strcat(charset, symbols);
    }

    // + 1 to account for the null character to end the string.
    char *password = malloc(len + 1);

    int valid = 0;

    // Keep generating passwords until we get a valid one.
    while (!valid)
    {
        for (int i = 0; i < len; i++)
        {
            password[i] = rand_char(charset);
        }
        // Set the last character to null character to end the string.
        password[len] = '\0';

        valid = check_valid_password(password, numbers_enabled, symbols_enabled);
    }

    return password;
}
