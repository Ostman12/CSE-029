#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

void encode_utf8(uint32_t num, char dest[]){
	dest[0] = 0;
	dest[1] = 0;
	dest[2] = 0;
	dest[3] = 0;

	if(num < 0b10000000){
		dest[0] = num;
	}else if (num < 0b100000000000){
		dest[0] = (num >> 6) | 0b11000000;
		dest[1] = (num & 0b00111111)|0b10000000;
	}else if (num < 0b1000000000000000000){
		dest[0] = (num >> 12) | 0b11100000;
		dest[1] = ((num >> 6) & 0b00111111)|0b10000000;
		dest[2] = (num & 0b00111111) | 0b10000000;
	}else{
		dest[0] = (num >> 18) | 0b11110000;
		dest[1] = ((num >> 12) & 0b00111111) | 0b10000000; 
		dest[2] = ((num >> 6) & 0b00111111) | 0b10000000;
		dest[3] =(num & 0b00111111) | 0b10000000;
	}
}

void print_array(char arr[]){
    for (int i = 0; i < 4; i++) {
        printf("%02X ", (unsigned char)arr[i]);
    }
    printf("\n");
}


int main(int argc, char** argv) {
        char buffer[100];
        char dest[4] = {0};
        while(1) {
                char* maybe_eof = fgets(buffer, sizeof(buffer), stdin);
                if(maybe_eof == NULL) { break; }
                uint32_t num = (uint32_t)strtoul(buffer, NULL, 10); // Convert input string to number
                for (int i = 0; i < 4; i++) dest[i] = 0; //Reset dest to be all 0
                encode_utf8(num, dest);
                print_array(dest);
        }
}
