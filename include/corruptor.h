#ifndef CORRUPTOR_H
#define CORRUPTOR_H "corruptor.h"


const char* __USAGE_HELP = "USAGE: \n\
    corruptor [files] [flags]";

const char* __OPTIONS = "OPTIONS: \n\
    -V  --version       Print the version corruptor-cli \n\
    -v  --verbose       Use verbose output\n\
    -q  --quiet         Use quiet mode to suppress output.\n\
                        Note that this option also supresses error messages\n\
                        to show error messages, use --show-errors\n\
                                                                 \n\
    -h  --help          Prints help information\n\
        --show-errors   Makes errors visible even if -q option is provided.\n";


const char* __FULL_HELP = "USAGE: \n\
    corruptor [files] [flags]\n\
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

#endif // corruptor.h
