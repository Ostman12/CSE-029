#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint8_t find_in_file(char* path, char* to_find){
	FILE* f = fopen(path,"r");
	if(f == NULL){
		return 0;
	}

	char line[2048];
	uint8_t found = 0;
	while(fgets(line,sizeof(line),f) != NULL){
		if(strstr(line,to_find) != NULL){
			found = 1;
			break;
		}
	}

	if(ferror(f)){
		found = 0;
	}

	fclose(f);
	return found;
}

int main(int argc, char** argv) {
    char buffer[100];
    while(1) {
        char* maybe_eof = fgets(buffer, sizeof(buffer), stdin);
        if(maybe_eof == NULL) { break; }

        // Remove newline if present
        size_t len = strlen(buffer);
            if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        }

        char* space = strchr(buffer, ' ');
        *space = '\0';
        char* path = buffer;
        char* to_find = space + 1;

        printf("%d\n", find_in_file(path, to_find));
    }
}
