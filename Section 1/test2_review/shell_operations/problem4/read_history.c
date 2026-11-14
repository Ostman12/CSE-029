#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int read_history(const char *filepath){
	FILE* f = fopen(filepath,"r");
	if(f == NULL){
		perror("open");
		return -1;
	}

	int index = 1;
	char command[1024];
	while(fgets(command,sizeof(command),f) != NULL){
		printf("%d %s",index++,command);
	}
	fclose(f);
	return 0;
}

int main()
{
	char buffer[1001];
	while (fgets(buffer, sizeof(buffer), stdin) != NULL)
	{
		size_t len = strlen(buffer);
		if (len > 0 && buffer[len - 1] == '\n') buffer[len - 1] = '\0';
		read_history(buffer);
	}
	return 0;
}
