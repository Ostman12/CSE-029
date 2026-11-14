#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

void parse_args(char* str, char* result[], int len){
	int index = 0;
	char* delim = " ";
	char* token = strtok(str,delim);
	while(token != NULL && index < len){
		result[index] = token;
		index++;
		token = strtok(NULL,delim);
	}	
	result[index] = NULL;
}

void print_array(char* arr[]) {
	int i = 0;
	while (arr[i] != NULL) {
		printf("result[%d]: '%s'\n", i, arr[i]);
		i++;
	}
	printf("result[%d]: NULL\n", i);
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
		parse_args(buffer, result, 3); // len = 3
		print_array(result);

	}
}
