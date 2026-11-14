#include <stdio.h>
#include<stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


int fork_and_wait(const char* command, const char* arg) {
	pid_t pid = fork();
	if(pid < 0){
		return -1;
	}
	if(pid == 0){
		if(arg == NULL){
			execlp(command,command,NULL);
		}else{
			execlp(command,command,arg,NULL);
		}
		exit(1);
	}

	waitpid(pid,NULL,0);
	return 0;
}

int main() {
	char buffer[1001];
	while(fgets(buffer, sizeof(buffer), stdin) != NULL) {
		size_t len = strlen(buffer);
		if (len > 0 && buffer[len-1] == '\n') buffer[len-1] = '\0';
		char* argv[64];
		int argc = 0;
		char *token = strtok(buffer, " \t");
		while (token != NULL && argc < 64) {
			argv[argc++] = token;
			token = strtok(NULL, " \t");
		}
		if (argc > 0) {
			const char* command = argv[0];
			const char* arg = (argc > 1) ? argv[1] : NULL;
			int result = fork_and_wait(command, arg);
			if (result == 0) printf("Parent: child completed\n");
		}
	}
	return 0;
}


