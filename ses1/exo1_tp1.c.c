#include<stdio.h>
#include<stdlib.h>

void check_msb (int num){
    int bits = sizeof(int)*8;
    int one = 1 << (bits-1);
    if(one & num) printf("msb is set");
    else printf("msb is not set");
    return;
}

int main(){
    int num;
    printf("print a number: ")
    scanf("%d",&num);
    check_msb(num);
    return 0;
}