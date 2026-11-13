#include <string.h>
#include <stdio.h>
#include <stdint.h>

//if ( (c & 0b11000000) == 0b10000000); true when c is a continuation byte
//if ( (c & 0b10000000) == 0b00000000); true when c is a 1 byte lead byte
//if ( (c & 0b11100000) == 0b11000000); true when c is a 2 byte lead byte
//if ( (c & 0b11110000) == 0b11100000); true when c is a 3 byte lead byte
//if ( (c & 0b11111000) == 0b11110000); true when c is a 4 byte lead byte
//
//if ( (c & 0xC0) == 0x80); true when c is a continuation byte
//if ( (c & 0x80) == 0x00); true when c is a 1 byte lead byte
//if ( (c & 0xE0) == 0xC0); true when c is a 2 byte lead byte
//if ( (c & 0xF0) == 0xE0); true when c is a 3 byte lead byte
//if ( (c & 0xF8) == 0xF0); true when c is a 4 byte lead byte

int32_t utf8_strlen(char *s){
	int32_t count = 0;
	for (int i = 0; s[i] != '\0'; i++){
		if((s[i] & 0xC0) != 0x80){count++;}
	}
	return count;
}

