#include "stringutils.h"
#include "coder.h"

void mutableCaesarEncoder( char* str, int offset) {
    mutableStrip(str);
    mutableToLower(str);
    int interval = 'z' - 'a' + 1;
    for (int i = 0; i < strlen(str); i++) {
	    str[i] += offset % 26;
	    if(str[i] > 'z') {
            str[i] -= interval;
	    }
    }
}

char* immutableCaesarEncoder(const char* str, int offset) {
    char* strRes = immutableStrip(str);
    mutableToLower(strRes);
    int interval = 'z' - 'a' + 1;
    for (int i = 0; i < strlen(strRes); i++) {
	    strRes[i] = (strRes[i] + (offset % 26));
	    if(strRes[i] > 'z') {
            strRes[i] -= interval;
        }
    }
    return strRes;
}

void mutableCaesarDecoder( char* str, int offset) {
    mutableStrip(str);
    mutableToLower(str);
    int interval = 'z' - 'a' + 1;
    for (int i = 0; i < strlen(str); i++) {
	    str[i] -= offset % 26;
	    if(str[i] < 'a') {
            str[i] += interval;
        }
    }
}

char* immutableCaesarDecoder(const char* str, int offset) {
    char* strRes = immutableStrip(str);
    mutableToLower(strRes);
    int interval = 'z' - 'a' + 1;
    for (int i = 0; i < strlen(strRes); i++) {
	    strRes[i] = (strRes[i] - (offset % 26));
	    if(strRes[i] < 'a') {
            strRes[i] += interval;
        }
    }
    return strRes;
}

void mutableXorCoder(char* str, char* password) {
    mutableStrip(str);
    mutableToLower(str);
    for (int i = 0; i < strlen(str); i++) {
	    str[i] ^= password[i % strlen(password)];
    }
}

char* immutableXorCoder(const char* str, const char* password) {
    char* strRes = immutableStrip(str);
    mutableToLower(strRes);
    for (int i = 0; i < strlen(strRes); i++) {
	    strRes[i] ^= password[i % strlen(password)];
    }
    return strRes;
}
