#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tokenize_args(char *str, const char *delim_str){
	int index = 0;
	char* token = strtok(str,delim_str);
	while(token != NULL){
		printf("%d: %s\n",index++,token);
		token = strtok(NULL,delim_str);
	}
}

int main(int argc, char **argv)
{
	// Build delimiter string from command-line arguments
	char delimiters[1001] = "";

	for (int i = 1; i < argc; i++)
	{
		strcat(delimiters, argv[i]);
	}

	// Read from stdin and tokenize each line
	char buffer[1001];
	while (fgets(buffer, sizeof(buffer), stdin) != NULL)
	{
		// Remove trailing newline
		size_t len = strlen(buffer);
		if (len > 0 && buffer[len - 1] == '\n')
		{
			buffer[len - 1] = '\0';
		}

		tokenize_args(buffer, delimiters);
	}

	return 0;
}
