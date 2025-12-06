#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <getopt.h>
#include "./password.h"

void print_usage(const char *program_name)
{
    printf("Usage: %s [OPTIONS]\n", program_name);
    printf("Generate a random password\n\n");
    printf("Options:\n");
    printf("  -l, --length=LEN     Password length (default: 20)\n");
    printf("  -n, --numbers        Include numbers\n");
    printf("  -s, --symbols        Include symbols\n");
    printf("  -h, --help           Show this help message\n");
    printf("\nExamples:\n");
    printf("  %s\n", program_name);
    printf("  %s -l=16 -ns\n", program_name);
    printf("  %s --length=20 --numbers --symbols\n", program_name);
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    int len = 20;
    int numbers_enabled = 0;
    int symbols_enabled = 0;

    static struct option long_options[] = {
        {"length", required_argument, 0, 'l'},
        {"numbers", no_argument, 0, 'n'},
        {"symbols", no_argument, 0, 's'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0},
    };

    int opt;

    while ((opt = getopt_long(argc, argv, "l::nsh", long_options, NULL)) != -1)
    {
        switch (opt)
        {
        case 'l':
        {
            int len_arg = atoi(optarg);
            if (len_arg <= 0)
            {
                fprintf(stderr, "Error: Length must be positive\n");
                return 1;
            }
            len = len_arg;
            break;
        }
        case 'n':
            numbers_enabled = 1;
            break;
        case 's':
            symbols_enabled = 1;
            break;
        case 'h':
            print_usage(argv[0]);
            return 0;
        }
    }

    char *password = create_password(len, numbers_enabled, symbols_enabled);

    if (password == NULL)
    {
        puts("Something went wrong generating the password");
        return -1;
    }

    printf("\n%s\n", password);
}
