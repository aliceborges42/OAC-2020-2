#include <stdio.h>
#include <stdint.h>
#include "../include/index.h"

void main(void){

    //Iniciaando a memória 
    sb(0, 0, 0x04); 
    sb(0, 1, 0x03); 
    sb(0, 2, 0x02); 
    sb(0, 3, 0x01);
    sb(4, 0, 0xFF); 
    sb(4, 1, 0xFE); 
    sb(4, 2, 0xFD); 
    sb(4, 3, 0xFC);
    sw(12, 0, 0xFF);
    sw(16, 0, 0xFFFF);
    sw(20, 0, 0xFFFFFFFF);
    sw(24, 0, 0x80000000);

//imprimindo a memória
    for(int i =0; i<=6; i++)
        printf("mem[%d] = %.8x\n", i, mem[i]);
    
    printf("\n/////////////\n");
    printf("lb(4,0) = %.8x\n", lb(4,0));
    printf("lb(4,1) = %.8x\n", lb(4,1));
    printf("lb(4,2) = %.8x\n", lb(4,2));
    printf("lb(4,3) = %.8x\n", lb(4,3));
    //printf("----------------\n");
    // for(int i =0; i<=6; i++)
    //     printf("%.8x\n", mem[i]);
    printf("\n/////////////\n");
    printf("lbu(4,0) = %.8x\n", lbu(4,0));
    printf("lbu(4,1) = %.8x\n", lbu(4,1));
    printf("lbu(4,2) = %.8x\n", lbu(4,2));
    printf("lbu(4,3) = %.8x\n", lbu(4,3));
    printf("\n/////////////\n");
    printf("lw(12,0) = %.8x\n", lw(12,0));
    printf("lw(16,0) = %.8x\n", lw(16,0));
    printf("lw(20,0) = %.8x\n", lw(20,0));
   

}