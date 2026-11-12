#include <stdio.h>
#include <stdint.h>
#include <string.h>

uint8_t is_ascii(char str[]){
	for (int i = 0; str[i] != '\0'; i++){
		if(str[i] & 0b10000000){
			return 0;
		}
	}
	return 1;
}

int main(){
	char line[100];
	while(fgets(line,sizeof(line),stdin) != NULL){
		size_t len = strlen(line);
		if(len > 0 && line[len -1] == '\n'){
			line[len -1] = '\0';
		}
		printf("%d\n",is_ascii(line));
	}
}
