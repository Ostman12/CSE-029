#include <stdio.h>
#include <stdint.h>
#include <string.h>

int32_t utf8_strlen(char str[]){
	int32_t count = 0;
	for (int i = 0; str[i] != '\0'; i++){
		if((str[i] & 0b11000000) != 0b10000000){
			count++;
		}
	}
	return count;
}

int main(){
	char line[50];

	while(fgets(line,sizeof(line),stdin) != NULL){
		size_t len = strlen(line);
		if(len > 0 && line[len -1] == '\n'){
			line[len -1] = '\0';
		}

		printf("%d\n", utf8_strlen(line));
	}
}

