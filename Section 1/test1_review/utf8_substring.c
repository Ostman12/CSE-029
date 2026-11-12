#include <stdio.h>
#include <stdint.h>
#include <string.h>

void utf8_substring(char str[],int  start,int end){
	int cp = -1;
	char sub[100];
	int len = 0;

	for (int i = 0; str[i] != '\0'; i++){
		if((str[i] & 0b11000000) != 0b10000000){
		       cp++;
	       	}
 		if(cp >= end){
			break;
		}	
		if(cp >= start){
			sub[len] = str[i];
			len++;
		}
	}
	sub[len] = '\0';
	printf("%s\n",sub);
}

int main(){
	char line[200];
	int end,start;
	while(fgets(line,sizeof(line),stdin)!=NULL){
		size_t len = strlen(line);
		if(len > 0 && line[len -1] == '\n'){
			line[len -1] = '\0';
		}

		char* sp;

		sp = strrchr(line, ' ');
		if(sp == NULL) continue;
		sscanf(sp+1,"%d",&end);
		*sp = '\0';

		sp = strrchr(line, ' ');
		if(sp == NULL)continue;
		sscanf(sp+1,"%d",&start);
		*sp = '\0';

		utf8_substring(line,start,end);
	}
	return 0;
}	
