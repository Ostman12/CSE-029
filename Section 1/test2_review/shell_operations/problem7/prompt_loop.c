#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>


void prompt_command_loop(){
	char line[1001];
	while(fgets(line,sizeof(line),stdin) != NULL){
		size_t len = strlen(line);
		if(len > 0 && line[len-1] == '\n'){
			line[len-1] = '\0';
		}

		char* p = line;
		if(*p == '\0'){continue;}
		while(*p == ' ' || *p == '\t'){p++;}



		if(strcmp(p,"exit") == 0){
			return;
		}

		char* first = p;
		while(*first != '\0' && *first != ' ' && *first != '\t'){first++;}
		*first = '\0';

		printf("%s\n",p);

	}
}

int main(int argc, char** argv) {
	prompt_command_loop();
	return 0;
}
