#include <stdio.h>
#include <stdint.h>
#include <string.h>


int8_t codepoint_size (char str[]){
	unsigned char cp = (unsigned char)str[0];

	if((cp & 0b10000000) == 0b00000000){ return 1; }
	else if ((cp & 0b11100000) == 0b11000000) { return 2; }
	else if ((cp & 0b11110000) == 0b11100000) { return 3; }
	else if ((cp & 0b11111000) == 0b11110000) { return 4; }
	return -1;
} 


int main(){
	char line[50];
	while(fgets(line,sizeof(line),stdin) != NULL){
		size_t len = strlen(line);
		if( len > 0 && line[len -1] == '\n'){
			line[len -1] = '\0';
		}

		printf("%d\n", codepoint_size(line));
	}
}
