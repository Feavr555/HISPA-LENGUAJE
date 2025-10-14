#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#define __isLetter(l) ((l >= '0' && l <='9') || (l >= 'A' && l <='Z') || (l >= 'a' && l <='z'))

char *__read(const char *file);
char* __follow(const char *const buffer,int *n);
bool __print(const char*const _string,int *n);
bool ___interpeter(const char*const buffer);
bool __interpeter(const char*const buffer);
bool viewError(char *buffer,uint32_t index);

