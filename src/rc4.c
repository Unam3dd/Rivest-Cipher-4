#include "rc4.h"

#ifdef __unix__
    #include <stdio.h>
#endif

void print_hex(unsigned char *str)
{
    while (*str)
        printf("%02X", *(str)++);
}

unsigned int RC4_cipher(unsigned char *input, unsigned char *key, unsigned char *buffer, unsigned long buffer_size, unsigned long size_key)
{
    if (!input || !key || size_key == 0 || buffer_size == 0 )
        return (1);
    
    unsigned char S[0x100] = {0};
    unsigned char tmp = 0, byte = 0;
    int i = 0, j = 0;

    for (i = 0; i < 0x100; i++)
        S[i] = i;
    
    j = 0;

    for (i = 0; i < 0x100; i++) {
        j = (j + S[i] + key[i % size_key]) % 0x100;
        
        // swap(S[i], S[j])
        tmp = S[j];
        S[j] = S[i];
        S[i] = tmp;
    }

    i = 0;
    j = 0;

    while (*input) {
        i = (i + 1) % 0x100;
        j = (j + S[i]) % 0x100;
        
        // swap(S[i], S[j])
        tmp = S[j];
        S[j] = S[i];
        S[i] = tmp;

        byte = S[(S[i] + S[j]) % 0x100];
        *buffer = (byte ^ *input);
        buffer++;
        input++;
    }

    return (0);
}