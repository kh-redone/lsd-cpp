#include"exo3_tp1.h"

void check_msb (int num){
    int bits = sizeof(int)*8;
    int one = 1 << (bits-1);
    if(one & num) printf("msb is set");
    else printf("msb is not set");
    return;
}

void print_bits(unsigned char byte){
    int bits = 8;
    unsigned char one = 1 << bits-1;
    for(int i=0 ; i<bits ; i++)
    {
        if(one & byte) printf("1");
        else printf("0");
        one = one >> 1;
    }
    return;
}
