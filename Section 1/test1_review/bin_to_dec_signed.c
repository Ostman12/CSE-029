#include <stdio.h>
#include <stdint.h>
#include <string.h>

void bin_to_dec_signed(char str[]){
	long result = 0;
	long cur = 1;

	for (int i = strlen(str)-1; i >= 0; i--){
		if(str[i] == '1'){
			if(i == 0){
				result -= cur;
			}else{
				result += cur;
			}
		}

		cur *= 2;
	}	

	printf("%ld\n",result);
}

int main(){
	char line[40];

	while(fgets(line,sizeof(line),stdin) != NULL){
		size_t len = strlen(line);
		if(len > 0 && line[len -1] == '\n'){
			line[len - 1] = '\0';
		}
		bin_to_dec_signed(line);
	}
	return 0;
}
