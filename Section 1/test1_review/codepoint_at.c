#include <stdio.h>
#include <stdint.h>
#include <string.h>

int32_t codepoint_at(char str[], int32_t index){
	unsigned char cp = (unsigned char) str[index];
	if((cp&0b10000000) == 0b00000000){
		return cp;
	}else if((cp & 0b11100000) == 0b11000000){
		return (cp&0b00011111)<<6
		        |(str[index + 1] & 0b00111111);
	}else if((cp & 0b11110000) == 0b11100000){
		return (cp & 0b00001111) << 12
			|(str[index + 1] & 0b00111111) << 6
			|(str[index + 2] & 0b00111111);
	}else if((cp & 0b11111000) == 0b11110000){
		return (cp & 0b00000111) << 18
			|(str[index + 1] & 0b00111111) << 12
			|(str[index + 2] & 0b00111111) << 6
			|(str[index + 3] & 0b00111111);
	}
	return -1;

}

int main(){
	char line[100];
	int32_t index;
	while(fgets(line,sizeof(line),stdin)!= NULL){
		size_t len = strlen(line);
		if(len > 0 && line[len - 1] == '\n'){
			line[len - 1] = '\0';
		}

		char* sp;
		sp = strchr(line,' ');
		if (sp == NULL) continue;
		sscanf(sp+1, "%d",&index);
		*sp = '\0';

		printf("%d\n",codepoint_at(line,index));
	}
}
