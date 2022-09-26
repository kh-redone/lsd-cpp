#include<stdio.h>
#include<stdlib.h>


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


int main(){
    unsigned char x;
    printf("enter a number:  ");
    scanf("%d",&x);
    print_bits(x);
    return 0;
}