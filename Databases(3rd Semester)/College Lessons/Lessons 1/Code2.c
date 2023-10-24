/*We checked that the binary number saved in Big-endian in memory*/
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>

/*
               0           0    01000001 (65 = 'A')  01000011  (67 = 'C') 
        00000000    00000000    01000001             01000011
*/
 
 
 
 int main(void)
 {
    int k = 16707;

    char *pc;

    pc = &k;

    printf("pc(byte0 address) = %d | pc+1(byte1 address) = %d \n",pc,pc+1);
    printf("k(byte 0) = %c k(byte 1) = %c\n",*pc,*(pc+1));

    return 0;
 }