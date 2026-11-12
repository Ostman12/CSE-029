#include <stdio.h>
#include <stdint.h>
#include <string.h>

void print_backwards(char str[]){
	for(int i = strlen(str) -1; i >= 0; i--){printf("%c %d\n",str[i],str[i]);}
}

int main(){
	char line[50];
	while(fgets(line,sizeof(line),stdin) != NULL){
		size_t len = strlen(line);
		if(len > 0 && line[len - 1] == '\n'){
			line[len -1] = '\0';
		}
		print_backwards(line);
	}
}
