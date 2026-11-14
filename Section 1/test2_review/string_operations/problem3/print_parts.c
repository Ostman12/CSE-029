#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>


void print_parts(const char* str){
	int index = 0;
	int i = 0;
	while(str[i] != '\0'){
		while(str[i] == ' '){i++;}
		if(str[i] == '\0'){break;}

		printf("%d:",index);
		while(str[i]!= ' ' && str[i] != '\0'){
			putchar(str[i]);
			i++;
		}
		index++;
		printf("\n");
	}
}

int main(int argc, char** argv){
	char line[100];
	while(fgets(line,sizeof(line),stdin) != NULL){
		size_t len = strlen(line);
		if(len > 0 && line[len-1] == '\n'){
			line[len-1] = '\0';
		}
		print_parts(line);	
	}
}
