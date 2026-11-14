#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int test_fopen(const char *filepath){
	FILE* f = fopen(filepath,"r");

	if(f == NULL){
		perror("open");
		return -1;
	}
	fclose(f);
	return 0;
}

int test_chdir(const char *path){
	if(chdir(path) == -1){
		perror("cd");
		return -1;
	}
	return 0;
}

int main()
{
    char buffer[1001];
    while (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
            buffer[len - 1] = '\0';
        char *space = strchr(buffer, ' ');
        if (space == NULL) continue;
        *space = '\0';
        char *command = buffer;
        char *arg = space + 1;
        int result;
        if (strcmp(command, "open") == 0)
            result = test_fopen(arg);
        else if (strcmp(command, "cd") == 0)
            result = test_chdir(arg);
        else continue;
        if (result == 0) printf("success\n");
    }
    return 0;
}
