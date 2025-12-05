#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define OK 0
#define NO_INPUT 1
#define TOO_LONG 2

int min_len = 8;
int max_len = 99;
int default_len = 20;

/**
 * Safely reads user input
 * https://stackoverflow.com/a/4815781
 */
int get_input(char *prmpt, char *buff, size_t sz)
{
    int ch, extra;

    // If given a prompt the log out to the user.
    if (prmpt != NULL)
    {
        printf("%s", prmpt);
        fflush(stdout);
    }

    if (fgets(buff, sz, stdin) == NULL)
    {
        return NO_INPUT;
    }

    if (buff[strlen(buff) - 1] != '\n')
    {
        extra = 0;
        while (((ch = getchar()) != '\n') && (ch != EOF))
        {
            extra = 1;
        }
        return (extra == 1) ? TOO_LONG : OK;
    }

    // Add null character as last character.
    buff[strlen(buff) - 1] = '\0';
    return OK;
}

/**
 * Request password length from user.
 */
int get_password_len()
{
    char buff[3];
    int input;

    while (1)
    {
        char prmpt[100];
        sprintf(prmpt, "Enter a length between %d and %d (default %d) ", min_len, max_len, default_len);
        input = get_input(prmpt, buff, sizeof(buff));

        char *p = &buff[0];

        if (*p == '\0')
        {
            return default_len;
        }

        int non_digits = 0;

        while (*p != '\0')
        {
            if (!isdigit(*p))
            {
                non_digits = 1;
            }

            ++p;
        }

        if (non_digits)
        {
            puts("❌ Only values 0-9 accepted");
            continue;
        }

        int len;
        sscanf(buff, "%d", &len);

        if (len < min_len)
        {
            printf("❌ Minimum length is %d\n", min_len);
        }
        else if (len > max_len || input == TOO_LONG)
        {
            printf("❌ Maximum length is %d\n", max_len);
        }
        else
        {
            return len;
        }
    }
}

int get_numbers_flag()
{
    char in[2];
    puts("Use numbers in password");
    get_input("Y/N (default Y) ", in, sizeof(in));

    char v = in[0];

    return v == 'Y' || v == 'y' || v == '\0';
}

int get_symbols_flag()
{
    char in[2];
    puts("Use symbols in password");
    get_input("Y/N (default N) ", in, sizeof(in));

    char v = in[0];

    return v == 'Y' || v == 'y';
}

int get_another_password()
{
    char in[2];
    puts("Generate another password?");
    get_input("Y/N (default Y) ", in, sizeof(in));

    char v = in[0];

    return v == 'Y' || v == 'y' || v == '\0';
}
