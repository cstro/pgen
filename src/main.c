#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./input.h"
#include "./password.h"

int main(void)
{
    srand(time(NULL));

    int len = get_password_len();
    int numbers_enabled = get_numbers_flag();
    int symbols_enabled = get_symbols_flag();

    char *p = create_password(len, numbers_enabled, symbols_enabled);

    if (p == NULL)
    {
        puts("Something went wrong generating the password");
        return -1;
    }

    printf("Password: %s\n", p);
}
