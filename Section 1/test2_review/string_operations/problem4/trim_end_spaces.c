#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void trim_end_spaces(char* str){
	size_t len = strlen(str);
	int i = len -1;
        while(str[i] == ' '){
		i++;
	}
	str[i+1] = '\0';

}

int main( int argc, char** argv){
	char line[100];
	while(fgets(line,sizeof(line),stdin) != NULL){
		size_t len = strlen(line);
		if(len > 0 && line[len-1] == '\n'){
			line[len-1] = '\0';
		}
		trim_end_spaces(line);
		printf("%s\n",line);
	}
}
