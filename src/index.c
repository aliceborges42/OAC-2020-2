#include "../include/index.h"

uint32_t getAddress(uint32_t address, int32_t kte){
     /*
      * Clacula o index da memória mem[index] do endereço address
      * divide address + kte por 4 - só parte inteira
     */
    return ( address + kte ) >> 2;
}


int32_t  setPosition(int32_t word, uint32_t index, uint32_t mask, int32_t value){
    //insere o value no index certo sem perder o valor anterior da word

    return (word & ~(mask << index)) | (value << index);
}

int32_t  getPosition(int32_t word, uint32_t index, uint32_t mask){

    /*
      *faz shift da da word até o index desejado e
      *pega os dois ultimos bits da word com o mascaramento
    */

    return (word >> index) & mask;
}


int32_t  extendSignal(int32_t word, uint32_t wsize){
    /*
     * Função para extender o sinal de 1 byte para 32 bits
     * se for negativo, extende para um numero negativo
     * senão, extende para positivo
     */
      
     if (word > 0)
        return  word | (-1 << wsize);
     else
        return word; 

}


int32_t lw(uint32_t address, int32_t kte){
    if( (address % 4) != 0 ){
        printf("erro, não alinhado\n");
        return 0;
    }
    return mem[(address + kte) >> 2];
}


int32_t lb(uint32_t address, int32_t kte){

    return extendSignal(lbu(address,kte),8);
}


int32_t lbu(uint32_t address, int32_t kte){

    return getPosition( mem[getAddress(address,kte)], ( (address + kte) % 4) * 8, 0xff);
}


void sw(uint32_t address, int32_t kte, int32_t dado){

    if( (address % 4) != 0 ){
       printf("erro, não alinhado\n");
       return;
    }
    mem[getAddress(address,kte)] = dado;
}


void sb(uint32_t address, int32_t kte, int32_t dado){
    /*
     * (address + kte) % 4 * 8 -> index do byte dentro da word de 32 bits
     */
    mem[getAddress(address,kte)] = setPosition(mem[getAddress(address,kte)], ( (address + kte) % 4) * 8, 0xff, dado);
 
}