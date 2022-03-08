/*
    Copyright 2022 All Rights Reserved
    file-corruptor: A Platform Specific File corrupting program.
    @file: corruptor.c
    @author: Aliasgar Khimani (NovusEdge)
    @copyright: CC-BY-4.0
*/

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<errno.h>


#include "corruptor.h"
#include "errors.h"

unsigned char *generate_random_bytes (size_t num_bytes);
int           *generate_random_numbers(size_t n);
int            write_random_bytes_to_file(const char* filename, unsigned int num_bytes, bool overwrite);
bool           check_for_help_option(int aargc, char const* aargv[]);
bool           is_valid_flag(const char* flag);

int main(int argc, char const* argv[]) {
    bool quiet_flag = false,
         verbose_flag = false,
         version_flag = false,
         show_err_flag = false;

    // Parsing command line flags.
    for (int i = 1; i < argc; i++) {
        if (check_for_help_option(argc, argv)) {
            printf("%s\n", FULL_HELP);
            exit(EXIT_SUCCESS);
        }

        if(!is_valid_flag(argv[i])) {
            fprintf(stderr, "E: Invalid Flag: %s\n\n%s\n", argv[i], __OPTIONS);
            exit(EXIT_FAILURE);
        }

        if( strncmp(argv[i], "-V", 2) == 0 || strncmp(argv[i], "--version", 9) == 0 ) {
            version_flag = true;
        }

        if( strncmp(argv[i], "-v", 2) == 0 || strncmp(argv[i], "--verbose", 9) == 0 ) {
            verbose_flag = true;
        }

        if( strncmp(argv[i], "-q", 2) == 0 || strncmp(argv[i], "--quiet", 7) == 0 ) {
            quiet_flag = true;
        }

        if( strncmp(argv[i], "--show-errors", 13) == 0 ) {
            show_err_flag = true;
        }
    }
    // printf("-q: %d\n-v: %d\n-V: %d\n--show-errors: %d\n", quiet_flag, verbose_flag, version_flag, show_err_flag);



    exit(EXIT_SUCCESS);
}

/*
    Generates a sequence of random bytes and returns it.
    @param n: Number of bytes to generate
    @return : Pointer to the head of byte sequence.
*/
unsigned char *generate_random_bytes (size_t n){
    srand(time(NULL));
    unsigned char* random_bytes = (unsigned char*)malloc(n*sizeof(unsigned char));
    unsigned char* head = random_bytes;

    for (size_t i = 0; i < n; i++) {
        unsigned char r_byte = (unsigned char)rand();
        (*random_bytes) = r_byte;
        random_bytes++;
    }

    return head;
}

/*
    Generates a sequence of random numbers.
    @param n: Specifies the amount of numbers to generate
    @return: The pointer to the head of the sequence.
*/
int *generate_random_numbers(size_t n) {
    srand(time(NULL));
    int* random_numbers = (int*)malloc(n*sizeof(int));
    int* head = random_numbers;

    for (size_t i = 0; i < n; i++) {
        int r_int = (int)rand();
        (*random_numbers) = r_int;
        random_numbers++;
    }

    return head;
}

/*
    Checks if the -h or --help flags have been passed into command line
    arguments.
*/
bool check_for_help_option(int aargc, char const* aargv[]){
    for (int i = 0; i < aargc; i++) {
        if ( 0 == strncmp("-h", aargv[i], 2) | 0 == strncmp("--help", aargv[i], 6)){
            return true;
        }
    }
    return false;
}

/*
    Checks if flag passed to the CLI is a valid flag or not.
*/
bool is_valid_flag(const char* flag) {
    bool check = false;
    for (size_t i = 0; i < 9; i++) {
        if( strcmp(flag, VALID_FLAGS[i]) == 0 ) { check = true; }
    }
    return check;
}
