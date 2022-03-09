/*
    Copyright 2022 All Rights Reserved
    file-corruptor: A Platform Specific file corrupting program.
    @file: loxoten.c
    @author: Aliasgar Khimani (NovusEdge)
    @copyright: CC-BY-4.0
*/

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>

#include "loxoten.h"
#include "fancy_console.h"

// Command line flags...
bool quiet_flag     = false,
     verbose_flag   = false;


int main(int argc, const char* argv[]) {
    int flag_end_pos = 1;

    // Parsing command line flags.
    for (int i = 1; i < argc; i++) {
        if (check_for_help_option(argc, argv)) {
            printf("%s\n", FULL_HELP);
            exit(EXIT_SUCCESS);
        }

        if( is_flag(argv[i]) && !is_valid_flag(argv[i]) ) {
            fprintf(stderr, "E: Invalid Flag: %s\n\n%s\n", argv[i], __FLAGS);
            exit(EXIT_FAILURE);
        }

        if( strncmp(argv[i], "-V", 2) == 0 || strncmp(argv[i], "--version", 9) == 0 ) {
            printf("loxoten version: %s\n", VERSION);
            exit(EXIT_SUCCESS);
        }

        if( strncmp(argv[i], "-v", 2) == 0 || strncmp(argv[i], "--verbose", 9) == 0 ) {
            verbose_flag = true;
            flag_end_pos++;
        }

        if( strncmp(argv[i], "-q", 2) == 0 || strncmp(argv[i], "--quiet", 7) == 0 ) {
            quiet_flag = true;
            flag_end_pos++;
        }
    }

    for(int i = flag_end_pos; i < argc; i++) {
        if( !check_if_file_exists(argv[i]) ) {
            if ( !quiet_flag || verbose_flag ){
                fprintf(stderr, "%s[-] E: File %s does not exist!%s\n", ANSI_COLOR_RED, argv[i], ANSI_COLOR_RESET);
            }
            exit(EXIT_FAILURE);
        }
        FILE* fd = fopen(argv[i], "rb+");

        if( !quiet_flag || verbose_flag ) {
            printf("%s[*] Attempting to corrupt file: %s%s\n\n", ANSI_COLOR_YELLOW, argv[i], ANSI_COLOR_RESET);
        }

        fseek(fd, 0L, SEEK_END); int filesize = ftell(fd); rewind(fd);
        corrupt_file(fd, filesize);

    }
    exit(EXIT_SUCCESS);
}

/*
    Corrupts given file by writing num_bytes number of randomly generated
    bytes to the file's memory.
    @param file     : file_ptr to the file to be corrupted
    @param num_bytes: number of bytes to write into the file.
*/
void corrupt_file(FILE* file, size_t num_bytes){
    unsigned char* random_bytes = generate_random_bytes(num_bytes);

    for(int i = 0; i < num_bytes; i++ ) {
        fwrite(random_bytes, sizeof(unsigned char), 1, file);
        random_bytes++;
    }
}


/*
    Generates a sequence of random bytes and returns it.
    @param n: Number of bytes to generate
    @return : Pointer to the head of byte sequence.
*/
unsigned char *generate_random_bytes (size_t n){
    srand(time(NULL));
    unsigned char* random_bytes = (unsigned char*)malloc(n*sizeof(unsigned char));
    unsigned char* head         = random_bytes;

    for (size_t i = 0; i < n; i++) {
        unsigned char r_byte = (unsigned char)rand();
        (*random_bytes)      = r_byte;
        random_bytes++;
    }

    return head;
}

/*
    Checks if the -h or --help flags have been passed into command line
    arguments.
    @param aargc: Count of command line arguments
    @param aargv: Command line arguments
    @return     : true if either "-h" or "--help" is in the command line
                  arguments.
*/
bool check_for_help_option(int aargc, const char* aargv[]){
    for (int i = 0; i < aargc; i++) {
        if ( 0 == strncmp("-h", aargv[i], 2) | 0 == strncmp("--help", aargv[i], 6)){
            return true;
        }
    }
    return false;
}

/*
    Checks if flag passed to the CLI is a valid flag or not.
    @param flag: command line flag to be checked
    @return    : true if [flag] is a valid command line flag for this program
*/
bool is_valid_flag(const char* flag) {
    bool check = false;
    for (size_t i = 0; i < 8; i++) {
        if( strcmp(flag, VALID_FLAGS[i]) == 0 ) { check = true; }
    }
    return check;
}

/*
    Checks if the string "flag" is a flag. A flag is a string starting with "-"
    @param flag: string passed into the command line arguments.
    @return    : true if [flag] is a command line flag.
*/
bool is_flag(const char* flag) {
    return strncmp(flag, "-", 1) == 0;
}

/*
    Checks if a file exists.
    @param filename: Path to the/Name of the file to be checked.
    @return        : true if [filename] exists.
*/
bool check_if_file_exists(const char* filename) {
    return access(filename, F_OK) == NULL;
}
