#include <stdio.h>
#include <stdint.h>
#include <string.h>

int32_t capitalize(char str[]){
	int count = 0;
	for(int i = 0; str[i] != '\0'; i++){
		if(str[i] >= 'a' && str[i] <= 'z'){
			str[i] -= ('a' - 'A');
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

		printf("%d %s\n", capitalize(line),line);
	}
}
