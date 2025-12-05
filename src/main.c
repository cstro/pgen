#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./input.h"
#include "./password.h"

int main(void)
{
    srand(time(NULL));

    int len = get_password_len();

    char *p = create_password(len);

    printf("Password: %s\n", p);
}
