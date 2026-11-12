#include <stdio.h>
#include <stdint.h>
#include <string.h>

void bin_to_dec(char str[]){
	int32_t result = 0;
	int cur = 1;

	for (int i = strlen(str) -1; i >= 0; i--){
		if(str[i] == '1'){
			result += cur;
		}
		cur *= 2;
	}

	printf("%u\n",result);
}

int main(){
	char line[40];
	while(fgets(line,sizeof(line),stdin) != NULL){
		size_t len = strlen(line);
		if (len > 0 && line[len -1] == '\n'){
			line[len -1] = '\0';
		}
		bin_to_dec(line);
	}	
}
