/*
    Copyright 2022 All Rights Reserved
    file-corruptor: A Platform Specific file corrupting program.
    @file: loxoten.h
    @author: Aliasgar Khimani (NovusEdge)
    @copyright: CC-BY-4.0
*/

#ifndef LOXOTEN_H
#define LOXOTEN_H "loxoten.h"

// version for the project
#define VERSION   "v1.0.0"

const char* __USAGE_HELP = "USAGE: \n\
    loxoten [flags] [files]";

const char* __FLAGS = "FLAGS: \n\
    -V  --version       Print the version loxoten-cli \n\
    -v  --verbose       Use verbose output\n\
    -q  --quiet         Use quiet mode to suppress output.\n\
    -h  --help          Prints help information\n";


const char* FULL_HELP = "USAGE: \n\
    loxoten [flags] [files]\n\
                            \n\
FLAGS: \n\
        -V  --version       Print the version loxoten-cli \n\
        -v  --verbose       Use verbose output\n\
        -q  --quiet         Use quiet mode to suppress output.\n\
        -h  --help          Prints help information\n";


const char* VALID_FLAGS[] = {
    "-V", "--version",
    "-v", "--verbose",
    "-q", "--quiet",
    "-h", "--help",
};

// Function signatures
unsigned char *generate_random_bytes (size_t num_bytes);
void           corrupt_file(FILE* file, size_t num_bytes);
int            write_random_bytes_to_file(const char* filename, unsigned int num_bytes, bool overwrite);
bool           check_for_help_option(int aargc, const char* aargv[]);
bool           is_valid_flag(const char* flag);
bool           is_flag(const char* flag);
bool           check_if_file_exists(const char* filename);

#endif // loxoten.h
