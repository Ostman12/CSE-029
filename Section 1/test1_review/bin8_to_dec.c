#include <stdio.h>
#include <stdint.h>
#include <string.h>

int8_t bin8_to_dec(char binary[]){
	int8_t result = 0;
	int cur = 1;
	if(binary[0] == '1'){
		result = -128;
		for(int i = 7; i > 0; i--){
			if(binary[i] == '1'){
				result += cur;
			}
			cur *= 2;
		}
	}else{
		for(int i = 7; i > 0; i--){
			if(binary[i] == '1'){
				result += cur;
			}
			cur *= 2;
		}
	}
	return result;
}



int main(){
	char line[10];

	while (fgets(line, sizeof(line), stdin) != NULL){
		size_t len = strlen(line);
		if(len > 0 && line[len -1] == '\n'){
			line[len - 1] = '\0';
		}
		
		printf("%d\n",bin8_to_dec(line));
	}
	return 0;
}
