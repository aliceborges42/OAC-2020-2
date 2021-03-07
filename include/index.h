#ifndef __INDEX_H__
#define __INDEX_H__

#include <stdio.h>
#include <stdint.h>

#define MEM_SIZE 4096
int32_t mem[MEM_SIZE];

uint32_t getAddress(uint32_t address, int32_t kte);
int32_t  setPosition(int32_t word, uint32_t index, uint32_t mask, int32_t value);
int32_t  getPosition(int32_t word, uint32_t index, uint32_t mask);
int32_t  extendSignal(int32_t word, uint32_t wsize);
int32_t lw(uint32_t address, int32_t kte);
int32_t lb(uint32_t address, int32_t kte);
int32_t lbu(uint32_t address, int32_t kte);
void sw(uint32_t address, int32_t kte, int32_t dado);
void sb(uint32_t address, int32_t kte, int32_t dado);
#endif