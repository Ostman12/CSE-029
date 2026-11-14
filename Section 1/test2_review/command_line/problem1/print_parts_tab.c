#include <stdio.h>
#include <string.h>

void print_parts_tabs(const char *str){
	int index = 0;
	char cpy[1024];
	strcpy(cpy,str);
	char* delim = "\t";
	char* token = strtok(cpy,delim);
	while(token != NULL){
		printf("%d: %s\n",index++,token);
		token = strtok(NULL,delim);
	}
}

int main()
{
	char buffer[1001];

	while (fgets(buffer, sizeof(buffer), stdin) != NULL)
	{
		// Remove trailing newline if present
		size_t len = strlen(buffer);
		if (len > 0 && buffer[len - 1] == '\n')
		{
			buffer[len - 1] = '\0';
		}

		print_parts_tabs(buffer);
	}

	return 0;
}
