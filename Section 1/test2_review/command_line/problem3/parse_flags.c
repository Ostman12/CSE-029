#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
	char* delim = " ";
	char* sep = "\n";
	for(int i = 0; i < argc;i++){
		if(strcmp(argv[i],"-d") == 0 && i+1 < argc){
			delim = argv[i+1];
			i++;
		}
		if(strcmp(argv[i],"-s") == 0 && i+1 < argc){
			sep = argv[i+1];
			i++;
		}
	}

	char line[1024];
	while(fgets(line,sizeof(line),stdin) != NULL){
		size_t len = strlen(line);
		if(len > 0 && line[len-1] == '\n'){
			line[len-1] = '\0';
		}
		char* token = strtok(line,delim);
		bool first = true;
		while(token != NULL){
			if(!first){printf("%s",sep);}
			printf("%s",token);
			first = false;
			token = strtok(NULL,delim);
		}
		printf("\n");
	}
	return 0;
}
