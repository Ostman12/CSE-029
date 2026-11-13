#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>



struct course {
	int id; 
	char* name;
};

struct course* course_new(int id, const char* name){
	struct course *c = malloc(sizeof(*c));
	c->id = id;
	c->name = malloc(strlen(name) + 1);
	strcpy(c->name,name);
	return c;
}

void course_free(struct course* c){
	free(c->name);
	free(c);
}

int main(){
	struct course* CSE29 = course_new(67,"cse29");
	printf("ID: %d\nName: %s\n",CSE29->id,CSE29->name);
	course_free(CSE29);
	return 0;
}
