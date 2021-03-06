#include <stdio.h>
#include <stdint.h>
//#include "../headers/index.h"
#include <stdint.h>

#define MEM_SIZE 4096
int32_t mem[MEM_SIZE];

uint32_t get_address(uint32_t address, int32_t kte){
    /**
     * Calculate a memory index ( mem[idx] ) from \ a{address}
     * note: equivalent return floor( (address + kte) / 4 ); 
     */
    return ( address + kte ) >> 2;
}//End get_address()

int32_t  set_field(int32_t word, uint32_t index, uint32_t mask, int32_t value){
    /**
     * Inserts \ a{mask} bytes from \ a{value} to \ a{word}, startin' from \ a{index}
     */
    return (word & ~(mask << index)) | ((value & mask) << index);
}//End set_field()

int32_t lw(uint32_t address, int32_t kte){
    if( (address + kte) & 0x3 ){
        printf("erro, não alinhado\n");
        return 0;
    }
    return mem[(address + kte) >> 2];
}
int32_t lb(uint32_t address, int32_t kte);
int32_t lbu(uint32_t address, int32_t kte);
void sw(uint32_t address, int32_t kte, int32_t dado){
        /**
     * Write a word in memory
     */
    if( (address % 4) != 0 ){
       printf("erro, não alinhado\n");
       return;
    }
    mem[get_address(address,kte)] = dado;
}
void sb(uint32_t address, int32_t kte, int32_t dado){
    /**
     * Write a byte in memory
     * note: (address + kte) % 4 * 8 -> byte index inside word [0,8,16,24]
     * note: (address + kte) % 4 == (address + kte) & 0x3, because selects
     * the first 2 bits from the word (0b11 = 0x3)
     */
    mem[get_address(address,kte)] = set_field(mem[get_address(address,kte)], ( (address + kte) & 0x3 ) << 3, 0xff, dado);
}


int main(){
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

    for(int i =0; i<=6; i++)
        printf("%.8x\n", mem[i]);
    
    return 0;
}