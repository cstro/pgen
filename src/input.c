#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define OK 0
#define NO_INPUT 1
#define TOO_LONG 2

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

    // Add null terminator as last character.
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
        input = get_input("How long is the password? (8-99): ", buff, sizeof(buff));

        char *p = &buff[0];

        if (*p == '\0')
        {
            printf("❌ Please enter a value\n");
            continue;
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
            printf("❌ Only values 0-9 accepted\n");
            continue;
        }

        int len;
        sscanf(buff, "%d", &len);

        if (len < 8)
        {
            printf("❌ Minimum length is 8\n");
        }
        else if (len > 99 || input == TOO_LONG)
        {
            printf("❌ Maximum length is 99\n");
        }
        else
        {
            return len;
        }
    }
}
