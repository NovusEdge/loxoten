#ifndef CORRUPTOR_H
#define CORRUPTOR_H "corruptor.h"

const char* __USAGE_HELP = "USAGE: \n\
    corruptor [flags] [files]";

const char* __OPTIONS = "OPTIONS: \n\
    -V  --version       Print the version corruptor-cli \n\
    -v  --verbose       Use verbose output\n\
    -q  --quiet         Use quiet mode to suppress output.\n\
                        Note that this option also supresses error messages\n\
                        to show error messages, use --show-errors\n\
                                                                 \n\
    -h  --help          Prints help information\n\
        --show-errors   Makes errors visible even if -q option is provided.\n";


const char* FULL_HELP = "USAGE: \n\
    corruptor [flags] [files]\n\
    \n\
    OPTIONS: \n\
        -V  --version       Print the version corruptor-cli \n\
        -v  --verbose       Use verbose output\n\
        -q  --quiet         Use quiet mode to suppress output.\n\
                            Note that this option also supresses error messages\n\
                            to show error messages, use --show-errors\n\
                                                                     \n\
        -h  --help          Prints help information\n\
            --show-errors   Makes errors visible even if -q option is provided.\n";


const char* VALID_FLAGS[] = {
    "-V", "--version",
    "-v", "--verbose",
    "-q", "--quiet",
    "-h", "--help",
    "--show-errors",
};

#endif // corruptor.h
