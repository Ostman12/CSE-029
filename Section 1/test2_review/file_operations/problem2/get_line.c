#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int32_t get_line(char* path, int line_number, char result[], int max){
	if (line_number < 1){
		return -1;
	}
	FILE* f = fopen(path,"r");

	if(f == NULL){
		return -1;
	}

	int lines = 0;
	int c;
	while(lines < line_number-1 && (c = fgetc(f) != EOF)){
		if(c == '\n'){
			lines++;
		}
	}

	if(lines < line_number-1 || fgets(result,max+1,f) == NULL){
		fclose(f);
		return -1;
	}

	fclose(f);
	return strlen(result);


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

		char* space1 = strchr(buffer, ' ');
		*space1 = '\0';
		char* path = buffer; // getting file path

		char* rest = space1 + 1;
		char* space2 = strchr(rest, ' ');
		*space2 = '\0';
		char* num1_str = rest; // getting len
		char* num2_str = space2 + 1; // getting max

		int num1 = atoi(num1_str); // convert len to number
		int num2 = atoi(num2_str); // convert max to number

		char result[num2 + 1];

		int32_t ret_num = get_line(path, num1, result, num2);
		if(ret_num == -1){printf("-1\n");}
		else{
			if (ret_num > 0 && result[ret_num - 1] == '\n') {
				result[ret_num - 1] = '\0';
			}
			printf("%d %s\n", ret_num, result);}
	}
}

