#ifndef __INDEX_H__
#define __INDEX_H__

#include <stdio.h>
#include <stdint.h>

#define MEM_SIZE 4096
int32_t mem[MEM_SIZE];

inline uint32_t get_address(uint32_t address, int32_t kte){
    /**
     * Calculate a memory index ( mem[idx] ) from \ a{address}
     * note: equivalent return floor( (address + kte) / 4 ); 
     */
    return ( address + kte ) >> 2;
}//End get_address()

inline int32_t  set_field(int32_t word, uint32_t index, uint32_t mask, int32_t value){
    /**
     * Inserts \ a{mask} bytes from \ a{value} to \ a{word}, startin' from \ a{index}
     */
    return (word & ~(mask << index)) | ((value & mask) << index);
}//End set_field()

inline int32_t lw(uint32_t address, int32_t kte){
    if(!((address + kte)%4)){
        printf("erro, não alinhado\n");
        return 0;
    }
    return mem[(address + kte) >> 2];
}
int32_t lb(uint32_t address, int32_t kte);
int32_t lbu(uint32_t address, int32_t kte);
inline void sw(uint32_t address, int32_t kte, int32_t dado){
        /**
     * Write a word in memory
     */
    if(!((address + kte)%4) ){
       printf("erro, não alinhado\n");
       return;
    }
    mem[get_address(address,kte)] = dado;
}
inline void sb(uint32_t address, int32_t kte, int32_t dado){
    /**
     * Write a byte in memory
     * note: (address + kte) % 4 * 8 -> byte index inside word [0,8,16,24]
     * note: (address + kte) % 4 == (address + kte) & 0x3, because selects
     * the first 2 bits from the word (0b11 = 0x3)
     */
    mem[get_address(address,kte)] = set_field(mem[get_address(address,kte)], ( (address + kte) & 0x3 ) << 3, 0xff, dado);
}


#endif