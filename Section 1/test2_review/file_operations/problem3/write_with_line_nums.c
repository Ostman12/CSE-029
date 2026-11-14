#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


void write_with_line_numbers(char* path, char* to_save){
	FILE* f = fopen(path,"w");
	if(f == NULL){
		return;
	}
	int line_num = 1;
	int i = 0;
	fprintf(f,"%d ",line_num);
	while(to_save[i] != '\0'){
		fputc(to_save[i],f);
		if(to_save[i] == '\n' && to_save[i+1] != '\0'){
			line_num++;
			fprintf(f,"%d ",line_num);
		}
		i++;


	}
	fclose(f);
}

void convert_escaped_newlines(char* src, char* dest) {
	while (*src) {
		if (src[0] == '\\' && src[1] == 'n') {
			*dest++ = '\n';
			src += 2;
		} else {
			*dest++ = *src++;
		}
	}
	*dest = '\0';
}

int main(int argc, char** argv) {
	char buffer[1000];
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
		char* raw_str = space + 1; // what to write into the file

		char processed_str[1000];
		convert_escaped_newlines(raw_str, processed_str); // make the newline char into an actual newline char

		write_with_line_numbers(path, processed_str);
	}
}
