#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#include "corruptor.h"
#include "errors.h"

unsigned char *generate_random_bytes (size_t num_bytes);

int main(int argc, char const *argv[]) {
    unsigned char* random_bytes = generate_random_bytes(10);
    for (size_t i = 0; i < 10; i++) {
        printf("%d ", (*random_bytes));
        random_bytes++;
    }

    return 0;
}

unsigned char *generate_random_bytes (size_t n){
    srand(time(NULL));
    unsigned char* random_bytes = (unsigned char*)malloc(n*sizeof(unsigned char));
    unsigned char* initial = random_bytes;

    for (size_t i = 0; i < n; i++) {
        unsigned char r_byte = (unsigned char)rand();
        (*random_bytes) = r_byte;
        random_bytes++;
    }
    return initial;
}
