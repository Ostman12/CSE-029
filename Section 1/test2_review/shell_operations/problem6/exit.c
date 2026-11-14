#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>


int run_exit(int argc){
	if(argc == 1){
		exit(EXIT_SUCCESS);
	}else{
		fprintf(stderr,"usage: exit\n");
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
		int argc = 0;
		char *token = strtok(copy, " \t");
		while (token != NULL)
		{
			argc++;
			token = strtok(NULL, " \t");
		}
		int result = run_exit(argc);
		if (result == -1) continue;
	}
	return 0;
}
