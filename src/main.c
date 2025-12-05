#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./input.h"
#include "./password.h"

int main(void)
{
    srand(time(NULL));

    int len = get_password_len();
    int use_numbers = get_numbers_flag();
    int use_symbols = get_symbols_flag();

    char *p = create_password(len, use_numbers, use_symbols);

    printf("Password: %s\n", p);
}
