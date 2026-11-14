#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>




char* split_space(char* s){
	for(int i =0; s[i] !='\0'; i++){
		if(s[i] == ' '){
			s[i] = '\0';
			return &s[i + 1];
		}

	}
	return s;
}


char* extract_second(char* s){
	char* split = split_space(s);
	if(split == s || *split == '\0'){
	       return "No second string";
	}	       
	char* split2 = split_space(split);
	return split;
}


int main (int argc, char** argv){
	char line[100];
	while(fgets(line,sizeof(line),stdin) != NULL){

		size_t len = strlen(line);
		if(len > 0 && line[len-1] == '\n'){
			line[len-1] = '\0';
		}

		char* second = extract_second(line);
		printf("%s\n",second);
	}
	return 0;
}
