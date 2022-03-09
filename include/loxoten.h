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

const char* __OPTIONS = "OPTIONS: \n\
    -V  --version       Print the version loxoten-cli \n\
    -v  --verbose       Use verbose output\n\
    -q  --quiet         Use quiet mode to suppress output.\n\
    -h  --help          Prints help information\n\
    -n  --num-bytes     Specifies the number of bytes to write to the given\n\
                        files.\n";


const char* FULL_HELP = "USAGE: \n\
    loxoten [flags] [files]\n\
                            \n\
OPTIONS: \n\
        -V  --version       Print the version loxoten-cli \n\
        -v  --verbose       Use verbose output\n\
        -q  --quiet         Use quiet mode to suppress output.\n\
        -h  --help          Prints help information\n\
        -n  --num-bytes     Specifies the number of bytes to write to the given\n\
                            files.\n";


const char* VALID_FLAGS[] = {
    "-V", "--version",
    "-v", "--verbose",
    "-q", "--quiet",
    "-h", "--help",
    "-n", "--num-bytes",
};

#endif // loxoten.h
