#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "String.h"

#define nil '\0'

static char* resize(char** str, int n, int capacity) {
	int i;
	char* inst = (char*) malloc(capacity*sizeof(char));
	char* garbage = *str;

	if(capacity < n) n = capacity;

	for(i=0;i<n;++i)
		inst[i] = (*str)[i];

	*str = inst;
	free(garbage);

	return inst;
}

String* String_new(char* text) {
	String* this = (String*) malloc(sizeof(String));
	int i, m;

	m = strlen(text);

	for(i=2;i<m;i<<=1);

	this->capacity = i;
	this->rep = (char*) malloc(this->capacity*sizeof(char));

	for(i=0;i<m;++i)
		this->rep[i] = text[i];

	this->rep[i] = nil;
	this->n = m;

	return this;
}

String* String_set(String* this, char* text) {
	int m = strlen(text);
	int i;

	if(m > this->capacity)
		while(m > this->capacity)
			this->capacity <<= 1;
	else
		while((this->capacity >> 1) > m)
			this->capacity >>= 1;

	resize(&(this->rep), this->n, this->capacity);

	for(i=0;i<m;++i)
		this->rep[i] = text[i];

	this->rep[i] = nil;
	this->n = m;

	return this;
}

String* String_setString(String* this, String* that) {
	int m = that->n;
	int i;

	if(m > this->capacity)
		while(m > this->capacity)
			this->capacity <<= 1;
	else
		while((this->capacity >> 1) > m)
			this->capacity >>= 1;

	resize(&(this->rep), this->n, this->capacity);

	for(i=0;i<m;++i)
		this->rep[i] = that->rep[i];

	this->rep[i] = nil;
	this->n = m;

	return this;
}

String* String_append(String* this, char* ap) {
	int m = strlen(ap);
	int i;

	while(m + this->n > this->capacity)
		this->capacity <<= 1;

	resize(&(this->rep), this->n, this->capacity);

	for(i=0;i<m;++i)
		this->rep[i+this->n] = ap[i];

	this->rep[i+this->n] = nil;
	this->n += m;

	return this;
}

String* String_appendString(String* this, String* that) {
	int m = that->n;
	int i;

	while(m + this->n > this->capacity)
		this->capacity <<= 1;

	resize(&(this->rep), this->n, this->capacity);

	for(i=0;i<m;++i)
		this->rep[i+this->n] = that->rep[i];

	this->rep[i+this->n] = nil;
	this->n += m;

	return this;
}

char* String_get(String* this) {
	return this->rep;
}

void String_delete(String* this) {
	free(this->rep);
	free(this);
}

/*int main() {
	String* str0 = String_new("");
	String* str1 = String_new("Tomatos for the taking!");
	String* str2 = String_new("We're the potato worms! And we rule! RULE RULE RULE");

	printf("%s : %d : %d\n%s : %d : %d\n", str0->rep, str0->n, str0->capacity, str1->rep, str1->n, str1->capacity);
	printf("%s : %d : %d\n", str2->rep, str2->n, str2->capacity);
	puts("================================================");

	String_set(str0, "Out of a sudden, a voice cries out\n- Get the camel! He's the thief!");

	printf("%s : %d : %d\n%s : %d : %d\n", str0->rep, str0->n, str0->capacity, str1->rep, str1->n, str1->capacity);
	printf("%s : %d : %d\n", str2->rep, str2->n, str2->capacity);
	puts("================================================");

	String_setString(str2, str1);

	printf("%s : %d : %d\n%s : %d : %d\n", str0->rep, str0->n, str0->capacity, str1->rep, str1->n, str1->capacity);
	printf("%s : %d : %d\n", str2->rep, str2->n, str2->capacity);	
	puts("================================================");

	String_append(str1, " - said the Pickle-man. He knew the time had come. It was going all according to plan.");

	printf("%s : %d : %d\n%s : %d : %d\n", str0->rep, str0->n, str0->capacity, str1->rep, str1->n, str1->capacity);
	printf("%s : %d : %d\n", str2->rep, str2->n, str2->capacity);	
	puts("================================================");

	String_set(str2, "\n- We're the potato worms! And we rule! RULE RULE RULE! ");
	String_appendString(str0, str2);

	printf("%s : %d : %d\n%s : %d : %d\n", str0->rep, str0->n, str0->capacity, str1->rep, str1->n, str1->capacity);
	printf("%s : %d : %d\n", str2->rep, str2->n, str2->capacity);	
	puts("================================================");

	return 0;
}*/