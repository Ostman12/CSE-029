#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int run (char *argv[]){
	pid_t pid = fork();
	if (pid < 0){
		perror("fork");
		return -1;
	}

	if( pid == 0){
		execvp(argv[0],argv);
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}


	int status;

	waitpid(pid,&status ,0);
	if (WIFEXITED(status)){
		return WEXITSTATUS(status);
	}
	return -1;	
}

void parse_args(char *str, char *result[], int len ){
        char *delim = " \t";
        int index = 0;
        char *token = strtok(str,delim);
        while(token != NULL && index < len){
                result[index] = token;
                token = strtok(NULL,delim);
                index++;
        }
        result[index] = NULL;

}

int main(int argc, char** argv) {
    char buffer[100];

    while(1) {
        char* maybe_eof = fgets(buffer, sizeof(buffer), stdin);
        if(maybe_eof == NULL) { break; }

        // Remove newline if present
        size_t len1 = strlen(buffer);
            if (len1 > 0 && buffer[len1-1] == '\n') {
            buffer[len1-1] = '\0';
        }
	
	char* result[50];
	if(result[0] == NULL){continue;}


        parse_args(buffer, result,50); 
	printf("%d\n",run(result));	
       
    }
}
