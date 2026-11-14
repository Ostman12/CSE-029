#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int run_cd(int argc, char *path){
	if(argc == 2){
		if(chdir(path) == -1){
			perror("cd");
			return -1;
		}else{
			return 0;
		}
	}else{
		fprintf(stderr,"usage: cd <path>\n");
		return -1;
	}
}

int main()
{
	char buffer[1001];
	while (fgets(buffer, sizeof(buffer), stdin) != NULL)
	{
		size_t len = strlen(buffer);
		if (len > 0 && buffer[len - 1] == '\n') buffer[len - 1] = '\0';
		char copy[1001];
		strcpy(copy, buffer);
		char *argv[64];
		int argc = 0;
		char *token = strtok(copy, " \t");
		while (token != NULL && argc < 64)
		{
			argv[argc++] = token;
			token = strtok(NULL, " \t");
		}
		char *path = (argc >= 2) ? argv[1] : NULL;
		int result = run_cd(argc, path);
		if (result == 0) printf("success\n");
	}
	return 0;
}
