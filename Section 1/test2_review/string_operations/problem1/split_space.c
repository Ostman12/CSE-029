#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


char* split_space(char* s){
	for(int i =0; s[i] !='\0'; i++){
		if(s[i] == ' '){
			s[i] = '\0';
			return &s[i + 1];
		}

	}
	return s;
}

int main (int argc, char** argv){
	char line[100];
	while(fgets(line,sizeof(line),stdin) != NULL){
		size_t len = strlen(line);
		if(len > 0 && line[len-1] == '\n'){
			line[len -1] = '\0';
		}
		char* string2 = split_space(line);
		printf("First String: %s\n",line);
		printf("Split String: %s\n",string2);
	}


}

