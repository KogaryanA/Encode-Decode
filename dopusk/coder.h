#ifndef CODER
#define CODER

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void mutableCaesarEncoder( char* str, int offset);
char* immutableCaesarEncoder(const char* str, int offset);

void mutableCaesarDecoder( char* str, int offset);
char* immutableCaesarDecoder(const char* str, int offset);

void mutableXorCoder(char* str, char* password);
char* immutableXorCoder(const char* str, const char* password);

#endif
