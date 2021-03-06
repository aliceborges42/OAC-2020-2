// #include "../headers/index.h"

// int32_t lw(uint32_t address, int32_t kte){
//     if(!((address + kte)%4)){
//         printf("erro, não alinhado\n");
//         return 0;
//     }
//     return mem[(address + kte) >> 2];
// }

// void sw(uint32_t address, int32_t kte, int32_t dado){
//     /**
//      * Write a word in memory
//      */
//     if(!((address + kte)%4) ){
//        printf("erro, não alinhado\n");
//        return;
//     }
//     mem[get_address(address,kte)] = dado;
// }//End sw() 

// void sb(uint32_t address, int32_t kte, int8_t dado){
//     /**
//      * Write a byte in memory
//      * note: (address + kte) % 4 * 8 -> byte index inside word [0,8,16,24]
//      * note: (address + kte) % 4 == (address + kte) & 0x3, because selects
//      * the first 2 bits from the word (0b11 = 0x3)
//      */
//     mem[get_address(address,kte)] = set_field(mem[get_address(address,kte)], ( (address + kte) & 0x3 ) << 3, 0xff, dado);
// }